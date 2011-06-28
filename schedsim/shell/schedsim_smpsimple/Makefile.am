##
## $Id$
##

bin_PROGRAMS = schedsim_smpsimple
schedsim_smpsimple_SOURCES = add_commands.c config.c \
  main_current_cpu.c main_dispatch.c main_dump_all_cpus.c \
  main_dump_ready_tasks.c printheir_executing.c smp_stub.c \
  wrap_thread_dispatch.c schedsim.cc

cpukitdir=@rtems_srcdir@/cpukit
schedsim_smpsimple_CPPFLAGS  = -I$(top_builddir)/score/include
schedsim_smpsimple_CPPFLAGS += -I$(srcdir)/sched_cpu
schedsim_smpsimple_CPPFLAGS += -I$(srcdir)/../../rtems
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/include
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/score/include
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/score/inline
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/rtems/include
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/rtems/inline
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/sapi/include
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/sapi/inline
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/libcsupport/include
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/libmisc/stringto
schedsim_smpsimple_CPPFLAGS += -I$(srcdir)/../../rtems/sched_cpu
schedsim_smpsimple_CPPFLAGS += -I$(srcdir)/../shared/include
schedsim_smpsimple_CPPFLAGS += -I$(srcdir)/../shared

schedsim_smpsimple_LDFLAGS =-Wl,--wrap=_Thread_Dispatch
## schedsim_smpsimple_LDADD +=-Wl,--start-group
schedsim_smpsimple_LDADD = ../shared/libschedsim.a
schedsim_smpsimple_LDADD += ../../rtems/librtems.a
schedsim_smpsimple_LDADD += ../shared/libschedsim.a
## schedsim_smpsimple_LDADD +=-Wl,--end-group

include $(top_srcdir)/../automake/host.am
