#include "main.h"
/**
 * handle_char - Handles the %c specifier.
 * @args: A va_list containing the argument to be printed.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The number of characters printed.
 */
int handle_char(va_list args, char *buf, int index)
{
	char c = va_arg(args, int);

	buf[index] = c;
	index++;

	if (index == 1023)
	{
		write(1, buf, index);
		index = 0;
	}
	return (index);
}
