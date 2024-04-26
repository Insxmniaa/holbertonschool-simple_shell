#include "shell.h"
#define MAX_PATH_LENGTH 1024
#define MAX_CMD_LENGTH 256

/**
 *
 *cmd_exists = function to check if a command exists in a directory
 *exc_command = function to exectute command if it exists
 *cmd = the command to execute
 */
int cmd_exists(const char *cmd, const char *directory)
{
    char full_path[MAX_PATH_LENGTH];
    snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", directory, cmd);
    return access(full_path, F_OK) == 0;
}

void exc_command(const char *cmd)
{
    char *path = getenv("PATH");

    if (!path)
    {
        fprintf(stderr, "PATH environment variable not found\n");
        exit(1);
    }

    char *token;
    char *path_copy = strdup(path);
    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        if (cmd_exists(cmd, token))
        {
            pid_t pid = fork();
            if (pid == -1)
            {
                perror("fork");
                exit(1);
            }
            else if (pid == 0)
            {
                char full_path[MAX_PATH_LENGTH];
                snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", token, cmd);
                execlp(full_path, cmd, NULL);
                perror("execlp");
                exit(1);
            }
            else
            {
                wait(NULL);
                return;
            }
        }
        token = strtok(NULL, ":");
    }

    fprintf(stderr, "%s: command not found\n", cmd);
    exit(1);
}
