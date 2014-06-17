/**
 * @file
 *
 * Configuration file for Scheduler Simulator using Simple Priority SMP
 */

#include <rtems.h>
#include <schedsim_shell.h>

shell_scheduler_name shell_scheduler_list[] = {
""
};

#define CONFIGURE_INIT
#define CONFIGURE_MAXIMUM_TASKS             1000
#define CONFIGURE_MAXIMUM_SEMAPHORES        1000

#define CONFIGURE_SMP_APPLICATION
#define CONFIGURE_SMP_MAXIMUM_PROCESSORS 4
#define CONFIGURE_SCHEDULER_SIMPLE_SMP

#define CONFIGURE_DISABLE_BSP_SETTINGS
#include <rtems/confdefs.h>
