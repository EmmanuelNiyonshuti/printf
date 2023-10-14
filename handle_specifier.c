#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
*process_conversion_specifier - Process and print a conversion specifier
*@specifier: The conversion specifier character
*@args: Variable argument list
*
*Return: Number of characters printed for this specifier
*/
int process_conversion_specifier(char specifier, va_list args)
{
	const char *str;

	switch (specifier)
	{
		case 'c':

				return (_putchar(va_arg(args, int)));
		case 's':
				str = va_arg(args, const char*);
				if (str == NULL)
				{

				str = "(null)";

				}
				return (write(1, str, _strlen(str)));


		case '%':
				return (_putchar('%'));
		case 'd':
		case 'i':
				return (_putchar(va_arg(args, int)));
		default:
				return (write(1, &specifier, 1));
	}
}
/**
 *_strlen - calculate length of the string.
 *@s: the string.
 *
 * Return: length of the string.
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
