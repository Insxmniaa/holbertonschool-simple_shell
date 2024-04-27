#include "main.h"

/**
 * get_command - find the path to the command in the input given
 *
 * @cmd: is the args[0] in main function
 *
 * Return: full path if successful, NULL if failed
*/
char *get_command(char *cmd)
{
	static char *locations[] = {"/bin/", "/usr/bin/", NULL};
	int i;
	char *full_path;

	if (access(cmd, X_OK) == 0)
	{
		full_path = malloc(strlen(cmd) + 1);
		strcpy(full_path, cmd);
		return (full_path);
	}

	for (i = 0; locations[i] != NULL; i++)
	{
		full_path = malloc(strlen(locations[i]) + strlen(cmd) + 1);
		if (full_path == NULL)
		{
			perror("Failed allocating memory");
			exit(EXIT_FAILURE);
		}

		sprintf(full_path, "%s%s", locations[i], cmd);

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}

		free(full_path);
	}
	return (NULL);
}
