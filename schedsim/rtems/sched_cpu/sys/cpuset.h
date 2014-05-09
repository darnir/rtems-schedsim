/*
 *  On Linux, the cpu_set_t is defined here proteted with _GNU_SOURCE
 *  and it is defined in Makefile.am`
 */
#include <sched.h>
#ifndef __CPU_ZERO_S
#error "__CPU_ZERO_S not defined - check configuration"
#endif

