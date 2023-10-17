#include "main.h"
/**
  *handle_p - Print the address of a pointer in hexadecimal format.
 * @args: The va_list containing the argument.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The index after handling the specifier.
 */
int handle_p(va_list args, char *buf, int index)
{
	void *ptr = va_arg(args, void *);

	if (!ptr)
	{
		return (handle_str(buf, index, "(nil)"));
	}

	buf[index++] = '0';
	buf[index++] = 'x';

	return (handle_unsigned(args, buf, index, 16, 0));
}
