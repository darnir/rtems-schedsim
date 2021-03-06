/**
 *  @file
 *  RTEMS SMP Support for Scheduler Simulator
 */

/*
 *  COPYRIGHT (c) 1989-2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#include <rtems.h>
#include <rtems/bspIo.h>
#include <stdlib.h>

/*
 * Actually owned by the _Thread_Dispatch() wrapper.
 * This way the variable is available all the time.
 */
extern uint32_t Schedsim_Current_cpu;

#if RTEMS_SMP
  extern uint32_t Schedsim_Maximum_CPUs_From_Command_Line;
#endif

uint32_t _CPU_SMP_Initialize( void )
{
#if RTEMS_SMP
  /* return the number of CPUs */
  return Schedsim_Maximum_CPUs_From_Command_Line;
#else
  return 1;
#endif
}

bool _CPU_SMP_Start_processor( uint32_t cpu_index )
{
  return true;
}

void _CPU_SMP_Finalize_initialization( uint32_t cpu_count )
{
}

void _CPU_SMP_Send_interrupt( uint32_t target_processor_index )
{
}

void _CPU_SMP_Processor_event_broadcast( void )
{
#if RTEMS_SMP
  Per_CPU_Control  *cpu = _Per_CPU_Get();
  uint32_t         cpu_count = _SMP_Get_processor_count();
  uint32_t         cpu_index;
  Per_CPU_State    state = cpu->state;

  if (state == PER_CPU_STATE_REQUEST_START_MULTITASKING) {
    for ( cpu_index = 0 ; cpu_index < cpu_count ; ++cpu_index ) {
      cpu = _Per_CPU_Get_by_index( cpu_index );
      state = cpu->state;
      if (state == PER_CPU_STATE_INITIAL )
         cpu->state = PER_CPU_STATE_READY_TO_START_MULTITASKING;
    }
  }
#endif
}


void _CPU_SMP_Processor_event_receive( void )
{
}

uint32_t _CPU_SMP_Get_current_processor( void )
{
#if RTEMS_SMP
  return Schedsim_Current_cpu;
#else
  return 0;
#endif
}
