<<<<<<< HEAD
#ifndef SHELL_H_
#define SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main();
void print_prompt();





#endif
=======
#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

char *_getenv(const char *name);
void getinput();
void execute_command(char **args);
char **parse_input(char *input_line);
void env(char **arv);
void _setenv(char **arv);
void _unsetenv(char **arv);
char *_getenv(const char *name);
void(*checkbuild(char **arv))(char **arv);



#endif
>>>>>>> refs/remotes/origin/main
