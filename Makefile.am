SUBDIRS = Atlas tutorial benchmark

bin_SCRIPTS = atlas-config

EXTRA_DIST = ROADMAP HACKING Doxyfile footer.html index.dox Atlas.mak Atlas.dsp atlas.m4 autogen.sh Atlas.pbproj/jmt.pbxuser Atlas.pbproj/project.pbxproj

m4datadir = $(datadir)/aclocal
m4data_DATA = atlas.m4

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = atlascpp-0.4.pc

docdir = $(datadir)/doc/Atlas-C++-$(VERSION)
doc_DATA = README COPYING AUTHORS THANKS NEWS ChangeLog TODO HACKING ROADMAP

docs:
	@echo "running doxygen..."
	@doxygen Doxyfile
	@echo "documentation is in doc/."
