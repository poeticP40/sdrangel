#--------------------------------------------------------
#
# Pro file for Android and Windows builds with Qt Creator
#
#--------------------------------------------------------

TEMPLATE = subdirs
SUBDIRS = sdrbase
SUBDIRS += lz4
SUBDIRS += plugins/samplesource/filesource
SUBDIRS += plugins/samplesource/sdrdaemon
SUBDIRS += plugins/channel/demodam
SUBDIRS += plugins/channel/chanalyzer
SUBDIRS += plugins/channel/demodbfm

# Main app must be last
CONFIG += ordered
SUBDIRS += app
