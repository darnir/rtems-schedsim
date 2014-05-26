bin_PROGRAMS = schedsim_smpsimple
schedsim_smpsimple_SOURCES =
schedsim_smpsimple_SOURCES += add_commands.c
schedsim_smpsimple_SOURCES += config.c
schedsim_smpsimple_SOURCES += main_dispatch.c
schedsim_smpsimple_SOURCES += main_dump_ready_tasks.c
schedsim_smpsimple_SOURCES += printheir_executing.c
schedsim_smpsimple_SOURCES += wrap_thread_dispatch.c

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
if HAS_PTHREADS
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/posix/include
schedsim_smpsimple_CPPFLAGS += -I$(cpukitdir)/posix/inline
endif
## Ensure all linker provided symbols are available
schedsim_smpsimple_LDFLAGS = 
schedsim_smpsimple_LDFLAGS += -Wl,--defsym=_TLS_Data_begin=0
schedsim_smpsimple_LDFLAGS += -Wl,--defsym=_TLS_BSS_end=0
schedsim_smpsimple_LDFLAGS += -Wl,--defsym=_TLS_Alignment=4

## Wrap _Thread_Dispatch so we can see context switches
schedsim_smpsimple_LDFLAGS +=-Wl,--wrap=_Thread_Dispatch

## schedsim_smpsimple_LDADD +=-Wl,--start-group
schedsim_smpsimple_LDADD = ../shared/libschedsim.a
schedsim_smpsimple_LDADD += ../../rtems/librtems.a
schedsim_smpsimple_LDADD += ../shared/libschedsim.a
## schedsim_smpsimple_LDADD +=-Wl,--end-group

include $(top_srcdir)/../automake/host.am
