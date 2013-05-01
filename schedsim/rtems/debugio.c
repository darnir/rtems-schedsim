/*
 *
 */

#include <rtems.h>
#include <rtems/bspIo.h>

#include <stdio.h>

void BSP_output_char_f(char c)
{
  putchar( c );
}

BSP_output_char_function_type           BSP_output_char = BSP_output_char_f;
BSP_polling_getchar_function_type       BSP_poll_char = NULL;

