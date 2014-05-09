/*
 *  BASED UPON SOURCE IN RTEMS, MODIFIED FOR SIMULATOR
 */

/*
 *  COPYRIGHT (c) 1989-2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#if HAVE_CONFIG_H
#include "config.h"
#endif

#define SAPI_INIT
#define SCORE_INIT
#define RTEMS_API_INIT
#define POSIX_API_INIT

#include <rtems/system.h>
#include <rtems/score/assert.h>
#include <rtems/config.h>
#include <rtems/debug.h>
#include <rtems/extensionimpl.h>
#include <rtems/fatal.h>
#include <rtems/init.h>
#include <rtems/io.h>
#include <rtems/score/sysstate.h>

#include <rtems/score/apiext.h>
#include <rtems/score/apimutex.h>
#include <rtems/score/cpusetimpl.h>
#include <rtems/score/userextimpl.h>
#include <rtems/score/schedulerimpl.h>
#include <rtems/score/smpimpl.h>
#include <rtems/score/threadimpl.h>
#include <rtems/score/todimpl.h>
#include <rtems/score/watchdogimpl.h>
#include <rtems/score/wkspace.h>

#include <rtems/rtems/tasksimpl.h>
#include <rtems/rtems/semimpl.h>

#include <rtems/posix/keyimpl.h>

void Init__wrap__Thread_Dispatch();

/*
 *  Declare Object Information tables directly here instead of API
 *  specific initialization files as in cpukit/sapi/src.
 */
Objects_Information *_Internal_Objects[ OBJECTS_INTERNAL_CLASSES_LAST + 1 ];

Objects_Information *_RTEMS_Objects[ OBJECTS_RTEMS_CLASSES_LAST + 1 ];

Objects_Information *_POSIX_Objects[ OBJECTS_POSIX_CLASSES_LAST + 1 ];

extern void check_heir_and_executing(void);

void rtems_initialize_data_structures(void)
{
  _System_state_Handler_initialization( FALSE );

  _CPU_Initialize();

  /*
   *  Do this as early as possible to ensure no debugging output
   *  is even attempted to be printed.
   */
  _Debug_Manager_initialization();

  _API_extensions_Initialization();

  _Thread_Dispatch_initialization();

  _User_extensions_Handler_initialization();
  _ISR_Handler_initialization();

  /*
   * Initialize the internal support API and allocator Mutex
   */
  _Objects_Information_table[OBJECTS_INTERNAL_API] = _Internal_Objects;

  _API_Mutex_Initialization( 2 );
  _API_Mutex_Allocate( &_RTEMS_Allocator_Mutex );
  _API_Mutex_Allocate( &_Once_Mutex );

  _Watchdog_Handler_initialization();
  _TOD_Handler_initialization();

  _Thread_Handler_initialization();

  _Scheduler_Handler_initialization();

  _SMP_Handler_initialize();

  _CPU_set_Handler_initialization();

/* MANAGERS */
  /*
   * Install our API Object Management Table and initialize the
   * various managers.
   */
  _Objects_Information_table[OBJECTS_CLASSIC_API] = _RTEMS_Objects;

  _RTEMS_tasks_Manager_initialization();
  _Semaphore_Manager_initialization();

  /*
   * Install our API Object Management Table and initialize the
   * various managers.
   */
  _Objects_Information_table[OBJECTS_POSIX_API] = _POSIX_Objects;

  _POSIX_Key_Manager_initialization();

  /*
   * Discover and initialize the secondary cores in an SMP system.
   */
  _SMP_Handler_initialize();

  _System_state_Set( SYSTEM_STATE_BEFORE_MULTITASKING );

  /*
   *  No threads should be created before this point!!!
   *  _Thread_Executing and _Thread_Heir are not set.
   *
   *  At this point all API extensions are in place.  After the call to
   *  _Thread_Create_idle() _Thread_Executing and _Thread_Heir will be set.
   */
  _Thread_Create_idle();

  /*
   *  Scheduling can properly occur now as long as we avoid dispatching.
   */

  _System_state_Set( SYSTEM_STATE_UP );

  _SMP_Request_start_multitasking();

  _Thread_Start_multitasking();

  /* Add Initialization of the Thread_Dispatch wrapper */
  Init__wrap__Thread_Dispatch();

  /*
   *  Now we are back in a non-dispatching critical section
   */
  #if defined(RTEMS_SMP)
   {
      ISR_Level  level;

      /*
       * On SMP we enter _Thread_Handler() with interrupts disabled and
       * _Thread_Dispatch() obtained the per-CPU lock for us.  We have to
       * release it here and set the desired interrupt level of the thread.
       */
      Per_CPU_Control *cpu_self = _Per_CPU_Get();

      _Assert( cpu_self->thread_dispatch_disable_level == 1 );
      _Assert( _ISR_Get_level() != 0 );

      cpu_self->thread_dispatch_disable_level = 0;
      _Profiling_Thread_dispatch_enable( cpu_self, 0 );

      /* For whatever reason, we haven't locked our per cpu yet in the
       * Scheduler Simulator. Until this is done, this release is not needed.
       */
      /* _Per_CPU_Release( cpu_self ); */

      level =  _Thread_Executing->Start.isr_level;
      _ISR_Set_level( level);

      /*
       * The thread dispatch level changed from one to zero.  Make sure we lose
       * no thread dispatch necessary update.
       */
      _Thread_Dispatch();
    }
  #else
    _Thread_Enable_dispatch();
  #endif

  /*
   * Print an initial message
   */
  check_heir_and_executing();
}
