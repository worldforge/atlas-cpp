
INCLUDES = -I$(top_srcdir)

lib_LTLIBRARIES = libAtlasMessage.la

libAtlasMessage_la_LDFLAGS = -version-info @ATLAS_INTERFACE_VERSION_INFO@

libAtlasMessageincludedir = $(includedir)/Atlas-C++-0.4/Atlas/Message

libAtlasMessage_la_SOURCES = \
	Object.cc Encoder.cc DecoderBase.cc QueuedDecoder.cc

libAtlasMessageinclude_HEADERS = \
	Object.h Layer.h Encoder.h DecoderBase.h QueuedDecoder.h
