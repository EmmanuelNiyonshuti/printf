#include "main.h"
/**
 *handle_percent - Handles the %% specifier.
 *
 *Return: The number of characters printed.
*/
int handle_percent(void)
{
	return (write(1, "%", 1));
}
