#include "shell.h"
/**
 * _memset - fills n bytes of s with byte b
 * @s: pointer to memory area
 * @b: bytes to fill in
 * @n: size of the adress
 * Return: pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
/**
 * _calloc - reproduce the bahavior of calloc
 * @nmemb: numbers of line to array
 * @size: size of array
 * Description: use malloc to allocate memory large enough for an array
 * initializing to zero
 * Return: pointer value or null if fail
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p;

	if (nmemb == 0 || size == 0)
		return (0);
	p = malloc(nmemb * size);
	if (!p)
		return (0);

	p = _memset(p, 0, nmemb * size);
	return (p);
}
