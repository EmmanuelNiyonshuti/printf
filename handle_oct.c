#include "main.h"
/**
 * handle_octal - Prints an unsigned octal integer.
 * @args: The va_list containing the argument.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The index after handling the specifier.
 */
int handle_octal(va_list args, char *buf, int index)
{
	unsigned int num = va_arg(args, unsigned int);
	int i = 0;
	char temp[12];

	if (num == 0)
	{
		buf[index] = '0';
		return (index + 1);
	}

	while (num > 0)
	{
		temp[i] = num % 8 + '0';
		num = num / 8;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		buf[index] = temp[i];
		index++;
	}

	return (index);
}
