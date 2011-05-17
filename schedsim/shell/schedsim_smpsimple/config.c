/*
 *  $Id$
 */

#include <rtems.h>

#define CONFIGURE_INIT
#define CONFIGURE_MAXIMUM_TASKS             1000
#define CONFIGURE_MAXIMUM_SEMAPHORES        1000

#define CONFIGURE_SMP_APPLICATION
#define CONFIGURE_SMP_MAXIMUM_PROCESSORS 4

#include <rtems/confdefs.h>

