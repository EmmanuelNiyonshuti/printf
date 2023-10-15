#include "main.h"
#include <unistd.h>
/**
 * _printf - Custom printf function.
 * @format: Format string.
 *
 * Return: Number of characters printed(excluding null byte).
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += process_conversion_specifier(*format, args);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);

	return (count);
}
