#include "shell.h"

/**
 * 
 * 
*/

char **parse_input(char *input_line)
{
    int bufsize = MAX_ARGS;
    int position = 0;
    char **tokens = malloc(bufsize *sizeof(char *));
    char *token;

    if (!tokens) 
    {
            fprintf(stderr, "Allocation error\n");
            exit(EXIT_FAILURE);
    }

    token = strtok(input_line, " \t\r\n\a");
    while (token != NULL)
    {
        tokens[position++] = token;

        if (position >= bufsize)
        {
            bufsize += MAX_ARGS;
            tokens = realloc(tokens, bufsize * sizeof(char *));

            if (!tokens)
            {
                    fprintf(stderr, "Allocation error\n");
                    exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, "\t\r\n\a");
    }

    tokens[position] = NULL;
    return tokens;
}