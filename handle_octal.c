#include "main.h"

/**
 * handle_octal - Print an octal number.
 * @args: The va_list containing the argument.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The index after handling the specifier.
 */
int handle_octal(va_list args, char *buf, int index)
{
	return (handle_unsigned(args, buf, index, 8, 0));
}
