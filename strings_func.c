#include "shell.h"

/**
 * _strstr - find needle in the haystack string
 * @haystack: string to search into
 * @needle: substring to look for
 *
 * Return: pointer to first char of substring or 0 if no sub found
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j = 0;

	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i])
	{
		if (needle[0] == haystack[i])
		{
			while (haystack[i + j] == needle[j] && needle[j])
			{
				if (needle[j + 1] == '\0')
					return (&haystack[i]);
				j++;
			}
		}
		i++;
		j = 0;
	}
	return (NULL);
}

/**
 * _strlen - return the lenght of string
 * @s: string to mesure
 *
 * Return: lenght value
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
/**
 * _strcat - append src to dest
 * @dest: base string
 * @src: string to append
 * Return: pointer to new dest string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j;

	while (dest[i])
	{
		i++;
	}
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/**
 * _strdup - duplicate string
 * @str: string to duplicate
 *
 * Return: pointer to duplicated string or 0 if str is null or fail
 */

char *_strdup(char *str)
{
	char *dest;
	int i = 0;

	if (str == 0)
		return (0);

	while (str[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (0);
	i = 0;

	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcmp - compare two string
 * @s1: string to compare
 * @s2: string to compare
 * Return: value of character difference
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
