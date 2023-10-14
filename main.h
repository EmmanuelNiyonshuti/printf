#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int process_conversion_specifier(char specifier, va_list args);
int _strlen(const char *s);

#endif /*MAIN_H*/
