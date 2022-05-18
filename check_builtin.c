#include "shell.h"

/**
 * check_built_in - check if the arg is treated as built in
 * @cmd: string to check
 * Return: true if built in else false
 */

int check_built_in(char *cmd)
{
	char *built_in = "env";
	char *built_in2 = "exit";

	if (cmd == NULL)
		return (0);
	if (!_strcmp(built_in, cmd))
		return (1);
	if (!_strcmp(built_in2, cmd))
		return (2);
	else
		return (0);
}

/**
 * exec_built_in - exec the appropriate built in function
 * @built_in: cmd array of strings
 */

void exec_built_in(char **built_in)
{
	if (!_strcmp(built_in[0], "env") && built_in[1] == NULL)
		print_env();
	if (!_strcmp(built_in[0], "exit"))
		exit_shell(built_in);
}

/**
 * exit_shell - exit with value
 * @built_in: command with num value
 */

void exit_shell(char **built_in)
{
	int ex = 0;

	if (built_in[1] == NULL)
	{
		free_array(built_in);
		exit(ex);
	}
	if (_isnumber(built_in[1]))
	{
		if (built_in[1][0] == '-')
		{
			perror(built_in[0]);
			exit(2);
		}
		ex = _atoi(built_in[1]) % 256,
		   free_array(built_in);
		exit(ex);
	}
	else
	{
		perror(built_in[0]);
		free_array(built_in);
		exit(2);
	}
}

/**
 * print_env - print env as env cmd
 */

void print_env(void)
{
	int i = 0;
	int j = 0;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			_putchar(environ[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
