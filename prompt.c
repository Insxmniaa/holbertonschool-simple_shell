#include "shell.h"

/**
 * receiveCommand - takes user input
 * 
 * Return: 0
*/

int receiveCommand(void)
{
    size_t n = 0;
    char *buff = NULL;
    int size = getline(&buff, &n, stdin); /*getline waits the user to enter something in terminal*/

    if (size == -1)
    {
        if (feof(stdin))
        {
            free(buff);
            exit(0);
        }

        else
        {
            perror("No user input");
            free(buff);
        }

    }
    return (size);
}