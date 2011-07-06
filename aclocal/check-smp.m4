dnl $Id$
dnl
AC_DEFUN([RTEMS_CHECK_SMP],
[dnl
AC_REQUIRE([RTEMS_ENABLE_SMP])dnl

AC_CACHE_CHECK([whether CPU supports libposix],
  rtems_cv_HAS_SMP,
  [dnl
    case "$RTEMS_CPU" in
    *)
      if test "${RTEMS_HAS_SMP}" = "yes"; then
        rtems_cv_HAS_SMP="yes";
      else
        rtems_cv_HAS_SMP="disabled";
      fi
      ;;
    esac])
])
