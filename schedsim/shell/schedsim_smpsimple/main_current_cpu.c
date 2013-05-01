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
#include <rtems/bspsmp.h>
#include <rtems/score/percpu.h>
#include <rtems/score/schedulerpriority.h>

extern uint32_t Schedsim_Current_cpu;

int main_set_current_cpu(int argc, char **argv)
{
  long cpu;

  if ( argc >= 2 ) {
    if ( rtems_string_to_long(argv[1], &cpu, NULL, 0) ) {
      printf( "CPU argument (%s) is not a number\n", argv[1] );
      return -1;
    }
    printf(
      "Changing current CPU from %d to %d\n",
      Schedsim_Current_cpu,
      cpu
    );
    Schedsim_Current_cpu = cpu;
  } else {
    printf( "Current CPU is %d\n", Schedsim_Current_cpu );
  }

  return 0;
}
