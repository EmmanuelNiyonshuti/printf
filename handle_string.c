#include "main.h"
/**
 * handle_string - Handle the %s specifier.
 * @args: A va_list containing the argument to be printed.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The updated index.
 */
int handle_string(va_list args, char *buf, int index)
{
	int i;
	int count = 0;
	char null_str[];
	char *str = va_arg(args, char*);

	if (str == NULL)
	{
		null_str[] = "(null)";

		for (i = 0; null_str[i]; i++)
		{
			if (index < 1023)
			{
				buf[index] = null_str[i];
				index++;
			}
			else
			{
				write(1, buf, index);
				index = 0;
				buf[index] = null_str[i];
				index++;
			}
		}
	}
	else
	{
		while (*str)
		{
			if (index < 1023)
			{
				buf[index] = *str;
				index++;
			}
			else
			{
				write(1, buf, index);
				index = 0;
				buf[index] = *str;
				index++;
			}
		str++;
		}
	}
	return (index);
}
