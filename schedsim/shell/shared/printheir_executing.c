/**
 * @file
 * @brief print heir and executing support
 */

/*
 *  COPYRIGHT (c) 1989-2013.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#include <stdio.h>
#include <rtems.h>

#if RTEMS_SMP
  extern uint32_t Schedsim_Current_cpu;
  #define MY_CPU Schedsim_Current_cpu
#else
  #define MY_CPU 0
#endif

void PRINT_EXECUTING() {
  printf(
    "  CPU %d: Thread Executing: 0x%08x priority=%ld\n",
    MY_CPU,
    _Thread_Executing->Object.id,
    (long) _Thread_Executing->current_priority
  );
}

void PRINT_HEIR() {
  printf(
    "  CPU %d: Thread Heir: 0x%08x priority=%ld\n",
    MY_CPU,
    _Thread_Heir->Object.id,
    (long) _Thread_Heir->current_priority
  );
}
