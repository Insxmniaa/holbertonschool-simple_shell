#include "main.h"

/**
 * main - makes a prompt and waits for command
 *
 * Return: exits the prompt
 *
 */

int main(void)
{
	char *buffer = NULL;
	char **args = NULL;
	ssize_t read;
	pid_t child;
	size_t size = 0;
	int status = 0;
	char *token;
	int i;

	args = malloc(MAX_ARGS * sizeof(char *));
	if (args == NULL)
	{
		perror("Failed allocating memory");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (isatty(0))
			printf("$ ");

		i = 0;
		read = getline(&buffer, &size, stdin);
		if (read == -1)
		{
			free(buffer);
			free(args);
			break;
		}

		if (read == 1 && buffer[0] == '\n')
			continue;

		buffer[read - 1] = '\0';

		token = strtok(buffer, " \t");
		if (token == NULL)
		{
			continue;
		}
		while (token != NULL && i < MAX_ARGS - 1)
		{
			args[i++] = token;
			token = strtok(NULL, " \t");
		}
		args[i] = NULL;

		if (strcmp(args[0], "exit") == 0)
		{
			free(buffer);
			free(args);
			break;
		}

		child = fork();
		if (child == -1)
		{
			perror("fork not successful");
			free(args);
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			char *path = get_command(args[0]);

			if (path != NULL)
			{
			if (access(path, X_OK) == 0)
			{
				execve(path, args, environ);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			}
			else
			{
				printf("%s: command not found\n", buffer);
				free(path);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (wait(&status) == -1)
			{
				perror("waitpid");
				exit(EXIT_SUCCESS);
			}
		}
	}
	return (0);
}
