#include "shell.h"

/**
 * tokenize - function to help tokenize user input
 * @command: command received from user
 * @argsC: storage tokens
 * 
 * Return: number of tokens
*/

int tokenize(char *command, char *argsC[])
{
        char *delim = " ", *token;
        int count = 0;

        token = strtok(command, delim);

        while (token)
        {
                printf("%s", token);
                argsC[count++] = token;
                token = strtok(NULL, delim);
        }
        argsC[count] = NULL;
        
        return (count);
}
