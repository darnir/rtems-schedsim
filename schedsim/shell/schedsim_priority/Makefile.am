##
## $Id$
##

bin_PROGRAMS = schedsim_priority
schedsim_priority_SOURCES = config.c \
    schedsim.cc wrap_thread_dispatch.c printheir_executing.c

if HAS_SMP
schedsim_priority_SOURCES += smp_stub.c
endif
cpukitdir=@rtems_srcdir@/cpukit
schedsim_priority_CPPFLAGS  = -I$(top_builddir)/score/include
schedsim_priority_CPPFLAGS += -I$(srcdir)/sched_cpu
schedsim_priority_CPPFLAGS += -I$(srcdir)/../../rtems
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/include
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/score/include
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/score/inline
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/rtems/include
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/rtems/inline
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/sapi/include
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/sapi/inline
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/libcsupport/include
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/libmisc/stringto
schedsim_priority_CPPFLAGS += -I$(srcdir)/../../rtems/sched_cpu
schedsim_priority_CPPFLAGS += -I$(srcdir)/../shared/include
schedsim_priority_CPPFLAGS += -I$(srcdir)/../shared

schedsim_priority_LDFLAGS =-Wl,--wrap=_Thread_Dispatch
## schedsim_priorityLDADD +=-Wl,--start-group
schedsim_priority_LDADD = ../shared/libschedsim.a
schedsim_priority_LDADD += ../../rtems/librtems.a
schedsim_priority_LDADD += ../shared/libschedsim.a
## schedsim_priority_LDADD +=-Wl,--end-group

include $(top_srcdir)/../automake/host.am
