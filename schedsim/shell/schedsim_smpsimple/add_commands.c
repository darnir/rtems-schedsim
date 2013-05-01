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
#include <assert.h>

#include "shell.h"
#include "rtems_sched.h"

extern int main_dump_ready_tasks(int argc, char **argv);
extern int main_dump_all_cpus(int argc, char **argv);
extern int main_set_current_cpu(int argc, char **argv);
extern int main_dispatch(int argc, char **argv);

void add_commands(void)
{
  rtems_shell_cmd_t *cmd;

  cmd = rtems_shell_add_cmd(
    "ready_tasks",
    "rtems",
    "no args",
    main_dump_ready_tasks
  );
  assert( cmd );

  cmd = rtems_shell_add_cmd(
    "cpus",
    "rtems",
    "no args",
    main_dump_all_cpus
  );
  assert( cmd );

  cmd = rtems_shell_add_cmd(
    "current_cpu",
    "rtems",
    "number",
    main_set_current_cpu
  );
  assert( cmd );

  cmd = rtems_shell_add_cmd(
    "dispatch",
    "rtems",
    "",
    main_dispatch
  );
  assert( cmd );

}
