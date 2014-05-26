ACLOCAL_AMFLAGS = -I ../../../aclocal

lib_LIBRARIES = libschedsim.a

cpukitdir=@rtems_srcdir@/cpukit
libschedsim_a_CPPFLAGS  = -D__RTEMS_VIOLATE_KERNEL_VISIBILITY__
libschedsim_a_CPPFLAGS += -I$(top_builddir)/score/include
libschedsim_a_CPPFLAGS += -I$(srcdir)/sched_cpu
libschedsim_a_CPPFLAGS += -I$(srcdir)/../../rtems
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/include
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/score/include
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/score/inline
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/rtems/include
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/rtems/inline
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/sapi/include
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/sapi/inline
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/libcsupport/include
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/libmisc/stringto
libschedsim_a_CPPFLAGS += -I$(srcdir)/../../rtems/sched_cpu
libschedsim_a_CPPFLAGS += -I$(srcdir)/include
if HAS_PTHREADS
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/posix/include
libschedsim_a_CPPFLAGS += -I$(cpukitdir)/posix/inline
endif

libschedsim_a_SOURCES =
libschedsim_a_SOURCES += schedsim.c
libschedsim_a_SOURCES += commands.c
libschedsim_a_SOURCES += getopt.c
libschedsim_a_SOURCES += lookup_semaphore.c
libschedsim_a_SOURCES += lookup_task.c
libschedsim_a_SOURCES += main_dump_all_cpus.c
libschedsim_a_SOURCES += main_echo.c
libschedsim_a_SOURCES += main_executing.c
libschedsim_a_SOURCES += main_heir.c
libschedsim_a_SOURCES += main_help.c
libschedsim_a_SOURCES += main_rtemsinit.c
libschedsim_a_SOURCES += main_clocktick.c
libschedsim_a_SOURCES += main_semcreate.c
libschedsim_a_SOURCES += main_semdelete.c
libschedsim_a_SOURCES += main_semflush.c
libschedsim_a_SOURCES += main_semobtain.c
libschedsim_a_SOURCES += main_semrelease.c
libschedsim_a_SOURCES += main_taskcreate.c
libschedsim_a_SOURCES += main_taskdelete.c
libschedsim_a_SOURCES += main_taskmode.c
libschedsim_a_SOURCES += main_taskpriority.c
libschedsim_a_SOURCES += main_taskresume.c
libschedsim_a_SOURCES += main_tasksuspend.c
libschedsim_a_SOURCES += main_taskwakeafter.c
libschedsim_a_SOURCES += schedsim_disable_dispatch.c
libschedsim_a_SOURCES += shell_cmdset.c
libschedsim_a_SOURCES += shell_makeargs.c 
if HAS_SMP
libschedsim_a_SOURCES += smp_stub.c
libschedsim_a_SOURCES += main_taskgetaffinity.c
libschedsim_a_SOURCES += main_tasksetaffinity.c
endif

schedsim_shell_includedir = $(includedir)/schedsim
schedsim_newlib_includedir = $(includedir)/schedsim/newlib

schedsim_shell_include_HEADERS  = include/shell.h schedsim_shell.h

schedsim_newlib_include_HEADERS = \
  include/newlib/getopt.h \
  include/newlib/_ansi.h 

include $(top_srcdir)/../automake/host.am
