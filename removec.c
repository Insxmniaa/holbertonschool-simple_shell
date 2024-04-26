#include "shell.h"

/**
 * removetrash - function to remove the newline character from user input
 * @str: user input
 * @len: lenght of the user input
 * 
 * Return: returns the command without a newline character
*/

char *removetrash(char *str, int len)
{
    if (str != 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';

    return (str);
}