#include "shell.h"

/**
 * getinput - takes user input
 * 
 * Return: 0
*/

int getinput(void)
{
    size_t n = 0;
    char *buff = NULL, *command, *argsC[MAX_ARG];
    int size; 
    
    size = getline(&buff, &n, stdin); /*getline waits the user to enter something in terminal*/
    if (size == -1)
    {
            if (feof(stdin))
            {
                free(buff);
                exit(0);
            }
            else
            {
                printf("Failed to read user input");
                free(buff);
            }
    }

    command = removetrash(buff, size);
    tokenize(command, argsC);

    executecommand(argsC);

    free(buff);
    return (size);
}
