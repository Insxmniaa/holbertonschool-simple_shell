#include "shell.h"

/**
 * main - entry point
 * 
 * Return: 0 
*/

int main(void)
{
    while(1)
    {
        printf("#cisfun$ ");
        receiveCommand();
    }
   

    return (0);
}