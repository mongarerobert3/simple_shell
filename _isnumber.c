#include "shell.h"

/**
 * _isdigit - check for digit
 * @c: digit sent to check
 * Return: 1 for digit else 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/**
 * _isnumber - check if string is num
 * @str: string
 * Return: 1 or 0
 */
int _isnumber(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/**
 * _atoi - convert string to integer
 * @s: string to convert
 * Return: int value
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int res = 0;

	while (s[i] >= 9 && s[i] <= 13)
		i++;
	while ((s[i] >= 32 && s[i] <= 47) || (s[i] >= 58 && s[i] <= 126))
	{
		if ((s[i] == '-') || (s[i] == '+'))
		{
			if (s[i] == '-')
				sign = sign * -1;
		}
		i++;
	}
	if (s[i] >= '0' && s[i] <= '9')
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10 + s[i] - '0';
			i++;
		}
	}
	else
	{
		res = 0;
		return (res);
	}
	return (res * sign);
}
