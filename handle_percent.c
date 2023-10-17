#include "main.h"
/**
 * handle_percent - Handles the %% character in the format string.
 * @args: A list of arguments, unused in this function.
 *@buf: The buffer to store the result.
 *@index: the current index in the buffer.
 *
 * Return: The updated index.
 */
int handle_percent(va_list args, char *buf, int index)
{
	buf[index] = '%';
	index++;

	if (index == 1023)
	{
		write(1, buf, index);
		index = 0;
	}
	return (index);
}
