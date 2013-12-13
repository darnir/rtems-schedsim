/**
 *  @file
 *
 *  BASED UPON SOURCE IN RTEMS, MODIFIED FOR SIMULATOR
 *
 *  Every method in this file is stubbed. There are no real
 *  context switches or interrupts.
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

#include <rtems/system.h>
#include <rtems/score/cpu.h>

void _CPU_Context_save_fp(
  Context_Control_fp **fp_context_ptr
)
{
}

void _CPU_Context_restore_fp(
  Context_Control_fp **fp_context_ptr
)
{
}

void _CPU_Context_switch(
  Context_Control  *run,
  Context_Control  *heir
)
{
}

void _CPU_Context_restore(
  Context_Control *new_context
)
{
}

void _ISR_Handler(void)
{
}
