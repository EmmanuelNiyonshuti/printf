#include "main.h"

/**
 * handle_S - Print a string with non-printable characters as \x followed by
 *            the ASCII code in hexadecimal.
 * @args: The va_list containing the argument.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The index after handling the specifier.
 */
int handle_S(va_list args, char *buf, int index)
{
	int count = 0;
	char *str = va_arg(args, char*);

	if (str == NULL)
	{
	char null_str[] = "(null)";
	int i;

	for (i = 0; null_str[i]; i++)
	{
		buf[index] = null_str[i];
		index++;
	}
	return (index);
	}

	while (*str)
	{
	if (*str < 32 || *str >= 127)
	{
	buf[index] = '\\';
	index++;
	buf[index] = 'x';
	index++;
	count += 2;

	/* Print the ASCII code in hexadecimal */
	count += handle_unsigned(args, buf, index, 16, 1);
	while (count % 2 != 0)
	{
		buf[index] = '0';
		index++;
		count++;
	}
	}
	else
	{
		buf[index] = *str;
		index++;
		count++;
	}

	if (index == 1023)
	{
		write(1, buf, index);
		index = 0;
	}

	str++;
	}

	return (index);
}
