ACLOCAL_AMFLAGS = -I ../../aclocal

lib_LIBRARIES = librtems.a

cpukitdir=@rtems_srcdir@/cpukit
rtemscdir=@rtems_srcdir@/c
librtems_a_CPPFLAGS  = -D__RTEMS_VIOLATE_KERNEL_VISIBILITY__
librtems_a_CPPFLAGS += -D_GNU_SOURCE
librtems_a_CPPFLAGS += -I$(top_builddir)/score/include
librtems_a_CPPFLAGS += -I$(srcdir)/sched_cpu
librtems_a_CPPFLAGS += -I$(cpukitdir)/include
librtems_a_CPPFLAGS += -I$(cpukitdir)/score/include
librtems_a_CPPFLAGS += -I$(cpukitdir)/rtems/include
librtems_a_CPPFLAGS += -I$(cpukitdir)/sapi/include
librtems_a_CPPFLAGS += -I$(cpukitdir)/libcsupport/include
librtems_a_CPPFLAGS += -I$(cpukitdir)/libmisc/stringto
if HAS_PTHREADS
librtems_a_CPPFLAGS += -I$(cpukitdir)/posix/include
librtems_a_CPPFLAGS += -I$(cpukitdir)/posix/include
endif

## Have own version of these
librtems_a_SOURCES = rtems_init.c
librtems_a_SOURCES += wkspace.c
librtems_a_SOURCES += debugio.c
librtems_a_SOURCES += sched_cpu/cpu_asm.c
librtems_a_SOURCES += sched_cpu/cpu.c

## CPUKIT/SCORE/SRC
librtems_a_SOURCES += $(cpukitdir)/score/src/interr.c
librtems_a_SOURCES += $(cpukitdir)/score/src/percpu.c
librtems_a_SOURCES += $(cpukitdir)/score/src/apiext.c
librtems_a_SOURCES += $(cpukitdir)/score/src/apimutex.c
librtems_a_SOURCES += $(cpukitdir)/score/src/apimutexlock.c
librtems_a_SOURCES += $(cpukitdir)/score/src/apimutexunlock.c
librtems_a_SOURCES += $(cpukitdir)/score/src/chainappend.c
librtems_a_SOURCES += $(cpukitdir)/score/src/chain.c
librtems_a_SOURCES += $(cpukitdir)/score/src/chainextract.c
librtems_a_SOURCES += $(cpukitdir)/score/src/chainget.c
librtems_a_SOURCES += $(cpukitdir)/score/src/chaininsert.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coremutex.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coremutexflush.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coremutexseize.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coremutexseizeintr.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coremutexsurrender.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coresem.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coresemflush.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coresemseize.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coresemsurrender.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coretod.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coretodget.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coretodgetuptimetimespec.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coretodsecondssinceepoch.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coretodset.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coretodtickle.c
librtems_a_SOURCES += $(cpukitdir)/score/src/coretodtickspersec.c
librtems_a_SOURCES += $(cpukitdir)/score/src/debugisownerofallocator.c
librtems_a_SOURCES += $(cpukitdir)/score/src/freechain.c
librtems_a_SOURCES += $(cpukitdir)/score/src/isr.c
librtems_a_SOURCES += $(cpukitdir)/score/src/log2table.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectallocate.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectapimaximumclass.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectclose.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectextendinformation.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectfree.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectget.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectgetinfo.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectgetinfoid.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectgetisr.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectgetnameasstring.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectgetnext.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectgetnoprotection.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectidtoname.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectinitializeinformation.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectnamespaceremove.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectnametoid.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectnametoidstring.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectsetname.c
librtems_a_SOURCES += $(cpukitdir)/score/src/objectshrinkinformation.c
librtems_a_SOURCES += $(cpukitdir)/score/src/rbtree.c
librtems_a_SOURCES += $(cpukitdir)/score/src/rbtreeextract.c
librtems_a_SOURCES += $(cpukitdir)/score/src/rbtreefind.c
librtems_a_SOURCES += $(cpukitdir)/score/src/rbtreeinsert.c
librtems_a_SOURCES += $(cpukitdir)/score/src/rbtreeiterate.c
librtems_a_SOURCES += $(cpukitdir)/score/src/rbtreenext.c
librtems_a_SOURCES += $(cpukitdir)/score/src/resourceiterate.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduler.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaultnodedestroy.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaultnodeinit.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaultreleasejob.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaultschedule.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaultstartidle.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaulttick.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaultupdate.c

