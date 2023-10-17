#include "main.h"
/**
 * handle_string - Handles the %s specifier.
 * @args: A va_list containing the argument to be printed.
 *
 * Return: The number of characters printed.
*/
int handle_string(va_list args)
{
	char *str = va_arg(args, char*);
	int count = 0;

	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}
