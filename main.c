#include "shell.h"

/**
 * main - entry point 
 * 
 * Return: 0
 */

int main()
{
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;
    int status;
    
    while (1) 
    {
        print_prompt();  /*Display prompt*/
        if (fgets(command, sizeof(command), stdin) == NULL) 
        {
            if (feof(stdin)) 
            {
                printf("\nExiting shell...\n");
                break;  /*Handle end of file (Ctrl+D)*/
            }
            perror("Error reading command");
            continue;
        }
        command[strcspn(command, "\n")] = '\0';  /*Remove newline character*/
        
        pid = fork();  /*Create a child process*/
        if (pid < 0) 
        {
            perror("Fork failed");
            continue;
        } 
        else if (pid == 0) 
        {  /*Child process*/
            execlp(command, command, NULL);  /*Execute the command*/
            perror("Command not found");
            exit(1);
        } 
        else 
        {  /*Parent process*/
            waitpid(pid, &status, 0);  /*Wait for child process to finish*/
            
            if (WIFEXITED(status) && WEXITSTATUS(status) != 0) 
            {
                printf("Command '%s' failed\n", command);
            }
        }
    }
    return 0;
}