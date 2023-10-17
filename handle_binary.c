#include "main.h"
/**
 * handle_binary - Convert an unsigned integer to binary.
 * @args: The va_list containing the argument.
 * @buf: the buffer to store the result.
 * @index: The current index in the buffer.
 *
 *Return: The updated index.
*/
int handle_binary(va_list args, char *buf, int index)
{
	unsigned int num = va_arg(args, unsigned int);

	return (handle_unsigned(args, buf, index, num, 2, 0));
}
