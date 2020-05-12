#include "shell.h"

/**
 * new_exit - Builtin command exit
 * @av: arguments.
 * Return: Always 0.
 */

int new_exit(char **av)
{
int code = 0;
if (av[1] != NULL)
	code = _atoi(av[1]);
exit(code);
}


/**
 * new_env - Builtin command env
 *
 * Return: Return 1 if success.
 */

void new_env(void)
{
int c = 0;
while (environ[c])
{
	write(STDOUT_FILENO, environ[c], _strlen(environ[c]));
	write(STDOUT_FILENO, "\n", 1);
	c++;
}
}

