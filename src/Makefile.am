AM_CPPFLAGS = @VMOD_INCLUDES@ -Wall -Werror

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_sleep.la

libvmod_sleep_la_LDFLAGS = -module -export-dynamic -avoid-version -shared

libvmod_sleep_la_SOURCES = \
	vmod_sleep.c

nodist_libvmod_sleep_la_SOURCES = \
	vcc_if.c \
	vcc_if.h

vmod_sleep.lo: vcc_if.c vcc_if.h

vcc_if.c: vcc_if.h

vcc_if.h: @VMODTOOL@ $(top_srcdir)/src/vmod_sleep.vcc
	@VMODTOOL@ $(top_srcdir)/src/vmod_sleep.vcc

VMOD_TESTS = $(top_srcdir)/src/tests/*.vtc
.PHONY: $(VMOD_TESTS)

$(top_srcdir)/src/tests/*.vtc: libvmod_sleep.la
	@VARNISHTEST@ -Dvarnishd=@VARNISHD@ -Dvmod_topbuild=$(abs_top_builddir) $@

check: $(VMOD_TESTS)

EXTRA_DIST = \
	vmod_sleep.vcc \
	$(VMOD_TESTS)

CLEANFILES = \
	$(builddir)/vcc_if.c \
	$(builddir)/vcc_if.h \
	$(builddir)/vmod_sleep.rst \
	$(builddir)/vmod_sleep.man.rst
