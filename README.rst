==========
vmod_sleep
==========

----------------------
Varnish Sleep Module
----------------------

:Date: 2016-07-14
:Version: 1.0
:Manual section: 3

SYNOPSIS
========

import sleep;

DESCRIPTION
===========

Sleep in VCL.

FUNCTIONS
=========

sleep
-----

Prototype
        ::

                sleep(DURATION t)
Return value
	VOID
Description
	Sleeps for specified amount of time (t). Supported types are ms (milliseconds), s (seconds), m (minutes), h (hours), d (days), w (weeks) and y (years). NOTE, please be aware of the various timeouts which may trigger if you sleep too long.
Example
        ::

                sleep.sleep(1ms);

USAGE EXAMPLE
=============

In your VCL you could then use this vmod along the following lines::

        import sleep;

        sub vcl_backend_error {
                sleep.sleep(5s);
                return (retry);
        }

INSTALLATION
============

The source tree is based on autotools to configure the building, and
does also have the necessary bits in place to do functional unit tests
using the ``varnishtest`` tool.

Building requires the Varnish header files and uses pkg-config to find
the necessary paths.

Pre-requisites::

 sudo apt-get install -y autotools-dev make automake libtool pkg-config libvarnishapi1 libvarnishapi-dev

Usage::

 ./autogen.sh
 ./configure

If you have installed Varnish to a non-standard directory, call
``autogen.sh`` and ``configure`` with ``PKG_CONFIG_PATH`` pointing to
the appropriate path. For sleep, when varnishd configure was called
with ``--prefix=$PREFIX``, use

 PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
 export PKG_CONFIG_PATH

Make targets:

* make - builds the vmod.
* make install - installs your vmod.
* make check - runs the unit tests in ``src/tests/*.vtc``
* make distcheck - run check and prepare a tarball of the vmod.

Installation directories
------------------------

By default, the vmod ``configure`` script installs the built vmod in
the same directory as Varnish, determined via ``pkg-config(1)``. The
vmod installation directory can be overridden by passing the
``VMOD_DIR`` variable to ``configure``.

Other files like man-pages and documentation are installed in the
locations determined by ``configure``, which inherits its default
``--prefix`` setting from Varnish.

COMMON PROBLEMS
===============

* configure: error: Need varnish.m4 -- see README.rst

  Check if ``PKG_CONFIG_PATH`` has been set correctly before calling
  ``autogen.sh`` and ``configure``

* Incompatibilities with different Varnish Cache versions

  Make sure you build this vmod against its correspondent Varnish Cache version.
  For sleep, to build against Varnish Cache 4.0, this vmod must be built from branch 4.0.
