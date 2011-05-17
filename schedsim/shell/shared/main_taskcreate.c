/*
 *  Task Create Shell Command Implmentation
 *
 *  COPYRIGHT (c) 1989-2010.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>

#define __need_getopt_newlib
#include <newlib/getopt.h>

#include <rtems.h>
#include "shell.h"
#include <rtems/stringto.h>
#include <schedsim_shell.h>
#include <rtems/error.h>

static void print_mode(
  const char *prefix,
  rtems_mode  mode
)
{
  printf(
    "%sPreemption: %s Timeslicing: %s\n",
    prefix,
    ((mode & RTEMS_NO_PREEMPT) ? "no" : "yes"),
    ((mode & RTEMS_TIMESLICE) ? "yes" : "no")
  );
}

rtems_task dummy_task(
  rtems_task_argument arg
)
{
}

int rtems_shell_main_task_create(
  int   argc,
  char *argv[]
)
{
  char               name[5];
  rtems_id           id;
  rtems_status_code  status;
  long               priority;
  rtems_mode         mode;
  rtems_mode         mask;
  struct getopt_data getopt_reent;
  char               option;
  int                arg;
 
  CHECK_RTEMS_IS_UP();

  mode = 0;
  mask = 0;
  memset(&getopt_reent, 0, sizeof(getopt_data));
  while ( (option = getopt_r( argc, argv, "tTpP", &getopt_reent)) != -1 ) {
    switch (option) {
      case 't':
        mask |= RTEMS_TIMESLICE_MASK;
        mode  = (mode & ~RTEMS_TIMESLICE_MASK) | RTEMS_NO_TIMESLICE;
        break;
      case 'T':
        mask |= RTEMS_TIMESLICE_MASK;
        mode  = (mode & ~RTEMS_TIMESLICE_MASK) | RTEMS_TIMESLICE;
        break;
      case 'p':
        mask |= RTEMS_PREEMPT_MASK;
        mode  = (mode & ~RTEMS_PREEMPT_MASK) | RTEMS_NO_PREEMPT;
        break;
      case 'P':
        mask |= RTEMS_PREEMPT_MASK;
        mode  = (mode & ~RTEMS_PREEMPT_MASK) | RTEMS_PREEMPT;
        break;
      default:
        fprintf( stderr, "%s: Usage [-tTpP]\n", argv[0] );
        return -1;
    }
  }

  print_mode( "Creating task with:  ", mode );

  /*
   *  Rest of arguments
   */
  arg = getopt_reent.optind;
  if ((argc - arg) != 2) {
    fprintf( stderr, "%s: Usage [args] name priority\n", argv[0] );
    return -1;
  }

  if ( rtems_string_to_long(argv[arg+1], &priority, NULL, 0) ) {
    printf( "Seconds argument (%s) is not a number\n", argv[1] );
    return -1;
  }

  /*
   *  Now create the task
   */
  memset( name, '\0', sizeof(name) );
  strncpy( name, argv[arg], 4 );

  status = rtems_task_create(
    rtems_build_name( name[0], name[1], name[2], name[3] ),
    (rtems_task_priority) priority,
    RTEMS_MINIMUM_STACK_SIZE,
    mode,
    RTEMS_DEFAULT_ATTRIBUTES,
    &id
  );
  if ( status ) {
    fprintf(
      stderr,
      "Task Create(%s) returned %s\n",
      name,
      rtems_status_text( status )
    ); 
    return -1;
  }

  printf(
    "Task (%s) created: id=0x%08x, priority=%ld\n",
    name,
    id,
    priority
  );
  
  printf(
    "Task (%s) starting: id=0x%08x, priority=%ld\n",
    name,
    id,
    priority
  );

  status = rtems_task_start( id, dummy_task, 1 );
  if ( status ) {
    fprintf(
      stderr,
      "Task Start(%s) returned %s\n",
      name,
      rtems_status_text( status )
    ); 
    return -1;
  }

  return 0;
}

rtems_shell_cmd_t rtems_shell_TASK_CREATE_Command = {
  "task_create",                 /* name */
  "task_create name priority",   /* usage */
  "rtems",                       /* topic */
  rtems_shell_main_task_create,  /* command */
  NULL,                          /* alias */
  NULL                           /* next */
};
