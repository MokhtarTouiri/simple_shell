#include "shell.h"

/**
 * main - the main shell program
 * @ac: number of arguments
 * @av: Strings containing arguments
 * Return: 0 on success code error if failure.
 */

int main(__attribute__ ((unused)) int ac, char **av)
{
char *line = NULL;
int status =1;

do {
printf("MChsh$ ");

line = read_line();
av = split_line(line);
status = execute(av);

free(line);
if (strcmp(av[0], "exit") != 0)
{
	free(av);
}
} while (status);

return (EXIT_SUCCESS);
}
