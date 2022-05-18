#include "shell.h"
/**
 * ctrlC - handle ctC
 * @sign: unused
 */
void ctrlC(int sign __attribute__((unused)))
{
	_puts("\n");
	_puts("$ ");
}
/**
 * main - main loop through getline to display prompt
 * Return: always 0
 */
int main(void)
{
	char *buff = NULL;
	char **cmd = NULL;
	size_t buf_size = 2048;

	buff = _calloc(sizeof(char), buf_size);
	if (!buff)
	{
		perror("alloc error");
		return (EXIT_FAILURE);
	}
	if (isatty(STDIN_FILENO))
		_puts("$ ");
	signal(SIGINT, ctrlC);
	while (getline(&buff, &buf_size, stdin) > 0)
	{
		cmd = strtow(buff);
		if (cmd != NULL)
		{
			if (check_built_in(cmd[0]) == 0)
			{
				if (get_path(cmd))
					execve_cmd(cmd);
				else
					perror(cmd[0]);
			}
			else if (check_built_in(cmd[0]) == 2)
				free(buff), exec_built_in(cmd);
			else
				exec_built_in(cmd);
			free_array(cmd);
		}
		if (isatty(STDIN_FILENO))
			_puts("$ ");
	}
	if (isatty(STDIN_FILENO))
		_putchar('\n');
	free(buff);
	return (0);
}
