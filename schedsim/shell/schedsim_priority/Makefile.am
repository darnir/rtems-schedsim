bin_PROGRAMS = schedsim_priority
schedsim_priority_SOURCES = config.c
schedsim_priority_SOURCES += wrap_thread_dispatch.c
schedsim_priority_SOURCES += printheir_executing.c
schedsim_priority_SOURCES += $(srcdir)/../shared/add_commands_stub.c

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
if HAS_PTHREADS
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/posix/include
schedsim_priority_CPPFLAGS += -I$(cpukitdir)/posix/inline
endif

## Ensure all linker provided symbols are available
schedsim_priority_LDFLAGS = 
schedsim_priority_LDFLAGS += -Wl,--defsym=_TLS_Data_begin=0
schedsim_priority_LDFLAGS += -Wl,--defsym=_TLS_BSS_end=0
schedsim_priority_LDFLAGS += -Wl,--defsym=_TLS_Alignment=4

## Wrap _Thread_Dispatch so we can see context switches
schedsim_priority_LDFLAGS += -Wl,--wrap=_Thread_Dispatch

## Link in all support libraries
## schedsim_priorityLDADD +=-Wl,--start-group
schedsim_priority_LDADD = ../shared/libschedsim.a
schedsim_priority_LDADD += ../../rtems/librtems.a
schedsim_priority_LDADD += ../shared/libschedsim.a
## schedsim_priority_LDADD +=-Wl,--end-group

include $(top_srcdir)/../automake/host.am
