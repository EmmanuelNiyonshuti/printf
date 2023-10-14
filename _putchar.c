#include <unistd.h>
/**
 * _putchar - write a character to the stdout.
 * @c: Character to write.
 *
 * Return: 0 on success, 1 on error, -1, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
