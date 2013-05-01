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

/*
 *  Variables to control global behavior
 */
int verbose = 1;
const char *progname;
const char *scriptname;

FILE *Script;
int ScriptFileLine = 0;

/*
 *  Print program usage message
 */
void usage()
{
  fprintf(
    stderr,
    "Usage: %s [-v] script\n"
    "\n"
    "  -v           - enable verbose output\n",
    progname
  );
  exit( -1 );
}

#define RTEMS_SHELL_MAXIMUM_ARGUMENTS (128)

void ProcessScript(
  FILE *script
)
{
  char               buffer[512];
  char              *cStatus;
  char              *c;
  size_t             length;
  int                argc;
  char              *argv[RTEMS_SHELL_MAXIMUM_ARGUMENTS];
  rtems_shell_cmd_t *shell_cmd;
  
 
  while ( 1 ) {
    cStatus = fgets( buffer, sizeof(buffer), script );
    if ( cStatus == NULL )
      break;
    // If the last line does not have a CR, then we don't want to
    // arbitrarily clobber an = instead of a \n.
    length = strlen(buffer);
    if ( buffer[ length - 1] == '\n' )
      buffer[ length - 1] = '\0';

    if ( verbose )
      printf( "==> %d: %s\n", ++ScriptFileLine, buffer );

    if ( buffer[0] == '#' )
      continue;

    for ( c = buffer ; *c ; c++ ) {
      if (!isblank((int)*c))
        break;
    }


    if (!strcmp(c,"bye") || !strcmp(c,"exit")) {
      return;
    } 

    if (rtems_shell_make_args(c, &argc, argv, RTEMS_SHELL_MAXIMUM_ARGUMENTS)) {
      fprintf(stderr, "Error parsing arguments\n" );
      continue;
    }

    if ( argc == 0 )
      continue;

    shell_cmd = rtems_shell_lookup_cmd(argv[0]);
    if ( !shell_cmd ) {
      fprintf(stderr, "%s is unknown command\n", c );
      continue;
    }

    shell_cmd->command(argc, argv);
  }
}

extern "C" {
 void add_commands(void);
};

int main(
  int argc,
  char **argv
)
{
  int opt;
  progname = argv[0];
  
  while ((opt = getopt(argc, argv, "v")) != -1) {
    switch (opt) {
      case 'v': verbose = 0;                break;
      default: /* '?' */
        usage();
    }
  }

  if ( optind >= argc ) {
    scriptname = "-"; 
  } else {
    scriptname = argv[ optind ];
  }

  if ( !strcmp( scriptname, "-" ) ) {
    scriptname = "/dev/stdin";
  }

  if ( verbose ) {
    printf(
      "Script File               : %s\n"
      "verbose                   : %d\n",
      scriptname,
      verbose
    );
  }

  //
  //  Initialize the command interpreter
  //
  rtems_shell_initialize_command_set();
  add_commands();

  //
  //  Open the script file
  // 
  Script = fopen( scriptname, "r" );
  if ( !Script ) {
    fprintf( stderr, "Unable to open script file (%s)\n", scriptname );
    exit( -1 );
  }

  //
  //  Process the Script
  //
  ProcessScript( Script );

  //
  //  Open the script file
  // 
  (void) fclose( Script );

  //
  //  Just in case something throws
  //
  try {
  } catch (...) {
    exit(-1);
  }

  return 0;
}
