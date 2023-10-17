#include "main.h"

/**
 * handle_hex_upper - Handles the %X specifier.
 * @args: A va_list containing the argument to be printed.
 *
 * Return: The number of characters printed.
 */
int handle_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;
	char buffer[32];
	int i = 0;
	int remainder;

	do {
	remainder = num % 16;
	buffer[i++] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'A';
	num /= 16;
	} while (num > 0);

	while (--i >= 0)
	count += write(1, &buffer[i], 1);

	return (count);
}
