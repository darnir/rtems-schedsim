dnl $Id$

dnl XXX
dnl RTEMS_ENABLE_RTEMSDIR(rtems_dir)
AC_DEFUN([RTEMS_ENABLE_RTEMSDIR],
[
AC_BEFORE([$0], [RTEMS_SRC_DIR])
AC_ARG_ENABLE(rtemsdir,
[AS_HELP_STRING([--enable-rtemsdir=DIRECTORY],
[RTEMS SOURCE DIRECTORY])],
[case "${rtemsdir}" in
  yes ) rtems_srcdir="" ;;
  no ) rtems_srcdir="no" ;;
  *) rtems_srcdir="$enableval" ;;
esac],[rtems_srcdir=""])
])
