#include "shell.h"

/**
 * _cd - builtin command change directory
 * @av: argument
 * Return: Always returns 1.
 */

int _cd(char **av)
{
if (av[1] == NULL)
{
	perror("Expected argument\n");
}
else
{
	if (chdir(av[1]) != 0)
	{
		perror("MChsh");
	}
}
return (1);
}

/**
 * _help - builtin command help
 * @av: argument
 * Return: Always returns 1.
 */

int _help(char **av)
{
printf("Look at man file \n");
free(av);
return (1);
}

/**
 * newexit - Builtin command exit
 * @av: argument
 * Return: Always 0.
 */

int newexit(char **av)
{
free(av);
return (0);
}
