#include "main.h"

/**
 * handle_precision - Handles the precision field width for
 *		non-custom conversion specifiers.
 * @args: A va_list containing the argument to be printed.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 * @precision: The precision field width.
 * @specifier: The conversion specifier.
 *
 * Return: The updated index.
*/
int handle_precision(va_list args, char *buf, int index, int precision, char specifier)
{
	(void)args;
	(void)buf;
	(void)index;
	(void)precision;
	(void)specifier;

	int count = 0;
	unsigned int num;
	int num_digits;

	if (specifier == 'd' || specifier == 'i')
	{
		num = va_arg(args, int);

		num_digits = print_number_with_precision(num, precision);

		count += num_digits;
	}
	else if (specifier == 'u' || specifier == 'o' || specifier == 'x' || specifier == 'X')
	{
		num = va_arg(args, unsigned int);

		num_digits = print_unsigned_with_precision(num, precision);

		count += num_digits;
	}

	return (index + count);
}
/**
 * print_number_with_precision - Prints an integer with precision.
 * @n: The integer to be printed.
 * @precision: The precision field width.
 *
 * Return: The number of digits printed (excluding any sign).
*/
int print_number_with_precision(int n, int precision)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}

	if (precision > 0)
	{
		while (precision > 0)
		{
			_putchar('0' + n / power_of_10(precision - 1));
			count++;
			n %= power_of_10(precision - 1);
			precision--;
		}
	}
	return (count);
}
/**
 *power_of_10 - Computes 10 to the power of n.
 *@n: The exponent.
 *
 *Return: 10 to the power of n.
 */

int power_of_10(int n)
{
	int result = 1;

	while (n > 0)
	{
		result *= 10;
		n--;
	}
	return (result);
}
/**
 * print_unsigned_with_precision - Prints an unsigned integer with precision.
 * @n: The unsigned integer to be printed.
 * @precision: The precision field width.
 *
 * Return: The number of digits printed.
 */
int print_unsigned_with_precision(int n, int precision)
{
	int count_digits = 0;

	while (count_digits < precision)
	{
		_putchar('0');
		count_digits++;
	}

	if (n / 10)
		count_digits += print_number(n / 10);

	_putchar(n % 10 + '0');
	count_digits++;

	return (count_digits);
}
