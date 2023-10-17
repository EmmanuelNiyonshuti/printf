#include "main.h"
/**
*handle_char - Handles the %c specifier.
*@args: A va_list containing the argument to be printed.
*
*Return: The number of characters printed.
*/
int handle_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
