#include "shell.h"
#define MAX_PATH_LENGTH 1024
#define MAX_CMD_LENGTH 256

/**
 *
 *cmd_exists = function to check if a command exists in a directory
 *exc_command = function to exectute command if it exists
 *
 */

int cmd_exists(const char * cmd, const char *directory, char *path)
{
	{
		char full_path[MAX_PATH_LENGTH];
		snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", directory, cmd);
		return access(full_path, F_OK) == 0;
	}

void exc_command(const char *cmd)
	{
		char *path = getenv("PATH");
		if(!path)
		fprintf(stderr, "PATH enviroment variable not found|\n");
		exit(1);
	}

	char *dir = strtok(path, ":");
	while (dir != NULL)
	{
	if (cmd_exists(cmd, dir, path))
	{
		pid_t pid = fork();
		if (pid == -1)
			{
				perror("fork");
				exit(1);
			}
		else if (pid == 0)
		{
			execlp(cmd, cmd, NULL);
			perror("execlp");
			exit(1);
		}
		else
		{
			wait(NULL);
			exit(0);
		}
	}
	dir = strtok(NULL, ":");
}
	fprintf(stderr,"%s: command not found\n", cmd);
	exit(1);
}
