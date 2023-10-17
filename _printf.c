#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int width;
	int result;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == '*')
			{
				width = va_arg(args, int);
				format++;
			}
			else
			{
				width = 0;
				while (*format >= '0' && *format <= '9')
				{
					width = width * 10 + (*format - '0');
					format++;
				}
			}

					if (*format)
					{
						result = handle_conversion_specifier(*format, args, width);
						if (result == -1)
						{
							va_end(args);
							return -1;
						}
					count += result;
					format++;
					}
		}
		else
		{
			write(1, format, 1);
			format++;
			count++;
		}
	}

	va_end(args);
	return (count);
}
/**
 * handle_conversion_specifier - Handles conversion specifiers for _printf.
 * @specifier: The conversion specifier character.
 * @args: A va_list containing the argument to be printed.
 * @width: The field width.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int handle_conversion_specifier(char specifier, va_list args, int width)
{
	char c;
	char *str;
	int count = 0;
	char* buf;
	int index;

	switch (specifier)
	{
	case 'c':
		c = va_arg(args, int);
		count += print_char_width(c, width);
		break;

	case 's':
		str = va_arg(args, char *);
		count += print_str_width(str ? str : "(null)", width);
		break;
	case '%':
		write(1, "%", 1);
		count++;
		break;

	case 'd':
	case 'i':
		if (width < 0)
		{
			width = -width;
			write(1, "-", 1);
			count++;
		}
		count += print_number_width(va_arg(args, int), width);
		break;
	case 'r':
		buf = malloc(1024);
		if (buf == NULL)
		{
			return (-1);
		}
		index = 0;
		count += handle_reverse(args, buf, index);
		write(1, buf, index);
		free(buf);
		break;
	default:

		return -1;
	}
	return (count);
}

/**
 * print_number_width - Prints an integer with a specified field width.
 * @num: The integer to be printed.
 * @width: The field width.
 *
 * Return: The number of characters printed.
 */
int print_number_width(int num, int width)
{
	char buffer[20];
	int count = 0;
	int length = 0;
	int padding;

	length = snprintf(buffer, sizeof(buffer), "%d", num);

	if (length < width)
	{
		padding = width - length;
		while (padding-- > 0)
		{
			write(1, " ", 1);
			count++;
		}
	}
	write(1, buffer, length);
	count += length;

	return (count);
}

/**
 * print_char_width - Prints a character with a specified field width.
 * @c: The character to be printed.
 * @width: The field width.
 *
 * Return: The number of characters printed.
 */
int print_char_width(char c, int width)
{
	int count = 0;
	int padding;

	if (width > 1)
	{
		padding = width - 1;
		write(1, &c, 1);
		count++;

		while (padding-- > 0)
			{
				write(1, " ", 1);
				count++;
			}
	}
	else
	{
		write(1, &c, 1);
		count++;
	}

	return (count);
}
/**
 * print_str_width - Prints a string with a specified field width.
 * @str: The string to be printed.
 * @width: The field width.
 *
 * Return: The number of characters printed.
 */
int print_str_width(char *str, int width)
{
	int count = 0;
	int padding;
	int length = str ? strlen(str) : 6;

	if (length < width)
	{
		padding = width - length;
		write(1, str ? str : "(null)", length);
		count += length;

		while (padding-- > 0)
		{
			write(1, " ", 1);
			count++;
		}
	}
	else
	{
		write(1, str ? str : "(null)", length);
		count += length;
	}

	return (count);
}
