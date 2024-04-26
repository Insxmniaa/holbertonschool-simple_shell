#include "shell.h"

/**
 * executecommand - function to execute the user command
 * @argsC array of commands from the user
 * 
 * Return: O on success
*/

int executecommand(char *argsC[])
{
    pid_t pid;
    int execmd, status;

    pid = fork();

    if (pid == -1)
    {
            perror("Process creation failure");
    }
    else if (pid == 0)
    {
            execmd = execve(argsC[0], argsC, NULL);
            
            if (execmd == -1)
            {
                    perror("Error executing command");
            }

    }
    else 
        wait(&status);
    
    return (0);

}