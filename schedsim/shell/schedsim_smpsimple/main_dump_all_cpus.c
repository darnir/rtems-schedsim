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

// #define __RTEMS_VIOLATE_KERNEL_VISIBILITY__
#include <rtems.h>
#include <rtems/bspsmp.h>
#include <rtems/score/percpu.h>
#include <rtems/score/smp.h>
#include <rtems/score/schedulerpriority.h>

int main_dump_all_cpus(int argc, char **argv)
{
  uint32_t        cpu;
  Thread_Control *h;
  Thread_Control *i;
  Thread_Control *e;

  printf(
    "=== CPU Status\n"
    "            EXECUTING    /     HEIR         /    IDLE        / "
      " SWITCH NEEDED\n"
  );
  for ( cpu=0 ; cpu < _SMP_Processor_count ; cpu++ ) {
    e = _Per_CPU_Information[cpu].per_cpu.executing;
    h = _Per_CPU_Information[cpu].per_cpu.heir;
    printf(
      "  CPU %d: 0x%08x @%3ld / 0x%08x @%3ld          %s\n",
      cpu,
      e->Object.id, (long) e->current_priority,
      h->Object.id, (long) h->current_priority,
      ((_Per_CPU_Information[cpu].per_cpu.dispatch_necessary) ?
         "true" : "false")
    );
  }
  printf( "=== End of Ready Set of Threads\n" );
  
  return 0;
}
