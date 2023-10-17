#include "main.h"

/**
 * handle_flags - Handles flags for various conversion specifiers.
 * @args: A va_list containing the argument to be printed.
 * @buf: The buffer to store the result.
 * @index: The current index in the buffer.
 * @flags: The flags for formatting.
 * @format: The format specifier.
 *
 * Return: The updated index.
 */
int handle_flags(va_list args, char *buf, int index, char flags, const char *format)
{
    int count = 0;

    if (flags == '+' || flags == ' ')
    {
        if (*format == 'd' || *format == 'i')
        {
            int num = va_arg(args, int);

            if (flags == '+' && num >= 0)
            {
                buf[index] = '+';
                index++;
                count++;
            }
            else if (flags == ' ' && num >= 0)
            {
                buf[index] = ' ';
                index++;
                count++;
            }

            int num_digits = print_number(num);

            count += num_digits;
        }
        else if (*format == 'u')
        {
            unsigned int num = va_arg(args, unsigned int);

            if (flags == '+')
            {
                buf[index] = '+';
                index++;
                count++;
            }

            int num_digits = handle_unsigned(args, buf, index, num, 10, 0);

            count += num_digits;
        }
        else if (*format == 'x' || *format == 'X' || *format == 'o')
        {
            if (flags == '+' && *format != 'o')
            {
                buf[index] = '+';
                index++;
                count++;
            }

            if (flags == ' ')
            {
                buf[index] = ' ';
                index++;
                count++;
            }

            if (*format == 'x' || *format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                int num_digits = handle_unsigned(args, buf, index, num, 16, (*format == 'X'));

                count += num_digits;
            }
            else if (*format == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                int num_digits = handle_unsigned(args, buf, index, num, 8, 0);

                count += num_digits;
            }
        }
        else if (*format == 'S')
        {
            if (flags == '+')
            {
                char *str = va_arg(args, char *);

                if (str == NULL)
                {
                    return handle_str(buf, index, "(null)");
                }

                buf[index] = '+';
                index++;
                count++;

                while (*str)
                {
                    buf[index] = *str;
                    index++;
                    count++;

                    if (index == 1023)
                    {
                        write(1, buf, index);
                        index = 0;
                    }
                    str++;
                }
            }
            else
            {
                char *str = va_arg(args, char *);

                if (str == NULL)
                {
                    return (handle_str(buf, index, "(null)"));
                }

                while (*str)
                {
                    buf[index] = *str;
                    index++;

                    if (index == 1023)
                    {
                        write(1, buf, index);
                        index = 0;
                    }
                    str++;
                }
            }
        }
        else if (*format == 'p')
        {
            void *ptr = va_arg(args, void *);

            if (flags == '+')
            {
                if (ptr == NULL)
                {
                    return handle_str(buf, index, "(nil)");
                }

                buf[index++] = '+';

                unsigned long ptr_value = (unsigned long)ptr;

                index = handle_unsigned(args, buf, index, ptr_value, 16, 0);
            }
            else
            {
                if (ptr == NULL)
                {
                    return handle_str(buf, index, "(nil)");
                }

                unsigned long ptr_value = (unsigned long)ptr;
                index = handle_unsigned(args, buf, index, ptr_value, 16, 0);
            }
        }
        else if (*format == 'r')  // Placeholder for handling %r
        {
            index = handle_reverse(args, buf, index);
        }
    }

    return index + count;
}
