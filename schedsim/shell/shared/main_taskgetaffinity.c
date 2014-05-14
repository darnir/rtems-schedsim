/**
 *  @file
 *
 *  Task Get Affinity Shell Command Implmentation
 */

/*
 *  COPYRIGHT (c) 1989-2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define _GNU_SOURCE
#include <sys/cpuset.h>

#include <stdio.h>

#include <rtems.h>
#include "shell.h"
#include <rtems/stringto.h>
#include <schedsim_shell.h>
#include <rtems/error.h>

int rtems_shell_main_task_get_affinity(
  int   argc,
  char *argv[]
)
{
  rtems_id             id;
  rtems_status_code    status;
  unsigned long        tmp;
  cpu_set_t            cpuset;

  CHECK_RTEMS_IS_UP();

  if (argc != 2) {
    fprintf( stderr, "%s: Usage [name|id]\n", argv[0] );
    return -1;
  }

  if ( lookup_task( argv[1], &id ) )
    return -1;

  CPU_ZERO( &cpuset );
  cpuset.__bits[0] = tmp;

  /*
   *  Now obtain the affinity the task
   */
  status = rtems_task_get_affinity( id, sizeof(cpuset), &cpuset );
  if ( status != RTEMS_SUCCESSFUL ) {
    fprintf(
      stderr,
      "Task Get Affinity(%s) returned %s\n",
      argv[1],
      rtems_status_text( status )
    );
    return -1;
  }

  printf("Task (0x%08x) Get affinity=0x%08x\n", id, cpuset.__bits[0] );

  return 0;
}

rtems_shell_cmd_t rtems_shell_TASK_GET_AFFINITY_Command = {
  "task_get_affinity",                 /* name */
  "task_get_affinity name ",           /* usage */
  "rtems",                             /* topic */
  rtems_shell_main_task_get_affinity,  /* command */
  NULL,                                /* alias */
  NULL                                 /* next */
};
