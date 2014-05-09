/*
 *  COPYRIGHT (c) 1989-2013.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#include <newlib/getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "shell.h"
#include "rtems_sched.h"

#include <rtems.h>
#include <rtems/score/percpu.h>
#include <rtems/score/smp.h>
#include <rtems/score/schedulersimplesmp.h>

extern uint32_t Schedsim_Current_cpu;

int main_dispatch(int argc, char **argv)
{
  uint32_t   cpu;
  uint32_t   current_cpu;

  current_cpu = Schedsim_Current_cpu;
  for ( cpu=0 ; cpu < _SMP_Processor_count ; cpu++ ) {
    if ( _Per_CPU_Information[cpu].per_cpu.dispatch_necessary ) {
      printf( "=== Invoke Thread Dispatch on CPU %d\n", cpu );
       Schedsim_Current_cpu = cpu;
      _Thread_Dispatch();
    }
  }
  
  Schedsim_Current_cpu = current_cpu;
  return 0;
}
