/*
 *  COPYRIGHT (c) 1989-2013.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#include <newlib/getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "shell.h"
#include "rtems_sched.h"
#include <rtems/score/chainimpl.h>
#include <rtems/score/thread.h>
#include <rtems/score/assert.h>

/*
 * Note: This source depends upon the scheduler being
 *       tested.
 */
#include <rtems/score/schedulersimplesmp.h>

int main_dump_ready_tasks(int argc, char **argv)
{
  Chain_Control  *chain;
  Chain_Node     *n;
  Thread_Control *t;

  Scheduler_simple_SMP_Context * self = 
    (Scheduler_simple_SMP_Context *) _Scheduler_Table[0].context;

  /* We don't support this yet */
  _Assert( _Scheduler_Count != 1 );

  printf( "=== Ready Set of Threads\n" );
  chain = &self->Ready;
  for (n = _Chain_First( chain ); !_Chain_Is_tail(chain, n); n = n->next) {
    t = (Thread_Control *)n;
    printf(
      "  0x%08x priority=%ld\n",
      t->Object.id,
      (long) t->current_priority
    );
  }
  printf( "=== End of Ready Set of Threads\n" );
  
  return 0;
}
