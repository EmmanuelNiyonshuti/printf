#include "main.h"
/**
 *handle_int - Handles the %d and %i specifiers.
 *@args: A va_list containing the argument to be printed.
 *
 *Return: The number of characters printed.
*/
int handle_int(va_list args)
{
	int num = va_arg(args, int);
	int count = 0;

	char buffer[12];
	int i = 0;
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	do {
		buffer[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
		buffer[i++] = '-';

	while (--i >= 0)
		count += write(1, &buffer[i], 1);

	return (count);
}
