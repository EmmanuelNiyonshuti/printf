#include "main.h"
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
	char c;

	switch (specifier)
	{
		case 'c':
				c = (char) va_arg(args, int);

				return (write(1, &c, 1));
		case 's':
				str = va_arg(args, const char*);
				if (str == NULL)
				{

				str = "(null)";

				}
				return (write(1, str, _strlen(str)));


		case '%':
				return (write(1, &specifier, 1));
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
