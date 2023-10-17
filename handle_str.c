#include "main.h"
/**
 *handle_str - Handle strings for %p conversion specifier.
 *@buf: The buffer to store the result.
 *@index: The current index in the buffer.
 *@str: The string to be handled.
 *
 *Return: The index after handling the string.
 */
int handle_str(char *buf, int index, char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		buf[index] = str[i];
		index++;

		if (index == 1023)
		{
			write(1, buf, index);
			index = 0;
		}
	}
	return (index);
}
