#include "main.h"

/**
 * handle_hex - Print a lowercase hexadecimal number.
 * @args: The va_list containing the argument.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The index after handling the specifier.
 */
int handle_hex(va_list args, char *buf, int index)
{
	return (handle_unsigned(args, buf, index, 16, 0));
}
