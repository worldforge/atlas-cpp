SUBDIRS = src tutorial benchmark

bin_SCRIPTS = atlas-config

EXTRA_DIST = ROADMAP Doxyfile footer.html index.dox Atlas.mak Atlas.dsp

m4datadir = $(datadir)/aclocal
m4data_DATA = atlas.m4

docs:
	@echo "running doxygen..."
	@doxygen Doxyfile
	@echo "documentation is in doc/."
