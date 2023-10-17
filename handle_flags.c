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
	int num;
	int num_digits;
	int count = 0;
	char *str;
	void *ptr;
	unsigned long ptr_value;

	if (flags == '+' || flags == ' ')
	{
		if (*format == 'd' || *format == 'i')
		{
			num = va_arg(args, int);

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

		num_digits = print_number(num);

		count += num_digits;
		}
		else if (*format == 'u')
		{
			num = va_arg(args, unsigned int);

		if (flags == '+')
		{
			buf[index] = '+';
			index++;
			count++;
		}

		num_digits = handle_unsigned(args, buf, index, 10, 0);

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
			num = va_arg(args, unsigned int);
			num_digits = handle_unsigned(args, buf, index, 16, (*format == 'X'));
			count += num_digits;
		}
		else if (*format == 'o')
		{
			num = va_arg(args, unsigned int);
			num_digits = handle_unsigned(args, buf, index, 8, 0);

                count += num_digits;
            }
        }
        else if (*format == 'S')
        {
            if (flags == '+')
            {
               str = va_arg(args, char *);

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
                str = va_arg(args, char *);

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
            ptr = va_arg(args, void *);

            if (flags == '+')
            {
                if (ptr == NULL)
                {
                    return handle_str(buf, index, "(nil)");
                }

                buf[index++] = '+';

               ptr_value = (unsigned long)ptr;

                index = handle_unsigned(args, buf, index, 16, 0);
            }
            else
            {
                if (ptr == NULL)
                {
                    return handle_str(buf, index, "(nil)");
                }

                ptr_value = (unsigned long)ptr;
                index = handle_unsigned(args, buf, index, 16, 0);
            }
        }
        else if (*format == 'r')
        {
            index = handle_reverse(args, buf, index);
        }
    }

    return index + count;
}
