
INCLUDES = -I$(top_srcdir)

lib_LTLIBRARIES = libAtlasNet.la

libAtlasNet_la_LDFLAGS = -version-info @ATLAS_INTERFACE_VERSION_INFO@

libAtlasNetincludedir = $(includedir)/Atlas-C++-0.4/Atlas/Net

libAtlasNet_la_SOURCES = \
	Stream.cc Loopback.cc

libAtlasNetinclude_HEADERS = \
	Stream.h Loopback.h
