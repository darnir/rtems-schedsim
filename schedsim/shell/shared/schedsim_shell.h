/**
 *  @file
 *  @brief Scheduler Simulator Internals
 *
 *  @note BASED UPON SOURCE IN RTEMS, MODIFIED FOR SIMULATOR
 */

/*
 *  COPYRIGHT (c) 1989-2014.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 */

#ifndef __SCHEDSIM_SHELL_h
#define __SCHEDSIM_SHELL_h

#include <rtems.h>
#include <rtems/score/sysstate.h>
#include "shell.h"

#ifdef __cplusplus
extern "C" {
#endif

Thread_Control *get_thread_executing(void);
Thread_Control *get_thread_heir(void);

void add_commands(void);

#define CHECK_RTEMS_IS_UP() \
  do { \
    if ( _System_state_Current != SYSTEM_STATE_UP ) { \
      fprintf( stderr, "RTEMS is not initialized yet\n" ); \
      return -1; \
    } \
  } while (0)

void PRINT_EXECUTING(void);
void PRINT_HEIR(void);

void schedsim_set_allow_dispatch(bool value);
bool schedsim_is_dispatch_allowed(void);

struct rtems_shell_topic_tt;
typedef struct rtems_shell_topic_tt rtems_shell_topic_t;

struct rtems_shell_topic_tt {
  const char          *topic;
  rtems_shell_topic_t *next;
};

extern rtems_shell_cmd_t   * rtems_shell_first_cmd;
extern rtems_shell_topic_t * rtems_shell_first_topic;

rtems_shell_topic_t * rtems_shell_lookup_topic(const char *topic);

extern rtems_shell_cmd_t *rtems_shell_Initial_commands[];
extern rtems_shell_alias_t *rtems_shell_Initial_aliases[];

int lookup_task(
  const char *string,
  rtems_id   *id
);

int lookup_semaphore(
  const char *string,
  rtems_id   *id
);

#ifdef __cplusplus
}
#endif

#endif
