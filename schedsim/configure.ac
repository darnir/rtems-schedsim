## Process this file with autoconf to produce a configure script.
## 
## $Id$

AC_PREREQ([2.68])
AC_INIT([rtems-tools-schedsim],[_RTEMS_VERSION],[http://www.rtems.org/bugzilla])
AC_CONFIG_SRCDIR([rtems])
RTEMS_TOP(..)

RTEMS_CANONICAL_TARGET_CPU

AM_INIT_AUTOMAKE([no-define foreign 1.11.1])
AM_MAINTAINER_MODE

AC_PROG_RANLIB
# FIXME: Hack to enforce gnu99 on systems with GCC which do not default to gnu99
AC_PROG_CC_C99
AC_PROG_CXX
# FIXME: Should abort if c99 or c++ are not available.
# FIXME: Should abort on systems without GCC.

# FIXME: This package is not a tool, it's a separate, hacked up RTEMS port
RTEMS_TOOLPATHS

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

AC_SUBST(rtems_srcdir)

AC_SUBST(program_prefix)

# Explicitly list all Makefiles here
AC_CONFIG_FILES([
Makefile
rtems/Makefile
shell/Makefile
shell/shared/Makefile
shell/schedsim_priority/Makefile
])
AC_OUTPUT
