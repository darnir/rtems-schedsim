bin_PROGRAMS = schedsim_smppriority_affinity

SOURCES  = config.c
SOURCES += $(srcdir)/../schedsim_smpsimple/add_commands.c
SOURCES += $(srcdir)/../schedsim_smpsimple/main_dump_ready_tasks.c
schedsim_smppriority_affinity_SOURCES = $(SOURCES)

cpukitdir=@rtems_srcdir@/cpukit
schedsim_smppriority_affinity_CPPFLAGS  = -I$(top_builddir)/score/include
schedsim_smppriority_affinity_CPPFLAGS += -I$(srcdir)/sched_cpu
schedsim_smppriority_affinity_CPPFLAGS += -I$(srcdir)/../../rtems
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/include
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/score/include
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/score/inline
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/rtems/include
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/rtems/inline
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/sapi/include
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/sapi/inline
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/libcsupport/include
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/libmisc/stringto
schedsim_smppriority_affinity_CPPFLAGS += -I$(srcdir)/../../rtems/sched_cpu
schedsim_smppriority_affinity_CPPFLAGS += -I$(srcdir)/../shared/include
schedsim_smppriority_affinity_CPPFLAGS += -I$(srcdir)/../shared
if HAS_PTHREADS
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/posix/include
schedsim_smppriority_affinity_CPPFLAGS += -I$(cpukitdir)/posix/inline
endif
## Ensure all linker provided symbols are available
schedsim_smppriority_affinity_LDFLAGS = 
schedsim_smppriority_affinity_LDFLAGS += -Wl,--defsym=_TLS_Data_begin=0
schedsim_smppriority_affinity_LDFLAGS += -Wl,--defsym=_TLS_BSS_end=0
schedsim_smppriority_affinity_LDFLAGS += -Wl,--defsym=_TLS_Alignment=4

## Wrap _Thread_Dispatch so we can see context switches
schedsim_smppriority_affinity_LDFLAGS +=-Wl,--wrap=_Thread_Dispatch

## schedsim_smppriority_affinity_LDADD +=-Wl,--start-group
schedsim_smppriority_affinity_LDADD = ../shared/libschedsim.a
schedsim_smppriority_affinity_LDADD += ../../rtems/librtems.a
schedsim_smppriority_affinity_LDADD += ../shared/libschedsim.a
## schedsim_smppriority_affinity_LDADD +=-Wl,--end-group

check-local:
	@echo Running tests from SMP Priority Affinity
	$(srcdir)/../run_scenarios \
	    -s $(builddir)/schedsim_smppriority_affinity \
	    -S $(srcdir) \
	    -A
	@echo Running tests from SMP Simple Priority
	$(srcdir)/../run_scenarios \
	    -s $(builddir)/schedsim_smppriority_affinity \
	    -S $(srcdir)/../schedsim_smpsimple \
	    -A
	@echo Running tests from Uniprocessor Deterministic Priority
	$(srcdir)/../run_scenarios \
	    -s $(builddir)/schedsim_smppriority_affinity \
	    -S $(srcdir)/../schedsim_priority \
	    script02.scen script04.scen script05.scen script06.scen


include $(top_srcdir)/../automake/host.am
