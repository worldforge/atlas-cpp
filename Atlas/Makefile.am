SUBDIRS = . Objects Message Codecs Net Funky

lib_LTLIBRARIES = libAtlas.la

libAtlas_la_LDFLAGS = -version-info @ATLAS_INTERFACE_VERSION_INFO@

libAtlasincludedir = $(includedir)/Atlas-C++-0.4/Atlas

libAtlas_la_SOURCES = \
	Bridge.cc Codec.cc

libAtlasinclude_HEADERS = \
	Bridge.h Codec.h Negotiate.h EncoderBase.h \
	Task.h Codec_impl.h
