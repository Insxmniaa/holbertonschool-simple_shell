#ifndef MAIN_H 
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>

#define MAX_ARGS 64

char* get_command(char *cmd);

extern char **environ;


#endif
