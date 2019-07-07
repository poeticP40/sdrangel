/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.11.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGXtrxInputSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGXtrxInputSettings::SWGXtrxInputSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGXtrxInputSettings::SWGXtrxInputSettings() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    log2_hard_decim = 0;
    m_log2_hard_decim_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    log2_soft_decim = 0;
    m_log2_soft_decim_isSet = false;
    lpf_bw = 0;
    m_lpf_bw_isSet = false;
    gain = 0;
    m_gain_isSet = false;
    nco_enable = 0;
    m_nco_enable_isSet = false;
    nco_frequency = 0;
    m_nco_frequency_isSet = false;
    antenna_path = 0;
    m_antenna_path_isSet = false;
    gain_mode = 0;
    m_gain_mode_isSet = false;
    lna_gain = 0;
    m_lna_gain_isSet = false;
    tia_gain = 0;
    m_tia_gain_isSet = false;
    pga_gain = 0;
    m_pga_gain_isSet = false;
    ext_clock = 0;
    m_ext_clock_isSet = false;
    ext_clock_freq = 0;
    m_ext_clock_freq_isSet = false;
    pwrmode = 0;
    m_pwrmode_isSet = false;
    file_record_name = nullptr;
    m_file_record_name_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGXtrxInputSettings::~SWGXtrxInputSettings() {
    this->cleanup();
}

void
SWGXtrxInputSettings::init() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    log2_hard_decim = 0;
    m_log2_hard_decim_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    log2_soft_decim = 0;
    m_log2_soft_decim_isSet = false;
    lpf_bw = 0;
    m_lpf_bw_isSet = false;
    gain = 0;
    m_gain_isSet = false;
    nco_enable = 0;
    m_nco_enable_isSet = false;
    nco_frequency = 0;
    m_nco_frequency_isSet = false;
    antenna_path = 0;
    m_antenna_path_isSet = false;
    gain_mode = 0;
    m_gain_mode_isSet = false;
    lna_gain = 0;
    m_lna_gain_isSet = false;
    tia_gain = 0;
    m_tia_gain_isSet = false;
    pga_gain = 0;
    m_pga_gain_isSet = false;
    ext_clock = 0;
    m_ext_clock_isSet = false;
    ext_clock_freq = 0;
    m_ext_clock_freq_isSet = false;
    pwrmode = 0;
    m_pwrmode_isSet = false;
    file_record_name = new QString("");
    m_file_record_name_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

