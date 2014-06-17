/*
 *  Task Create Shell Command Implmentation
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

#if defined(RTEMS_SMP)
#define _GNU_SOURCE
#include <sys/cpuset.h>
#endif

#include <stdio.h>

#define __need_getopt_newlib
#include <newlib/getopt.h>

#include <rtems.h>
#include "shell.h"
#include <rtems/stringto.h>
#include <schedsim_shell.h>
#include <rtems/error.h>

int rtems_shell_main_task_set_scheduler(
  int   argc,
  char *argv[]
)
{
  rtems_id           task_id;
  rtems_id           scheduler_id;
  rtems_status_code  status;
  rtems_name         name;
  long               sched;
  bool               ok = true;

  CHECK_RTEMS_IS_UP();

  if (strcmp("", shell_scheduler_list[0]) == 0)
  {
    fprintf(stderr, "Cluster Scheduling not configured\n");
    return -1;
  }

  if (argc != 3)
    ok = false;

  if ( lookup_task( argv[1], &task_id ) )
    ok = false;

  if (!ok)
  {
    fprintf( stderr, "%s: Usage [task name|id]  [sheduler number] \n", argv[0] );
    return -1;
  }

  if ( rtems_string_to_long(argv[2], &sched, NULL, 0) ) {
    fprintf( stderr, "Schedule argument (%s) is not a number\n", argv[2] );
    return -1;
  }

  name = SCHED_NAME(sched);

  status = rtems_scheduler_ident( name, &scheduler_id );
  if ( status != RTEMS_SUCCESSFUL ) {
    fprintf(
      stderr,
      "Task scheduler id (%d) returned %s\n",
      sched,
      rtems_status_text( status )
    );
    return -1;
  }

  printf("Task (0x%08x) on %s\n", task_id, shell_scheduler_list[sched] );

  status = rtems_task_set_scheduler(task_id, scheduler_id );
  if ( status != RTEMS_SUCCESSFUL ) {
    fprintf(
      stderr,
      "Task set scheduler(%s) returned %s\n",
      argv[1],
      rtems_status_text( status )
    );
    return -1;
  }

  return 0;
}

rtems_shell_cmd_t rtems_shell_TASK_SET_SCHEDULER_Command = {
  "task_set_scheduler",                 /* name */
  "task_set_scheduler task_name scheduler_name",   /* usage */
  "rtems",                       /* topic */
  rtems_shell_main_task_set_scheduler,  /* command */
  NULL,                          /* alias */
  NULL                           /* next */
};
