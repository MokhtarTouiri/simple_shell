/**
 * main - the main shell program
 * @ac: Number of command line args
 * @av: Arguments
 * @ev: Environment vars
 * Return: noting
 */

void main(int ac, char **av, char **ev)
{
sev_t sev;

initialize_shell_env(&sev, av, ev);

while (1)
{
	write(STDOUT_FILENO, "hsh$ ", 4);
	getcommand(&sev);
	check_alias(&sev);
	if (!check_builtin(&sev))
	action(&sev);
	display_error(&sev);
}
clean_sev(&sev);
}