void
SWGXtrxInputSettings::cleanup() {


















    if(file_record_name != nullptr) { 
        delete file_record_name;
    }

    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGXtrxInputSettings*
SWGXtrxInputSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGXtrxInputSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&dev_sample_rate, pJson["devSampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&log2_hard_decim, pJson["log2HardDecim"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGSDRangel::setValue(&iq_correction, pJson["iqCorrection"], "qint32", "");
    
    ::SWGSDRangel::setValue(&log2_soft_decim, pJson["log2SoftDecim"], "qint32", "");
    
    ::SWGSDRangel::setValue(&lpf_bw, pJson["lpfBW"], "qint32", "");
    
    ::SWGSDRangel::setValue(&gain, pJson["gain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&nco_enable, pJson["ncoEnable"], "qint32", "");
    
    ::SWGSDRangel::setValue(&nco_frequency, pJson["ncoFrequency"], "qint32", "");
    
    ::SWGSDRangel::setValue(&antenna_path, pJson["antennaPath"], "qint32", "");
    
    ::SWGSDRangel::setValue(&gain_mode, pJson["gainMode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&lna_gain, pJson["lnaGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tia_gain, pJson["tiaGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&pga_gain, pJson["pgaGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&ext_clock, pJson["extClock"], "qint32", "");
    
    ::SWGSDRangel::setValue(&ext_clock_freq, pJson["extClockFreq"], "qint32", "");
    
    ::SWGSDRangel::setValue(&pwrmode, pJson["pwrmode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&file_record_name, pJson["fileRecordName"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGXtrxInputSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGXtrxInputSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_dev_sample_rate_isSet){
        obj->insert("devSampleRate", QJsonValue(dev_sample_rate));
    }
    if(m_log2_hard_decim_isSet){
        obj->insert("log2HardDecim", QJsonValue(log2_hard_decim));
    }
    if(m_dc_block_isSet){
        obj->insert("dcBlock", QJsonValue(dc_block));
    }
    if(m_iq_correction_isSet){
        obj->insert("iqCorrection", QJsonValue(iq_correction));
    }
    if(m_log2_soft_decim_isSet){
        obj->insert("log2SoftDecim", QJsonValue(log2_soft_decim));
    }
    if(m_lpf_bw_isSet){
        obj->insert("lpfBW", QJsonValue(lpf_bw));
    }
    if(m_gain_isSet){
        obj->insert("gain", QJsonValue(gain));
    }
    if(m_nco_enable_isSet){
        obj->insert("ncoEnable", QJsonValue(nco_enable));
    }
    if(m_nco_frequency_isSet){
        obj->insert("ncoFrequency", QJsonValue(nco_frequency));
    }
    if(m_antenna_path_isSet){
        obj->insert("antennaPath", QJsonValue(antenna_path));
    }
    if(m_gain_mode_isSet){
        obj->insert("gainMode", QJsonValue(gain_mode));
    }
    if(m_lna_gain_isSet){
        obj->insert("lnaGain", QJsonValue(lna_gain));
    }
    if(m_tia_gain_isSet){
        obj->insert("tiaGain", QJsonValue(tia_gain));
    }
    if(m_pga_gain_isSet){
        obj->insert("pgaGain", QJsonValue(pga_gain));
    }
    if(m_ext_clock_isSet){
        obj->insert("extClock", QJsonValue(ext_clock));
    }
    if(m_ext_clock_freq_isSet){
        obj->insert("extClockFreq", QJsonValue(ext_clock_freq));
    }
    if(m_pwrmode_isSet){
        obj->insert("pwrmode", QJsonValue(pwrmode));
    }
    if(file_record_name != nullptr && *file_record_name != QString("")){
        toJsonValue(QString("fileRecordName"), file_record_name, obj, QString("QString"));
    }
    if(m_use_reverse_api_isSet){
        obj->insert("useReverseAPI", QJsonValue(use_reverse_api));
    }
    if(reverse_api_address != nullptr && *reverse_api_address != QString("")){
        toJsonValue(QString("reverseAPIAddress"), reverse_api_address, obj, QString("QString"));
    }
    if(m_reverse_api_port_isSet){
        obj->insert("reverseAPIPort", QJsonValue(reverse_api_port));
    }
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }

    return obj;
}

qint64
SWGXtrxInputSettings::getCenterFrequency() {
    return center_frequency;
}
void
SWGXtrxInputSettings::setCenterFrequency(qint64 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGXtrxInputSettings::getDevSampleRate() {
    return dev_sample_rate;
}
void
SWGXtrxInputSettings::setDevSampleRate(qint32 dev_sample_rate) {
    this->dev_sample_rate = dev_sample_rate;
    this->m_dev_sample_rate_isSet = true;
}

qint32
SWGXtrxInputSettings::getLog2HardDecim() {
    return log2_hard_decim;
}
void
SWGXtrxInputSettings::setLog2HardDecim(qint32 log2_hard_decim) {
    this->log2_hard_decim = log2_hard_decim;
    this->m_log2_hard_decim_isSet = true;
}

qint32
SWGXtrxInputSettings::getDcBlock() {
    return dc_block;
}
void
SWGXtrxInputSettings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint32
SWGXtrxInputSettings::getIqCorrection() {
    return iq_correction;
}
void
SWGXtrxInputSettings::setIqCorrection(qint32 iq_correction) {
    this->iq_correction = iq_correction;
    this->m_iq_correction_isSet = true;
}

qint32
SWGXtrxInputSettings::getLog2SoftDecim() {
    return log2_soft_decim;
}
void
SWGXtrxInputSettings::setLog2SoftDecim(qint32 log2_soft_decim) {
    this->log2_soft_decim = log2_soft_decim;
    this->m_log2_soft_decim_isSet = true;
}

qint32
SWGXtrxInputSettings::getLpfBw() {
    return lpf_bw;
}
void
SWGXtrxInputSettings::setLpfBw(qint32 lpf_bw) {
    this->lpf_bw = lpf_bw;
    this->m_lpf_bw_isSet = true;
}

qint32
SWGXtrxInputSettings::getGain() {
    return gain;
}
void
SWGXtrxInputSettings::setGain(qint32 gain) {
    this->gain = gain;
    this->m_gain_isSet = true;
}

qint32
SWGXtrxInputSettings::getNcoEnable() {
    return nco_enable;
}
void
SWGXtrxInputSettings::setNcoEnable(qint32 nco_enable) {
    this->nco_enable = nco_enable;
    this->m_nco_enable_isSet = true;
}

qint32
SWGXtrxInputSettings::getNcoFrequency() {
    return nco_frequency;
}
void
SWGXtrxInputSettings::setNcoFrequency(qint32 nco_frequency) {
    this->nco_frequency = nco_frequency;
    this->m_nco_frequency_isSet = true;
}

qint32
SWGXtrxInputSettings::getAntennaPath() {
    return antenna_path;
}
void
SWGXtrxInputSettings::setAntennaPath(qint32 antenna_path) {
    this->antenna_path = antenna_path;
    this->m_antenna_path_isSet = true;
}

qint32
SWGXtrxInputSettings::getGainMode() {
    return gain_mode;
}
void
SWGXtrxInputSettings::setGainMode(qint32 gain_mode) {
    this->gain_mode = gain_mode;
    this->m_gain_mode_isSet = true;
}

qint32
SWGXtrxInputSettings::getLnaGain() {
    return lna_gain;
}
void
SWGXtrxInputSettings::setLnaGain(qint32 lna_gain) {
    this->lna_gain = lna_gain;
    this->m_lna_gain_isSet = true;
}

qint32
SWGXtrxInputSettings::getTiaGain() {
    return tia_gain;
}
void
SWGXtrxInputSettings::setTiaGain(qint32 tia_gain) {
    this->tia_gain = tia_gain;
    this->m_tia_gain_isSet = true;
}

qint32
SWGXtrxInputSettings::getPgaGain() {
    return pga_gain;
}
void
SWGXtrxInputSettings::setPgaGain(qint32 pga_gain) {
    this->pga_gain = pga_gain;
    this->m_pga_gain_isSet = true;
}

qint32
SWGXtrxInputSettings::getExtClock() {
    return ext_clock;
}
void
SWGXtrxInputSettings::setExtClock(qint32 ext_clock) {
    this->ext_clock = ext_clock;
    this->m_ext_clock_isSet = true;
}

qint32
SWGXtrxInputSettings::getExtClockFreq() {
    return ext_clock_freq;
}
void
SWGXtrxInputSettings::setExtClockFreq(qint32 ext_clock_freq) {
    this->ext_clock_freq = ext_clock_freq;
    this->m_ext_clock_freq_isSet = true;
}

qint32
SWGXtrxInputSettings::getPwrmode() {
    return pwrmode;
}
void
SWGXtrxInputSettings::setPwrmode(qint32 pwrmode) {
    this->pwrmode = pwrmode;
    this->m_pwrmode_isSet = true;
}

QString*
SWGXtrxInputSettings::getFileRecordName() {
    return file_record_name;
}
void
SWGXtrxInputSettings::setFileRecordName(QString* file_record_name) {
    this->file_record_name = file_record_name;
    this->m_file_record_name_isSet = true;
}

qint32
SWGXtrxInputSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGXtrxInputSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGXtrxInputSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGXtrxInputSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGXtrxInputSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGXtrxInputSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGXtrxInputSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGXtrxInputSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGXtrxInputSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_center_frequency_isSet){ isObjectUpdated = true; break;}
        if(m_dev_sample_rate_isSet){ isObjectUpdated = true; break;}
        if(m_log2_hard_decim_isSet){ isObjectUpdated = true; break;}
        if(m_dc_block_isSet){ isObjectUpdated = true; break;}
        if(m_iq_correction_isSet){ isObjectUpdated = true; break;}
        if(m_log2_soft_decim_isSet){ isObjectUpdated = true; break;}
        if(m_lpf_bw_isSet){ isObjectUpdated = true; break;}
        if(m_gain_isSet){ isObjectUpdated = true; break;}
        if(m_nco_enable_isSet){ isObjectUpdated = true; break;}
        if(m_nco_frequency_isSet){ isObjectUpdated = true; break;}
        if(m_antenna_path_isSet){ isObjectUpdated = true; break;}
        if(m_gain_mode_isSet){ isObjectUpdated = true; break;}
        if(m_lna_gain_isSet){ isObjectUpdated = true; break;}
        if(m_tia_gain_isSet){ isObjectUpdated = true; break;}
        if(m_pga_gain_isSet){ isObjectUpdated = true; break;}
        if(m_ext_clock_isSet){ isObjectUpdated = true; break;}
        if(m_ext_clock_freq_isSet){ isObjectUpdated = true; break;}
        if(m_pwrmode_isSet){ isObjectUpdated = true; break;}
        if(file_record_name != nullptr && *file_record_name != QString("")){ isObjectUpdated = true; break;}
        if(m_use_reverse_api_isSet){ isObjectUpdated = true; break;}
        if(reverse_api_address != nullptr && *reverse_api_address != QString("")){ isObjectUpdated = true; break;}
        if(m_reverse_api_port_isSet){ isObjectUpdated = true; break;}
        if(m_reverse_api_device_index_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

