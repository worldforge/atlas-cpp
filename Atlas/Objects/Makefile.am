SUBDIRS = . Entity Operation

lib_LTLIBRARIES = libAtlasObjects.la

libAtlasObjects_la_LDFLAGS = $(INTERFACE_VERSION)

libAtlasObjectsincludedir = $(includedir)/Atlas/Objects

libAtlasObjects_la_SOURCES = \
	Root.cc Decoder.cc

libAtlasObjectsinclude_HEADERS = \
	Root.h Decoder.h Encoder.h

EXTRA_DIST = gen_cc.py README DESIGN
