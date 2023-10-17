#include "main.h"
/**
 * handle_int - Handles the %d and %i conversion specifiers.
 * @args: A va_list containing argument to be printed.
 *@buf: The buffer to store the result.
 *@index: The current index in the buffer.
 *
 * Return: The number of digits printed (excluding any sign).
 */
int handle_int(va_list args, char *buf, int index)
{
	int num = va_arg(args, int);

	if (num < 0)
	{
		buf[index] = '-';
		index++;
		num = -num;
	}
	return (handle_unsigned(args, buf, index, 10, 0));
}
/**
 *print_number - Prints an integer using _putchar.
 * @n: The integer to be printed.
 *
 * Return: The number of digis printed (excluding any sign).
*/
int print_number(int n)
{
	int count_digits = 0;

	if (n < 0)
	{
		_putchar('-');
		count_digits++;
		n = -n;
	}
	if (n / 10)
		count_digits += print_number(n / 10);
	_putchar(n % 10 + '0');
	count_digits++;
	return (count_digits);
}
