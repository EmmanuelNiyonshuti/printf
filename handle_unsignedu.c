#include "main.h"
/**
 * handle_unsigned - Print an unsigned decimal integer.
 * @args: The va_list contining the argument.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 * @base: The base for conversion (8 for %o, 16 for %x and %X).
 * @is_upper: A flag indicating whether to use uppercase for %X.
 *
 * Return: The index after handling the specifier.
 */
int handle_unsigned(va_list args, char *buf, int index, int base, int is_upper)
{
	unsigned int num = va_arg(args, unsigned int);
	int i = 0;
	char temp[15];
	int count = 0;

	if (num == 0)
	{
		buf[index] = '0';
		return (index + 1);
	}

	while (num > 0)
	{
		int digit = num % base;

		temp[i] = (digit < 10) ? digit + '0' : digit - 10 + (is_upper ? 'A' : 'a');
		num = num / base;
		i++;
	}

	for (i = i - 1; i >= 0; i--)
	{
		buf[index] = temp[i];
		index++;
		count++;

		if (index == 1023)
		{
			write(1, buf, index);
			index = 0;
		}
	}

	return (index);
}

