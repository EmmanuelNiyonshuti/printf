#include "main.h"
/**
 *_strlen - calculate length of the string.
 *@s: the string.
 *
 * Return: length of the string.
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
