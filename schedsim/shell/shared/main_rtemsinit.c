/*
 *  Initialize RTEMS Shell Command Implmentation
 *
 *  COPYRIGHT (c) 1989-2013.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>

#include <rtems.h>
#include "shell.h"
#include <schedsim_shell.h>
#include <rtems/stringto.h>

#if defined(RTEMS_SMP)
  #include <rtems/score/smp.h>

  uint32_t Schedsim_Maximum_CPUs_From_Command_Line;
#endif


int rtems_shell_main_rtems_init(
  int   argc,
  char *argv[]
)
{
  int i;

#if defined(RTEMS_SMP)
  long cpus = 1;

  if ( argc >= 2 ) {
    if ( rtems_string_to_long(argv[1], &cpus, NULL, 0) ) {
      printf( "Number of CPUs argument (%s) is not a number\n", argv[1] );
      return -1;
    }
  }
  Schedsim_Maximum_CPUs_From_Command_Line = cpus;
#endif

  for (i=0; strcmp("", shell_scheduler_list[i]) != 0; i++)
  {
    printf("Scheduler %d: %s\n", i, shell_scheduler_list[i]);
  }

  //
  // Initialize RTEMS
  //
  rtems_initialize_data_structures();
  return 0;
}

rtems_shell_cmd_t rtems_shell_RTEMS_INIT_Command = {
  "rtems_init",                 /* name */
  "rtems_init [cpus]",          /* usage */
  "rtems",                      /* topic */
  rtems_shell_main_rtems_init,  /* command */
  NULL,                         /* alias */
  NULL                          /* next */
};
