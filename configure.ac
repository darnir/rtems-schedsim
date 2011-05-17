## Process this file with autoconf to produce a configure script.
## 
## $Id$

AC_PREREQ([2.68])
AC_INIT([rtems],[_RTEMS_VERSION],[http://www.rtems.org/bugzilla])
AC_CONFIG_SRCDIR([schedsim])
RTEMS_TOP([.])

# Abort if trying to build inside of the source tree.
AS_IF([test -f aclocal/version.m4],[
  rm -f config.cache config.log confdefs.h
  AC_MSG_ERROR([***]
    [Attempt to build inside of the source tree]
    [Please use a separate build directory, instead] )
])

AC_CANONICAL_TARGET([])
AM_INIT_AUTOMAKE([no-define foreign dist-bzip2 no-dist-gzip 1.11.1])
AM_MAINTAINER_MODE

## These option are only in here to let --help report all supported
## options.
RTEMS_ENABLE_MULTIPROCESSING
RTEMS_ENABLE_POSIX
RTEMS_ENABLE_NETWORKING
RTEMS_ENABLE_CXX
RTEMS_ENABLE_TESTS  
RTEMS_ENABLE_RTEMS_DEBUG
RTEMS_ENABLE_RTEMSBSP
RTEMS_ENABLE_MULTILIB
RTEMS_ENABLE_SMP

AC_ARG_ENABLE([docs],
  [AS_HELP_STRING([--enable-docs],[enable building documentation
    (default:disabled)])])

RTEMS_ENABLE_RTEMSDIR
if test X"${rtems_srcdir}" = "X" ; then
  AC_MSG_ERROR([RTEMS Source Directory Not Specified])
fi
if test ! -d ${rtems_srcdir}; then
  AC_MSG_ERROR([RTEMS Source Directory ${rtems_srcdir} Does Not Exist])
fi
if test ! -d ${rtems_srcdir}/cpukit; then
  AC_MSG_ERROR([RTEMS Source Directory ${rtems_srcdir}/cpukit Does Not Exist])
fi

RTEMS_BUILD_CONFIG_SUBDIRS([schedsim])

AC_SUBST(rtems_srcdir)

#AS_IF([test x"${enable_docs}" = x"yes"],
#  [RTEMS_BUILD_CONFIG_SUBDIRS([doc])])

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
