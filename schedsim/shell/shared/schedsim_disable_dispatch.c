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

#include <rtems.h>

#include "shell.h"
#include <schedsim_shell.h>
#include <rtems/score/threadimpl.h>

static bool  allow_dispatch = true;

void schedsim_set_allow_dispatch(bool value)
{
  bool old = allow_dispatch;

  allow_dispatch = value;
  if ( value == true && old != value )
    _Thread_Dispatch();
}

bool schedsim_is_dispatch_allowed(void)
{
  return allow_dispatch;
}
