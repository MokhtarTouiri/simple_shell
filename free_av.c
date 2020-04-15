#include "shell.h"

/**
 *free_av - Free arguments
 *@av: arguments of a program
 *Return: Void
 */

void free_av(char **av)
{
int c = 0;
if (av == NULL)
return;

while (av[c])
{
	free(av[c]);
	av[c] = NULL;
	c++;
	}
	free(av);
	av = NULL;
}
