#include "shell.h"

/**
 * 
 * 
 *
*/

void execute_command(char **args)
{
    pid_t pid, parentpid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("fork");
    }
    else 
    {
        do
        {
          parentpid = waitpid(pid, &status, WUNTRACED);

          if (parentpid == pid)
          {
            printf("Process %d terminated\n", parentpid);
          }
        }
        while (!WIFEXITED(status) && !WIFSIGNALED(status));
        
    }
}