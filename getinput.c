#include "shell.h"

/**
 * 
 * 
*/

void getinput()
{
    char input_line[MAX_INPUT];
    char **arguments;

    if (fgets(input_line, MAX_INPUT, stdin) == NULL)
    {
            if (feof(stdin))
            {
                printf("\n");
                exit(0);
            }
            else 
            {
                perror("Error");
                exit(1);
            }
    }
    arguments = parse_input(input_line);
    if (arguments[0] != NULL)
    {
        execute_command(arguments);
    }

    free(arguments);
}