/**
 *  @file
 *  @brief Get Thread Heir Helper
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

#include "shell.h"
#include <schedsim_shell.h>
#include <rtems/score/threaddispatch.h>

Thread_Control *get_thread_heir(void)
{
  Thread_Control *e;

  _Thread_Disable_dispatch();
    e = _Thread_Heir;
  _Thread_Enable_dispatch();
  return e;
}
