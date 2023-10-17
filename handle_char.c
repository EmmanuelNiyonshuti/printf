#include "main.h"
/**
 * handle_char - Handles the %c specifier.
 * @args: A va_list containing the argument to be printed.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The updated index.
 */
int handle_char(va_list args, char *buf, int index)
{
	char c = va_arg(args, int);

	if (index < 1023)
	{
	buf[index] = c;
	index++;
	}
	else
	{
	write(1, buf, index);
	index = 0;
	buf[index] = c;
	index++;
	}

	return (index);
}
