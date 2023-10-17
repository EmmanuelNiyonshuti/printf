#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @str: The input string.
 *
 * Return: The rot13-encoded string.
 */
char *rot13(char *str)
{
    int i;

    for (i = 0; str && str[i]; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if ((str[i] >= 'a' && str[i] <= 'm') ||
                (str[i] >= 'A' && str[i] <= 'M'))
                str[i] += 13;
            else
                str[i] -= 13;
        }
    }

    return str;
}
