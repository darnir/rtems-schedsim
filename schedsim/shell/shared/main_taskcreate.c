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
  char              *c_p;
  char               name[5];
  rtems_id           id;
  rtems_status_code  status;
  long               priority;
  rtems_mode         mode;
  rtems_mode         mask;
  struct getopt_data getopt_reent;
  char               option;
  int                arg;
  unsigned long      affinity;
#if defined(RTEMS_SMP)
  cpu_set_t          cpuset;
  bool               do_affinity = false;
#endif

  CHECK_RTEMS_IS_UP();

  mode = 0;
  mask = 0;
  memset(&getopt_reent, 0, sizeof(getopt_data));
  while ( (option = getopt_r( argc, argv, "a:tTpP", &getopt_reent)) != -1 ) {
    switch (option) {
      case 'a':
#if defined(RTEMS_SMP)
        c_p = getopt_reent.optarg;
        if ( rtems_string_to_unsigned_long( c_p, &affinity, NULL, 0) ) {
          fprintf( stderr, "Affinity (%s) is not a number\n", argv[2] );
          return 1;
        }
        do_affinity = true;

	CPU_ZERO( &cpuset );
	cpuset.__bits[0] = affinity;
#else
        printf( "Ignoring affinity request on uniprocessor\n" );
#endif
        break;

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
        fprintf( stderr, "%s: Usage [-a:tTpP]\n", argv[0] );
        return -1;
    }
  }

  print_mode( "Creating task with:  ", mode );

  /*
   *  Rest of arguments
   */
  arg = getopt_reent.optind;
  if ( ((argc - arg) != 2) && ((argc - arg) != 4) ){
    fprintf( stderr, "%s: Usage [args] name priority -a affinity\n", argv[0] );
    return -1;
  }

  if ( rtems_string_to_long(argv[arg+1], &priority, NULL, 0) ) {
    printf( "Priority argument (%s) is not a number\n", argv[1] );
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

#if defined(RTEMS_SMP)
  /*
   * If specified, set the affinity
   */
  if ( do_affinity ) {
    status = rtems_task_set_affinity( id, sizeof(cpuset), &cpuset );
    if ( status != RTEMS_SUCCESSFUL ) {
      fprintf(
	stderr,
	"Task Set Affinity(0x%08x) returned %s\n"
        "Deleting task 0x%08x\n",
	affinity,
	rtems_status_text( status ),
        id
      );
      rtems_task_delete( id );
      return -1;
    }
    printf("Task (0x%08x) Set affinity=0x%08x\n", id, cpuset.__bits[0] );
  }
#endif

  /*
   * Starting the task
   */
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
