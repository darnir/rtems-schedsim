#include <rtems.h>

#define CONFIGURE_INIT
#define CONFIGURE_MAXIMUM_TASKS             1000
#define CONFIGURE_MAXIMUM_SEMAPHORES        1000

#define CONFIGURE_DISABLE_BSP_SETTINGS
#include <confdefs.h>

