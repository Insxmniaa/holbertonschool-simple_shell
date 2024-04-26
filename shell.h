#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define MAX_ARG 25

int main(void);
int getinput(void);
char *removetrash(char *str, int len);
int tokenize(char *command, char *argsC[]);
int executecommand(char *argsC[]);




#endif