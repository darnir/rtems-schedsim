/*
 *  RTEMS SMP Support for Single Core
 *
 *  COPYRIGHT (c) 1989-2013.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#include <rtems.h>
#include <rtems/bspIo.h>
#include <stdlib.h>

uint32_t _CPU_SMP_Initialize( void )
{
  /* return the number of CPUs */
  return 1; /* XXX */
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
}

void _CPU_SMP_Processor_event_receive( void )
{
}

uint32_t _CPU_SMP_Get_current_processor( void )
{
  return 0;
}
