SUBDIRS = .

INCLUDES = -I$(top_srcdir)

lib_LTLIBRARIES = libAtlasObjectsEntity.la

libAtlasObjectsEntity_la_LDFLAGS = -version-info @ATLAS_INTERFACE_VERSION_INFO@

libAtlasObjectsEntityincludedir = $(includedir)/Atlas-C++-0.4/Atlas/Objects/Entity

libAtlasObjectsEntity_la_SOURCES = \
	Entity.cc

libAtlasObjectsEntityinclude_HEADERS = \
	Account.h Admin.h AdminEntity.h Game.h \
	GameEntity.h Player.h RootEntity.h