# Uniprocessor Deterministic Scheduler 
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerpriorityblock.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerpriority.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerprioritychangepriority.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerpriorityprioritycompare.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerpriorityschedule.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerpriorityunblock.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerpriorityupdate.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerpriorityyield.c

# Uniprocessor Scheduler Simple
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersimpleblock.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersimple.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersimplechangepriority.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersimpleschedule.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersimpleunblock.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersimpleyield.c

# Uniprocessor Scheduler CBS
librtems_a_SOURCES += $(cpukitdir)/score/src
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsattachthread.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbscreateserver.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsgetapprovedbudget.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsgetremainingbudget.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsreleasejob.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbs.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsdestroyserver.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsgetexecutiontime.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsgetserverid.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbssetparameters.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbscleanup.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsdetachthread.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsgetparameters.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsnodeinit.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulercbsunblock.c

# Uniprocessor Scheduler EDF
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredfblock.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredfchangepriority.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredfprioritycompare.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredfschedule.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredfupdate.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredf.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredfnodeinit.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredfreleasejob.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredfunblock.c
librtems_a_SOURCES += $(cpukitdir)/score/src/scheduleredfyield.c

librtems_a_SOURCES += $(cpukitdir)/score/src/thread.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadchangepriority.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadclearstate.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadcreateidle.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threaddelayended.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threaddispatch.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadget.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadhandler.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadinitialize.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadloadenv.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadready.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadrestart.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadsetpriority.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadsetstate.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadstackallocate.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadstackfree.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadstart.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadstartmultitasking.c
librtems_a_SOURCES += $(cpukitdir)/score/src/iterateoverthreads.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadq.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadblockingoperationcancel.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadqdequeue.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadqenqueue.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadqextract.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadqextractwithproxy.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadqfirst.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadqflush.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadqprocesstimeout.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadqrequeue.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadqtimeout.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadyield.c
librtems_a_SOURCES += $(cpukitdir)/score/src/timespecaddto.c
librtems_a_SOURCES += $(cpukitdir)/score/src/timespecdividebyinteger.c
librtems_a_SOURCES += $(cpukitdir)/score/src/timespecdivide.c
librtems_a_SOURCES += $(cpukitdir)/score/src/timespecfromticks.c
librtems_a_SOURCES += $(cpukitdir)/score/src/timespecisvalid.c
librtems_a_SOURCES += $(cpukitdir)/score/src/timespeclessthan.c
librtems_a_SOURCES += $(cpukitdir)/score/src/timespecsubtract.c
librtems_a_SOURCES += $(cpukitdir)/score/src/timespectoticks.c
librtems_a_SOURCES += $(cpukitdir)/score/src/userextaddset.c
librtems_a_SOURCES += $(cpukitdir)/score/src/userext.c
librtems_a_SOURCES += $(cpukitdir)/score/src/userextiterate.c
librtems_a_SOURCES += $(cpukitdir)/score/src/userextremoveset.c
librtems_a_SOURCES += $(cpukitdir)/score/src/watchdogadjust.c
librtems_a_SOURCES += $(cpukitdir)/score/src/watchdogadjusttochain.c
librtems_a_SOURCES += $(cpukitdir)/score/src/watchdog.c
librtems_a_SOURCES += $(cpukitdir)/score/src/watchdoginsert.c
librtems_a_SOURCES += $(cpukitdir)/score/src/watchdogremove.c
librtems_a_SOURCES += $(cpukitdir)/score/src/watchdogtickle.c
librtems_a_SOURCES += $(cpukitdir)/sapi/src/debug.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clockgetsecondssinceepoch.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clockgettickspersecond.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clockgettod.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clockgettodtimeval.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clockgetuptime.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clockset.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clocksetnsecshandler.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clocktick.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clocktodtoseconds.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/clocktodvalidate.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/getprocessorcount.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/sem.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/semcreate.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/semdata.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/semdelete.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/semflush.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/semident.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/semobtain.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/semrelease.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/semtranslatereturncode.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/signalcatch.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/status.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/statustext.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/tasks.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskdata.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskmode.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskvariable_invoke_dtor.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskcreate.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskstart.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskident.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskdelete.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskresume.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/tasksuspend.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/tasksetpriority.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskmode.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskwakeafter.c
librtems_a_SOURCES += $(cpukitdir)/posix/src/key.c
librtems_a_SOURCES += $(cpukitdir)/posix/src/keyfreememory.c
librtems_a_SOURCES += $(cpukitdir)/posix/src/keyrundestructors.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/__assert.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assoclocalbyname.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assoclocalbyremotebitfield.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assoclocalbyremote.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocnamebad.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocnamebylocalbitfield.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocnamebylocal.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocnamebyremotebitfield.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocnamebyremote.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocptrbylocal.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocptrbyname.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocptrbyremote.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocremotebylocalbitfield.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocremotebylocal.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/assocremotebyname.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/error.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/printk.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/vprintk.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/rtems_heap_null_extend.c
librtems_a_SOURCES += $(cpukitdir)/libcsupport/src/rtems_putc.c
librtems_a_SOURCES += $(cpukitdir)/libmisc/stringto/stringtodouble.c
librtems_a_SOURCES += $(cpukitdir)/libmisc/stringto/stringtofloat.c
librtems_a_SOURCES += $(cpukitdir)/libmisc/stringto/stringtoint.c
librtems_a_SOURCES += $(cpukitdir)/libmisc/stringto/stringtolong.c
librtems_a_SOURCES += $(cpukitdir)/libmisc/stringto/stringtopointer.c
librtems_a_SOURCES += $(cpukitdir)/libmisc/stringto/stringtounsignedchar.c
librtems_a_SOURCES += $(cpukitdir)/libmisc/stringto/stringtounsignedint.c
librtems_a_SOURCES += $(cpukitdir)/libmisc/stringto/stringtounsignedlong.c

