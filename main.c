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
int exitcode = 0;
(void)ac;

initialize_shell_env(&sev, av, ev);

while (sev.good2go)
{
	display_prompt(sev);
	getcommand(&sev);
	check_alias(&sev);
	if (!check_builtin(&sev))
	action(&sev);
	display_error(&sev);
}
exitcode = sev.error;
clean_sev(&sev);
}



