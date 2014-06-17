#include <rtems.h>
#include <schedsim_shell.h>

shell_scheduler_name shell_scheduler_list[] = {
""
};

#define CONFIGURE_INIT
#define CONFIGURE_MAXIMUM_TASKS             1000
#define CONFIGURE_MAXIMUM_SEMAPHORES        1000

#define CONFIGURE_SCHEDULER_CBS
#define CONFIGURE_DISABLE_BSP_SETTINGS
#include <confdefs.h>
