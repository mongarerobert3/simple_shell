#include "shell.h"
/**
 * get_path - make a suitable path to use with command
 *
 * @cmd: cmd to use to refer to binary
 * Return: 1 or 0
 */
int get_path(char **cmd)
{
	char *path, *find = NULL, **split_path;
	int i = 0;

	path = _strdup(_getenv("PATH"));
	if (_strncmp(cmd[0], "/bin", 4) == 0 || _strncmp(cmd[0], "./", 2) == 0)
	{
		free(path);
		return (1);
	}
	if (cmd[0][0] != '/' && _strncmp(cmd[0], "./", 2) != 0)
	{
		if (access(cmd[0], F_OK) != 0 && _strncmp(cmd[0], "pwd", 3) != 0 &&
				_strncmp(cmd[0], "ls", 2 != 0))
		{
			free(path);
			return (0);
		}
		split_path = strtow(path);
		free(path);
		while (split_path[i])
		{
			find = _calloc(sizeof(char), _strlen(split_path[i])
					+ 1 + _strlen(cmd[0]) + 1);
			if (!find)
				break;
			_strcat(find, split_path[i]), _strcat(find, "/");
			_strcat(find, cmd[0]);
			if (access(find, F_OK) == 0)
				break;
			i++;
			free(find);
			find = NULL;
		}
		free_array(split_path), free(cmd[0]), cmd[0] = find;
	}
	else
		free(path), path = NULL;
	if (find == NULL)
		return (0);
	return (1);
}
