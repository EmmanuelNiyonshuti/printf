#include "main.h"

/**
 * handle_reverse - Handles the %r conversion specifier.
 * @args: A va_list containing the argument to be printed (string).
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 *
 * Return: The updated index.
 */
int handle_reverse(va_list args, char *buf, int index)
{
    char *str = va_arg(args, char *);

    if (str == NULL)
    {
        return handle_str(buf, index, "(null)");
    }

    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        buf[index] = str[i];
        index++;
    }

    return index;
}
