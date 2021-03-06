/**
 *  @file
 *  @brief Task Delete Shell Command Implmentation
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

#include <stdio.h>

#include <rtems.h>
#include "shell.h"
#include <rtems/stringto.h>
#include <schedsim_shell.h>
#include <rtems/error.h>

int rtems_shell_main_semaphore_delete(
  int   argc,
  char *argv[]
)
{
  rtems_id           id;
  rtems_status_code  status;

  CHECK_RTEMS_IS_UP();

  if (argc != 2) {
    fprintf( stderr, "%s: Usage [name|id]\n", argv[0] );
    return -1;
  }

  if ( lookup_semaphore( argv[1], &id ) )
    return -1;

  /*
   *  Now delete the semaphore
   */
  printf("Deleting semaphore (0x%08x)\n", id );

  /*
   * This wraps the allocator mutex and should defer any context switching
   */
  schedsim_set_allow_dispatch(false);
    status = rtems_semaphore_delete( id );
  schedsim_set_allow_dispatch(true);

  if ( status != RTEMS_SUCCESSFUL ) {
    fprintf(
      stderr,
      "Semaphore Delete(%s) returned %s\n",
      argv[1],
      rtems_status_text( status )
    );
    return -1;
  }

  return 0;
}

rtems_shell_cmd_t rtems_shell_SEMAPHORE_DELETE_Command = {
  "semaphore_delete",                 /* name */
  "semaphore_delete name priority",   /* usage */
  "rtems",                            /* topic */
  rtems_shell_main_semaphore_delete,  /* command */
  NULL,                               /* alias */
  NULL                                /* next */
};
