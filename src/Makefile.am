AM_CFLAGS = $(VARNISHAPI_CFLAGS) -Wall -Werror
AM_LDFLAGS = $(VARNISHAPI_LIBS) $(VMOD_LDFLAGS)

vmod_LTLIBRARIES = libvmod_sleep.la

libvmod_sleep_la_SOURCES = \
	vmod_sleep.c

nodist_libvmod_sleep_la_SOURCES = \
	vcc_sleep_if.c \
	vcc_sleep_if.h

dist_man_MANS = vmod_sleep.3

@BUILD_VMOD_SLEEP@

AM_TESTS_ENVIRONMENT = \
	PATH="$(VMOD_TEST_PATH)" \
	LD_LIBRARY_PATH="$(VARNISH_LIBRARY_PATH)"
TEST_EXTENSIONS = .vtc
VTC_LOG_COMPILER = varnishtest -v
AM_VTC_LOG_FLAGS = -Dvmod_sleep="$(VMOD_SLEEP)"

TESTS = @VMOD_TESTS@

EXTRA_DIST = \
	vmod_sleep.vcc \
	$(VMOD_TESTS)
