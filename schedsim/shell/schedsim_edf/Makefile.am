bin_PROGRAMS = schedsim_edf
schedsim_edf_SOURCES = config.c
schedsim_edf_SOURCES += $(srcdir)/../shared/add_commands_stub.c

cpukitdir=@rtems_srcdir@/cpukit
schedsim_edf_CPPFLAGS  = -I$(top_builddir)/score/include
schedsim_edf_CPPFLAGS += -I$(srcdir)/sched_cpu
schedsim_edf_CPPFLAGS += -I$(srcdir)/../../rtems
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/include
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/score/include
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/score/inline
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/rtems/include
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/rtems/inline
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/sapi/include
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/sapi/inline
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/libcsupport/include
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/libmisc/stringto
schedsim_edf_CPPFLAGS += -I$(srcdir)/../../rtems/sched_cpu
schedsim_edf_CPPFLAGS += -I$(srcdir)/../shared/include
schedsim_edf_CPPFLAGS += -I$(srcdir)/../shared
if HAS_PTHREADS
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/posix/include
schedsim_edf_CPPFLAGS += -I$(cpukitdir)/posix/inline
endif

## Ensure all linker provided symbols are available
schedsim_edf_LDFLAGS = 
schedsim_edf_LDFLAGS += -Wl,--defsym=_TLS_Data_begin=0
schedsim_edf_LDFLAGS += -Wl,--defsym=_TLS_BSS_end=0
schedsim_edf_LDFLAGS += -Wl,--defsym=_TLS_Alignment=4

## Wrap _Thread_Dispatch so we can see context switches
schedsim_edf_LDFLAGS += -Wl,--wrap=_Thread_Dispatch

## Link in all support libraries
## schedsim_edfLDADD +=-Wl,--start-group
schedsim_edf_LDADD = ../shared/libschedsim.a
schedsim_edf_LDADD += ../../rtems/librtems.a
schedsim_edf_LDADD += ../shared/libschedsim.a
## schedsim_edf_LDADD +=-Wl,--end-group

check-local:
	@echo Running tests from Uniprocessor Deterministic Priority
	$(srcdir)/../run_scenarios \
	    -s $(builddir)/schedsim_edf \
	    -S $(srcdir)/../schedsim_priority \
	    -A

include $(top_srcdir)/../automake/host.am
