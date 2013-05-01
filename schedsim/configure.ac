## Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([rtems-tools-schedsim],[_RTEMS_VERSION],[http://www.rtems.org/bugzilla])
AC_CONFIG_SRCDIR([rtems])
RTEMS_TOP(..)

RTEMS_CANONICAL_TARGET_CPU

AM_INIT_AUTOMAKE([no-define foreign 1.11.1])
AM_MAINTAINER_MODE

RTEMS_ENABLE_MULTIPROCESSING
RTEMS_ENABLE_POSIX
RTEMS_ENABLE_RTEMS_DEBUG
RTEMS_ENABLE_NETWORKING

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


RTEMS_CHECK_MULTIPROCESSING
RTEMS_CHECK_POSIX_API
RTEMS_CHECK_NETWORKING
RTEMS_CHECK_SMP

rtems_major=`echo _RTEMS_VERSION | sed "s/\..*//"`
rtems_minor=`echo _RTEMS_VERSION | sed "s/[[0-9]][[0-9]]*\.//;s/\..*//"`
rtems_revision=`echo _RTEMS_VERSION | sed "s/[[0-9]][[0-9]]*\.//;s/[[0-9]][[0-9]]*\.//;s/\..*//"`

## This is needed to generate the field offsets of the per CPU 
## data structure so they can be accessed from assembly code.
AC_CHECK_SIZEOF([void *])

_RTEMS_CPUOPT_INIT

RTEMS_CPUOPT([RTEMS_DEBUG],
  [test x"${enable_rtems_debug}" = x"yes"],
  [1],
  [if RTEMS_DEBUG is enabled])

RTEMS_CPUOPT([RTEMS_MULTIPROCESSING],
  [test x"$enable_multiprocessing" = xyes],
  [1],
  [if multiprocessing is enabled])

RTEMS_CPUOPT([RTEMS_NEWLIB],
  [test x"$RTEMS_USE_NEWLIB" = xyes],
  [1],
  [if using newlib])

RTEMS_CPUOPT([RTEMS_POSIX_API],
  [test x"$rtems_cv_HAS_POSIX_API" = xyes],
  [1],
  [if posix api is supported])

RTEMS_CPUOPT([RTEMS_SMP],
  [test x"$RTEMS_HAS_SMP" = xyes],
  [1],
  [if SMP is enabled])

RTEMS_CPUOPT([RTEMS_NETWORKING],
  [test x"$rtems_cv_HAS_NETWORKING" = xyes],
  [1],
  [if networking is enabled])

RTEMS_CPUOPT([RTEMS_VERSION],
  [true],
  ["]_RTEMS_VERSION["],
  [RTEMS version string])

RTEMS_CPUOPT([__RTEMS_USE_TICKS_FOR_STATISTICS__],
  [test x"${USE_TICKS_FOR_STATISTICS}" = x"1"],
  [1],
  [disable nanosecond granularity for statistics])

RTEMS_CPUOPT([__RTEMS_USE_TICKS_CPU_USAGE_STATISTICS__],
  [test x"${USE_TICKS_FOR_CPU_USAGE_STATISTICS}" = x"1"],
  [1],
  [disable nanosecond granularity for cpu usage statistics])

RTEMS_CPUOPT([__RTEMS_USE_TICKS_RATE_MONOTONIC_STATISTICS__],
  [test x"${USE_TICKS_FOR_RATE_MONOTONIC_STATISTICS}" = x"1"],
  [1],
  [disable nanosecond granularity for period statistics])

## This improves both the size and coverage analysis.
RTEMS_CPUOPT([__RTEMS_DO_NOT_INLINE_THREAD_ENABLE_DISPATCH__],
  [test x"${RTEMS_DO_NOT_INLINE_THREAD_ENABLE_DISPATCH}" = x"1"],
  [1],
  [disable inlining _Thread_Enable_dispatch])

## This improves both the size and coverage analysis.
RTEMS_CPUOPT([__RTEMS_DO_NOT_INLINE_CORE_MUTEX_SEIZE__],
  [test x"${RTEMS_DO_NOT_INLINE_CORE_MUTEX_SEIZE}" = x"1"],
  [1],
  [disable inlining _Thread_Enable_dispatch])

## This improves both the size and coverage analysis.
RTEMS_CPUOPT([__RTEMS_DO_NOT_UNROLL_THREADQ_ENQUEUE_PRIORITY__],
  [test x"${RTEMS_DO_NOT_UNROLL_THREADQ_ENQUEUE_PRIORITY}" = x"1"],
  [1],
  [disable inlining _Thread_queue_Enqueue_priority])

## This gives the same behavior as 4.8 and older
RTEMS_CPUOPT([__RTEMS_STRICT_ORDER_MUTEX__],
  [test x"${ENABLE_STRICT_ORDER_MUTEX}" = x"1"],
  [1],
  [disable strict order mutex])

## Deactivate ada bindings
RTEMS_CPUOPT([__RTEMS_ADA__],
  [test x"${enable_ada}" = x"yes"],
  [1],
  [Define to 1 if ada/gnat bindings are built-in])

RTEMS_CPUOPT([RTEMS_SCHEDSIM],
  [true],
  [1],
  [defined to indicate building RTEMS Scheduler Simulator])

## Then we propagate a private copy of the value into cpuopts.h
## so it is always available to the RTEMS header files.

RTEMS_CPUOPT([__RTEMS_SIZEOF_VOID_P__],
  [true],
  [$ac_cv_sizeof_void_p],
  [Size of a void * pointer])

RTEMS_CPUOPT([__RTEMS_MAJOR__],
  [true],
  [$rtems_major],
  [major version portion of an RTEMS release])

RTEMS_CPUOPT([__RTEMS_MINOR__],
  [true],
  [$rtems_minor],
  [minor version portion of an RTEMS release])

RTEMS_CPUOPT([__RTEMS_REVISION__],
  [true],
  [$rtems_revision],
  [revision version portion of an RTEMS release])

_RTEMS_CPUOPT_FINI

AM_CONDITIONAL(LIBRPC,[test x"$rtems_cv_HAS_NETWORKING" = x"yes"])
AM_CONDITIONAL(NEWLIB,test x"$RTEMS_USE_NEWLIB" = x"yes")

AM_CONDITIONAL(HAS_MP,test x"$enable_multiprocessing" = x"yes" )
AM_CONDITIONAL(HAS_SMP,[test "$RTEMS_HAS_SMP" = "yes"])

AM_CONDITIONAL(HAS_PTHREADS,test x"$rtems_cv_HAS_POSIX_API" = x"yes")
AM_CONDITIONAL(LIBNETWORKING,test x"$rtems_cv_HAS_NETWORKING" = x"yes")

AC_SUBST(rtems_srcdir)
AC_SUBST(program_prefix)

# Explicitly list all Makefiles here
AC_CONFIG_FILES([
Makefile
rtems/Makefile
shell/Makefile
shell/shared/Makefile
shell/schedsim_priority/Makefile
shell/schedsim_smpsimple/Makefile
])
AC_OUTPUT
