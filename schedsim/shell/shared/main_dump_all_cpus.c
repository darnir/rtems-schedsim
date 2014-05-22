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
#include "schedsim_shell.h"

#include <rtems.h>
#include <rtems/score/percpu.h>
#include <rtems/score/smp.h>
#include <rtems/score/schedulerpriority.h>

int main_dump_all_cpus(int argc, char **argv)
{
  uint32_t        cpu;
  Thread_Control *h;
  Thread_Control *i;
  Thread_Control *e;
  rtems_id        id;
  bool            mismatch;

  printf(
    "=== CPU Status\n"
    "          EXECUTING      /   HEIR             / SWITCH NEEDED\n"
  );
  for ( cpu=0 ; cpu < rtems_get_processor_count() ; cpu++ ) {
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

  /*
   * If no arguments, then we were not requested to verify task placement.
   */
  if ( argc == 1 )
    return 0;

  /*
   * Now verify the thread on each processor. 
   */
  mismatch = false;
  for ( cpu=0 ; cpu < rtems_get_processor_count() && cpu < argc ; cpu++ ) {
    e = _Per_CPU_Information[cpu].per_cpu.executing;

    if ( argv[cpu + 1][ 0 ] == '-' )
      continue;

    if ( lookup_task( argv[cpu + 1], &id ) )
      return -1;

    if ( !strcmp( argv[cpu + 1], "IDLE" )) {
      /* XXX should do something cleaner for the ID mask */
      if ( (e->Object.id & 0xFFFF0000) != 0x09010000 ) {
        mismatch = true;
        printf(
          "*** ERROR on CPU %d Expected an IDLE found 0x%08x executing\n",
          cpu,
          e->Object.id
        );
      }
    } else {
      if ( lookup_task( argv[cpu + 1], &id ) ) {
        printf(
          "*** ERROR in scenario -- unknown task %s\n",
           argv[cpu + 1]
        );
        exit( 1 );
      }

      if ( e->Object.id != id ) {
        mismatch = true;
        printf(
          "*** ERROR on CPU %d Expected 0x%08x found 0x%08x executing\n",
          cpu,
          id,
          e->Object.id
        );
      }
    }
  }
  if ( mismatch ) {
    printf( "Exiting test scenario due to scheduling failure\n" );
    exit( 1 );
  }

  return 0;
}

rtems_shell_cmd_t rtems_shell_CPUS_Command = {
  "cpus",                           /* name */
  "cpus [tasks expected on cores]", /* usage */
  "rtems",                          /* topic */
  main_dump_all_cpus,              /* command */
  NULL,                             /* alias */
  NULL                              /* next */
};
