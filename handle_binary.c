#include "main.h"
/**
 *handle_binary - Handles the %b specifier.
 *@args: A va_list containing the argument to be printed.
 *
 *Return: The number of characters printed.
 */
int handle_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;
	char buffer[32];
	int i = 0;

	do {
		buffer[i++] = (num % 2) + '0';
		num /= 2;
	} while (num > 0);

	while (--i >= 0)
		count += write(1, &buffer[i], 1);

	return (count);
}
