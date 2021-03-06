/**
 * @file
 * @brief Given Name or ID String, give Id
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
#include <rtems/stringto.h>
#include <rtems/score/threaddispatch.h>
#include "schedsim_shell.h"

#ifndef METHOD_NAME
  #define METHOD_NAME lookup_task
#endif
#ifndef RTEMS_IDENT_NAME
  #define RTEMS_IDENT_NAME rtems_task_ident
  #define DOING_TASKS
#endif

int METHOD_NAME(
  const char *string,
  rtems_id   *id
)
{
  char               name[5];
  rtems_status_code  status;
  unsigned long      tmp;

  if ( string[0] != '0' ) {
    #ifdef DOING_TASKS
      if ( !strcmp( string, "SELF" ) ) {
        *id = get_thread_executing()->Object.id;
        return 0;
      }
    #endif
#if 0
    if ( strlen( string ) != 4 ) {
      return -1;
    }
#endif
    memset( name, '\0', sizeof(name) );
    strncpy( name, string, 4 );
    status = RTEMS_IDENT_NAME(
      rtems_build_name( name[0], name[1], name[2], name[3] ),
      OBJECTS_SEARCH_ALL_NODES,
      id
    );
    if ( status != RTEMS_SUCCESSFUL )
      return 1;
  } else {
    if ( rtems_string_to_unsigned_long( string, &tmp, NULL, 0) ) {
      fprintf( stderr, "Argument (%s) is not a number\n", string );
      return 1;
    }
    *id = (rtems_id) tmp;
  }

  return 0;
}
