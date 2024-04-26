#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAX_INPUT 1024
#define MAX_ARGS 100

void getinput();
void execute_command(char **args);
char **parse_input(char *input_line);


#endif