if HAS_SMP
librtems_a_SOURCES += $(cpukitdir)/score/src/smp.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threaddisabledispatch.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threadenabledispatch.c
librtems_a_SOURCES += $(cpukitdir)/score/src/threaddispatchdisablelevel.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerchangeroot.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerprioritysmp.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersimplesmp.c
librtems_a_SOURCES += $(cpukitdir)/score/src/debugisthreaddispatchingallowed.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaultaskforhelp.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaultgetaffinity.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerdefaultsetaffinity.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulergetaffinity.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulerpriorityaffinitysmp.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersetaffinity.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersmpdebug.c
librtems_a_SOURCES += $(cpukitdir)/score/src/schedulersmpstartidle.c
librtems_a_SOURCES += $(cpukitdir)/score/src/cpuset.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/taskgetaffinity.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/tasksetaffinity.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/schedulerident.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/schedulergetprocessorset.c
librtems_a_SOURCES += $(cpukitdir)/rtems/src/tasksetscheduler.c
endif

schedsim_includedir = $(includedir)/schedsim
schedsim_rtems_includedir = $(includedir)/schedsim/rtems
schedsim_rtems_score_includedir = $(includedir)/schedsim/rtems/score
schedsim_rtems_rtems_includedir = $(includedir)/schedsim/rtems/rtems

schedsim_include_HEADERS  = \
  ${cpukitdir}/rtems/include/rtems.h \
  sched_cpu/stdatomic.h \
  sched_cpu/sys/_types.h \
  sched_cpu/machine/_types.h \
  sched_cpu/machine/_default_types.h \
  sched_cpu/sys/features.h \
  sched_cpu/sys/lock.h \
  sched_cpu/sys/cpuset.h

