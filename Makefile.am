SUBDIRS = src tutorial benchmark

bin_SCRIPTS = atlas-config

EXTRA_DIST = ROADMAP Doxyfile footer.html index.dox Atlas.mak Atlas.dsp atlas.m4 autogen.sh

m4datadir = $(datadir)/aclocal
m4data_DATA = atlas.m4

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = atlascpp-0.4.pc

install-data-local:
	mkdir -p $(DESTDIR)$(datadir)/doc/Atlas-C++-$(VERSION)
	$(INSTALL_DATA) README $(DESTDIR)$(datadir)/doc/Atlas-C++-$(VERSION)
	$(INSTALL_DATA) COPYING $(DESTDIR)$(datadir)/doc/Atlas-C++-$(VERSION)
	$(INSTALL_DATA) AUTHORS $(DESTDIR)$(datadir)/doc/Atlas-C++-$(VERSION)
	$(INSTALL_DATA) THANKS $(DESTDIR)$(datadir)/doc/Atlas-C++-$(VERSION)
	$(INSTALL_DATA) NEWS $(DESTDIR)$(datadir)/doc/Atlas-C++-$(VERSION)

docs:
	@echo "running doxygen..."
	@doxygen Doxyfile
	@echo "documentation is in doc/."
