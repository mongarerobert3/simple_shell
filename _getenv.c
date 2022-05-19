#include "shell.h"
/**
 * _getenv - find the path inside of env array
 * @name: word path to refer to
 * Return: pointer to the path string or null
 */
char *_getenv(char *name)
{
	int i = 0;
	char *path = NULL;

	while (*environ[i])
	{
		if (_strstr(environ[i], name) != NULL && environ[i][0] == 'P')
		{
			return (environ[i]);
		}
		i++;
	}
	path = _strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");
	return (path);
}
