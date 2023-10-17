#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(void);
int handle_int(va_list args);
int handle_binary(va_list args);
int handle_octal(va_list args);
int handle_hex(va_list args);
int handle_hex_upper(va_list args);





















#endif /*MAIN_H*/
