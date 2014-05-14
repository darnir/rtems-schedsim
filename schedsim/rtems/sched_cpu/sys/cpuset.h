/*
 *  On Linux, the cpu_set_t is defined here proteted with _GNU_SOURCE
 *  and it is defined in Makefile.am`
 */

#ifndef __SCHEDSIM_SYS_CPUSET_h
#define __SCHEDSIM_SYS_CPUSET_h

#include <sched.h>
#ifndef __CPU_ZERO_S
#error "__CPU_ZERO_S not defined - check configuration"
#endif

#if defined(__gnu_linux__)
/* This was not defined as of at least CentOS 6.x */
/* copy src set to dest set */
static __inline void CPU_COPY( cpu_set_t *dest, const cpu_set_t *src )
{
  *dest = *src;
}
#endif

#endif
