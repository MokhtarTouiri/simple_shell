#include "shell.h"

/**
 * main - the main shell program
 * @ac: number of arguments
 * @av: Strings containing arguments
 * Return: 0 on success code error if failure.
 */

int main(int ac, char **av)
{
char *line;
int status = ac;

do {
write(STDOUT_FILENO, "MChsh>", 6);
line = read_line();
av = split_line(line);
status = execute(av);
free(line);
free(av);
} while (status);

return (0);
}