schedsim_rtems_include_HEADERS  = \
  ${cpukitdir}/score/include//rtems/seterr.h \
  ${cpukitdir}/score/include/rtems/system.h \
  ${cpukitdir}/score/include/rtems/debug.h \
  ${cpukitdir}/include/rtems/bspIo.h \
  $(cpukitdir)/sapi/include/rtems/fatal.h \
  $(cpukitdir)/sapi/include/rtems/init.h \
  $(cpukitdir)/sapi/include/rtems/config.h \
  $(cpukitdir)/sapi/include/rtems/sptables.h \
  $(cpukitdir)/sapi/include/rtems/io.h \
  $(cpukitdir)/sapi/include/rtems/mptables.h \
  $(cpukitdir)/sapi/include/rtems/extension.h \
  $(cpukitdir)/sapi/include/rtems/chain.h \
  $(cpukitdir)/sapi/include/confdefs.h \
  $(cpukitdir)/libcsupport/include/rtems/libio_.h \
  $(cpukitdir)/libcsupport/include/rtems/watchdogdrv.h \
  $(cpukitdir)/libcsupport/include/rtems/error.h \
  $(cpukitdir)/libcsupport/include/rtems/framebuffer.h \
  $(cpukitdir)/libcsupport/include/rtems/assoc.h \
  $(cpukitdir)/libcsupport/include/rtems/libio.h \
  $(cpukitdir)/libcsupport/include/rtems/gxx_wrappers.h \
  $(cpukitdir)/libcsupport/include/rtems/libcsupport.h \
  $(cpukitdir)/libcsupport/include/rtems/termiostypes.h \
  $(cpukitdir)/libcsupport/include/rtems/malloc.h \
  sched_cpu/rtems/stringto.h \
  sched_cpu/rtems/asm.h

if HAS_PTHREADS
schedsim_rtems_include_HEADERS  += \
  ${cpukitdir}/posix/include/rtems/posix/config.h
endif

schedsim_rtems_score_include_HEADERS = \
  ${cpukitdir}/score/include/rtems/score/address.h \
  ${cpukitdir}/score/include/rtems/score/coremutex.h \
  ${cpukitdir}/score/include/rtems/score/corerwlock.h \
  ${cpukitdir}/score/include/rtems/score/cpuset.h \
  ${cpukitdir}/score/include/rtems/score/cpusetimpl.h \
  ${cpukitdir}/score/include/rtems/score/cpustdatomic.h \
  ${cpukitdir}/score/include/rtems/score/threadsync.h \
  ${cpukitdir}/score/include/rtems/score/priority.h \
  ${cpukitdir}/score/include/rtems/score/sysstate.h \
  ${cpukitdir}/score/include/rtems/score/threadmp.h \
  ${cpukitdir}/score/include/rtems/score/mppkt.h \
  ${cpukitdir}/score/include/rtems/score/stack.h \
  ${cpukitdir}/score/include/rtems/score/context.h \
  ${cpukitdir}/score/include/rtems/score/heap.h \
  ${cpukitdir}/score/include/rtems/score/coresem.h \
  ${cpukitdir}/score/include/rtems/score/corebarrier.h \
  ${cpukitdir}/score/include/rtems/score/corespinlock.h \
  ${cpukitdir}/score/include/rtems/score/prioritybitmap.h \
  ${cpukitdir}/score/include/rtems/score/timestamp.h \
  ${cpukitdir}/score/include/rtems/score/basedefs.h \
  ${cpukitdir}/score/include/rtems/score/wkspace.h \
  ${cpukitdir}/score/include/rtems/score/percpu.h \
  ${cpukitdir}/score/include/rtems/score/watchdog.h \
  ${cpukitdir}/score/include/rtems/score/tod.h \
  ${cpukitdir}/score/include/rtems/score/protectedheap.h \
  ${cpukitdir}/score/include/rtems/score/timestamp64.h \
  ${cpukitdir}/score/include/rtems/score/chain.h \
  ${cpukitdir}/score/include/rtems/score/apiext.h \
  ${cpukitdir}/score/include/rtems/score/userext.h \
  ${cpukitdir}/score/include/rtems/score/userextimpl.h \
  ${cpukitdir}/score/include/rtems/score/threadq.h \
  ${cpukitdir}/score/include/rtems/score/apimutex.h \
  ${cpukitdir}/score/include/rtems/score/scheduler.h \
  ${cpukitdir}/score/include/rtems/score/isr.h \
  ${cpukitdir}/score/include/rtems/score/mpci.h \
  ${cpukitdir}/score/include/rtems/score/object.h \
  ${cpukitdir}/score/include/rtems/score/copyrt.h \
  ${cpukitdir}/score/include/rtems/score/states.h \
  ${cpukitdir}/score/include/rtems/score/objectmp.h \
  ${cpukitdir}/score/include/rtems/score/thread.h \
  ${cpukitdir}/score/include/rtems/score/coremsg.h \
  ${cpukitdir}/score/include/rtems/score/schedulerpriority.h \
  ${cpukitdir}/score/include/rtems/score/schedulersimple.h \
  ${cpukitdir}/score/include/rtems/score/timespec.h \
  ${cpukitdir}/score/include/rtems/score/interr.h \
  sched_cpu/rtems/score/cpu_asm.h \
  $(top_builddir)/score/include/rtems/score/cpuopts.h \
  sched_cpu/rtems/score/cpu.h \
  sched_cpu/rtems/score/cpuatomic.h \
  sched_cpu/rtems/score/types.h \
  sched_cpu/rtems/score/no_cpu.h 


