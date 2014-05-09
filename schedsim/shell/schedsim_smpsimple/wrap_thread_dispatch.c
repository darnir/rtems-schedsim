/*
 *  Thread Dispatch Wrapper Implmentation
 *
 *  COPYRIGHT (c) 1989-2013.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#include "shell.h"
#include <schedsim_shell.h>

#include <stdlib.h>
#include <stdio.h>
#include <rtems.h>

typedef Thread_Control * Thread_Control_ptr;
extern uint32_t Schedsim_Current_cpu;

Thread_Control_ptr *last_heir = NULL;
Thread_Control_ptr *last_executing = NULL;

extern void __real__Thread_Dispatch(void);

void Init__wrap__Thread_Dispatch()
{
  last_heir = (Thread_Control_ptr *) calloc(
    sizeof( Thread_Control_ptr ),
    _SMP_Processor_count
  );
  last_executing =  (Thread_Control_ptr *) calloc(
    sizeof( Thread_Control_ptr ),
    _SMP_Processor_count
  );
}

void check_heir_and_executing(void)
{
  uint32_t level;

  _ISR_Disable_without_giant( level );
    if ( last_heir[Schedsim_Current_cpu] != _Thread_Heir ) 
      PRINT_HEIR();

    if ( last_executing[Schedsim_Current_cpu] != _Thread_Executing )
      PRINT_EXECUTING();

    last_heir[Schedsim_Current_cpu] = _Thread_Heir;
    last_executing[Schedsim_Current_cpu] = _Thread_Executing;
  _ISR_Enable_without_giant( level );
}

void __wrap__Thread_Dispatch(void)
{
  uint32_t   cpu;
  uint32_t   current_cpu;

  current_cpu = Schedsim_Current_cpu;
  for ( cpu=0 ; cpu < _SMP_Processor_count ; cpu++ ) {
    Schedsim_Current_cpu = cpu;
    check_heir_and_executing();
    __real__Thread_Dispatch();
    check_heir_and_executing();
  }
  
  Schedsim_Current_cpu = current_cpu;
}

