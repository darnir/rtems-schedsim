/**
 *  @file
 *
 *  @brief Thread Dispatch Wrapper Implmentation
 */

/*
 *  COPYRIGHT (c) 1989-2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#include "shell.h"
#include <schedsim_shell.h>

#include <stdio.h>
#include <rtems.h>

Thread_Control *last_heir = NULL;
Thread_Control *last_executing = NULL;

extern void __real__Thread_Dispatch(void);

void Init__wrap__Thread_Dispatch()
{
}

void check_heir_and_executing(void)
{
  uint32_t level;

  _ISR_Disable_without_giant( level );
    if ( last_heir != _Thread_Heir )
      PRINT_HEIR();

    if ( last_executing != _Thread_Executing )
      PRINT_EXECUTING();

    last_heir = _Thread_Heir;
    last_executing = _Thread_Executing;
  _ISR_Enable_without_giant( level );
}

void __wrap__Thread_Dispatch(void)
{
  if ( schedsim_is_dispatch_allowed() == false )
    return;

  check_heir_and_executing();
    __real__Thread_Dispatch();
  check_heir_and_executing();
}
