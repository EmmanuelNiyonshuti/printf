#include "main.h"
/**
*_printf - Custom printf function.
*@format: The format string.
*
*Return: Number of characters printed (excluding null byte).
*/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += handle_char(args);
					break;
				case 's':
					count += handle_string(args);
					break;
				case '%':
					count += handle_percent();
					break;

				default:
					write(1, "%", 1);
					write(1, format, 1);
					count += 2;
			}
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
