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
#include <rtems/bspsmp.h>
#include <stdlib.h>

uint32_t Schedsim_Current_cpu;
extern uint32_t Schedsim_Maximum_CPUs_From_Command_Line;

void bsp_smp_secondary_cpu_initialize(int cpu)
{
  Schedsim_Current_cpu = 0;
}

int bsp_smp_processor_id(void)
{
  return Schedsim_Current_cpu;
}

uint32_t bsp_smp_initialize(
  uint32_t configured_cpu_count
)
{
  if ( configured_cpu_count < Schedsim_Maximum_CPUs_From_Command_Line ) {
    printf(
      "ERROR - Maximum cores per confdefs.h is %d\n",
      configured_cpu_count
    );
    exit( 1 );
  }

  /* return the number of CPUs */
  return Schedsim_Maximum_CPUs_From_Command_Line;
}

void bsp_smp_broadcast_interrupt(void)
{
}

void bsp_smp_broadcast_message(
  uint32_t  message
)
{
}

void bsp_smp_interrupt_cpu(
  int cpu
)
{
}

void bsp_smp_delay( int max )
{
}

void bsp_smp_wait_for(
  volatile unsigned int *address,
  unsigned int           desired,
  int                    maximum_usecs
)
{
  int iterations;
  volatile int i;
  volatile unsigned int *p = address;

  for (iterations=0 ;  iterations < maximum_usecs ; iterations++ ) {
    *p = desired;
    /* XXX hack to make simulator happy */
  }
}

