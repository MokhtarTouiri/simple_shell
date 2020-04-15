#include "shell.h"

/**
 * new_exit - Builtin command exit
 *
 * Return: Always 0.
 */

int new_exit(void)
{
	exit(EXIT_SUCCESS);
}



/**
 * new_env - Builtin command env
 *
 * Return: Return 1 if success.
 */

int new_env(void)
{
int c = 0;
while (environ[c])
{
	write(STDOUT_FILENO, environ[c], _strlen(environ[c]));
	write(STDOUT_FILENO, "\n", 1);
	c++;
}

return (1);
}