schedsim_rtems_rtems_include_HEADERS = \
  ${cpukitdir}/rtems/include/rtems/rtems/event.h \
  ${cpukitdir}/rtems/include/rtems/rtems/cache.h \
  ${cpukitdir}/rtems/include/rtems/rtems/timer.h \
  ${cpukitdir}/rtems/include/rtems/rtems/regionmp.h \
  ${cpukitdir}/rtems/include/rtems/rtems/config.h \
  ${cpukitdir}/rtems/include/rtems/rtems/ratemon.h \
  ${cpukitdir}/rtems/include/rtems/rtems/rtemsapi.h \
  ${cpukitdir}/rtems/include/rtems/rtems/mp.h \
  ${cpukitdir}/rtems/include/rtems/rtems/dpmem.h \
  ${cpukitdir}/rtems/include/rtems/rtems/status.h \
  ${cpukitdir}/rtems/include/rtems/rtems/sem.h \
  ${cpukitdir}/rtems/include/rtems/rtems/barriermp.h \
  ${cpukitdir}/rtems/include/rtems/rtems/types.h \
  ${cpukitdir}/rtems/include/rtems/rtems/intr.h \
  ${cpukitdir}/rtems/include/rtems/rtems/signalmp.h \
  ${cpukitdir}/rtems/include/rtems/rtems/eventmp.h \
  ${cpukitdir}/rtems/include/rtems/rtems/part.h \
  ${cpukitdir}/rtems/include/rtems/rtems/message.h \
  ${cpukitdir}/rtems/include/rtems/rtems/region.h \
  ${cpukitdir}/rtems/include/rtems/rtems/object.h \
  ${cpukitdir}/rtems/include/rtems/rtems/partmp.h \
  ${cpukitdir}/rtems/include/rtems/rtems/msgmp.h \
  ${cpukitdir}/rtems/include/rtems/rtems/clock.h \
  ${cpukitdir}/rtems/include/rtems/rtems/modes.h \
  ${cpukitdir}/rtems/include/rtems/rtems/taskmp.h \
  ${cpukitdir}/rtems/include/rtems/rtems/asr.h \
  ${cpukitdir}/rtems/include/rtems/rtems/semmp.h \
  ${cpukitdir}/rtems/include/rtems/rtems/options.h \
  ${cpukitdir}/rtems/include/rtems/rtems/attr.h \
  ${cpukitdir}/rtems/include/rtems/rtems/support.h \
  ${cpukitdir}/rtems/include/rtems/rtems/signal.h \
  ${cpukitdir}/rtems/include/rtems/rtems/barrier.h \
  ${cpukitdir}/rtems/include/rtems/rtems/tasks.h

schedsim_include_HEADERS += rtems_sched.h

include $(top_srcdir)/../automake/host.am
