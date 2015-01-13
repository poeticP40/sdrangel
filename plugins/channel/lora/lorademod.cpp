///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012 maintech GmbH, Otto-Hahn-Str. 15, 97204 Hoechberg, Germany //
// written by Christian Daniel                                                   //
// (c) 2015 John Greb
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <QTime>
#include <stdio.h>
#include "lorademod.h"
#include "dsp/dspcommands.h"

MESSAGE_CLASS_DEFINITION(LoRaDemod::MsgConfigureLoRaDemod, Message)

LoRaDemod::LoRaDemod(SampleSink* sampleSink) :
	m_sampleSink(sampleSink)
{
	m_Bandwidth = 7813;
	m_sampleRate = 96000;
	m_frequency = 0;
	m_nco.setFreq(m_frequency, m_sampleRate);
	m_interpolator.create(16, m_sampleRate, m_Bandwidth/1.9);
	m_sampleDistanceRemain = (Real)m_sampleRate / m_Bandwidth;

	m_chirp = 0;
	m_angle = 0;
	m_bin = 0;
	m_result = 0;
	m_count = 0;

	loraFilter = new sfft(LORA_SFFT_LEN);
}

LoRaDemod::~LoRaDemod()
{
	if (loraFilter)
		delete loraFilter;
}

void LoRaDemod::configure(MessageQueue* messageQueue, Real Bandwidth)
{
	Message* cmd = MsgConfigureLoRaDemod::create(Bandwidth);
	cmd->submit(messageQueue, this);
}

// Detecting the header needs an sfft with the opposite rotation
int  LoRaDemod::detect(Complex c)
{
	int i;
	float peak;
	float mag[LORA_SFFT_LEN];

	loraFilter->run(c);
	if (++m_count & 31)
		return m_result;

	// process spectrum every 32 samples
	loraFilter->fetch(mag);
	peak = 0.0f;
	m_result = 0;
	for (i = 0; i < LORA_SFFT_LEN; i++) {
		if (mag[i] > peak) {
			peak = mag[i];
			m_result = i;
		}
	}
	return m_result;
}

void LoRaDemod::feed(SampleVector::const_iterator begin, SampleVector::const_iterator end, bool pO)
{
	int newangle;
	Complex ci;

	m_sampleBuffer.clear();
	for(SampleVector::const_iterator it = begin; it < end; ++it) {
		Complex c(it->real() / 32768.0, it->imag() / 32768.0);
		c *= m_nco.nextIQ();

		if(m_interpolator.interpolate(&m_sampleDistanceRemain, c, &ci)) {
			m_chirp = (m_chirp + 1) & (SPREADFACTOR - 1);
                        m_angle = (m_angle + m_chirp) & (SPREADFACTOR - 1);
			Complex cangle(cos(M_PI*2*m_angle/SPREADFACTOR),-sin(M_PI*2*m_angle/SPREADFACTOR));
			newangle = detect(ci * cangle);

			m_bin = (m_bin + newangle) & (LORA_SFFT_LEN - 1);
			Complex nangle(cos(M_PI*2*m_bin/LORA_SFFT_LEN),sin(M_PI*2*m_bin/LORA_SFFT_LEN));
			m_sampleBuffer.push_back(Sample(nangle.real() * 500, nangle.imag() * 500));
			m_sampleDistanceRemain += (Real)m_sampleRate / m_Bandwidth;
		}
	}
	if(m_sampleSink != NULL)
		m_sampleSink->feed(m_sampleBuffer.begin(), m_sampleBuffer.end(), true);
}

void LoRaDemod::start()
{
}

void LoRaDemod::stop()
{
}

bool LoRaDemod::handleMessage(Message* cmd)
{
	if(DSPSignalNotification::match(cmd)) {
		DSPSignalNotification* signal = (DSPSignalNotification*)cmd;
		m_sampleRate = signal->getSampleRate();
		m_nco.setFreq(-signal->getFrequencyOffset(), m_sampleRate);
		m_interpolator.create(16, m_sampleRate, m_Bandwidth/1.9);
		m_sampleDistanceRemain = m_sampleRate / m_Bandwidth;
		cmd->completed();
		return true;
	} else if(MsgConfigureLoRaDemod::match(cmd)) {
		MsgConfigureLoRaDemod* cfg = (MsgConfigureLoRaDemod*)cmd;
		m_Bandwidth = cfg->getBandwidth();
		m_interpolator.create(16, m_sampleRate, m_Bandwidth/1.9);
		cmd->completed();
		return true;
	} else {
		if(m_sampleSink != NULL)
			 return m_sampleSink->handleMessage(cmd);
		else
			return false;
	}
}
