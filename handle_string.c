#include "main.h"
/**
 * handle_string - handle the %s specifier.
 *@args: aA va_list containing the argument to be printed.
 *@buf: The buffer to store the result.
 *@index: The current index in the buffer.
 *
 * Return: The string length.
 */
int handle_string(va_list args, char *buf, int index)
{
	int i;
	int count = 0;
	char *str = va_arg(args, char*);

	if (str == NULL)
	{
		char null_str[] = "(null)";

	for (i = 0; null_str[i]; i++)
	{
		buf[index] = null_str[i];
		index++;
	}
	return (index);
	}
	while(*str)
	{
		buf[index] = *str;
		index++;
		str++;
		count++;

		if (index == 1023)
		{
			write(1, buf, index);
			index = 0;
		}
	}
	return (index);
}
