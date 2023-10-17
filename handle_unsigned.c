#include "main.h"
/**
 * handle_unsigned - Print an unsigned decimal integer.
 * @args: The va_list containing the argument.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The index after handling the specifier.
 */
int handle_unsigned(va_list args, char *buf, int index, int base, int is_upper)
{
	unsigned int num = va_arg(args, unsigned int);
	int i = 0;
	char temp[15];

	if (num == 0)
	{
		buf[index] = '0';
		return (index + 1);
	}

	while (num > 0)
	{
		temp[i] = num % 10 + '0';
		num = num / base;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		buf[index] = is_upper ? toupper(temp[i]) : temp[i];
		index++;
	}

	return (index);
}

