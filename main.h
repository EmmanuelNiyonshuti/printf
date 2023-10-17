#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _putchar(char c);
int handle_char(va_list args);
int handle_char(va_list args, char *buf, int index);
int handle_string(va_list args);
int handle_string(va_list args, char *buf, int index);
int handle_percent(va_list __attribute__((unused)) args);
int handle_percent( __attribute__((unused)) va_list args, char *buf, int index);
int handle_int(va_list args);
int print_number(int n);
int handle_binary(va_list args, char *buf, int index);
int handle_unsigned(va_list args, char *buf, int index, int base, int is_upper);
int handle_octal(va_list args, char *buf, int index);
int handle_hex(va_list args, char *buf, int index);
int handle_hex_upper(va_list args, char *buf, int index);
int handle_S(va_list args, char *buf, int index);
int handle_p(va_list args, char *buf, int index);
int handle_str(char *buf, int index, char *str);
int handle_d(va_list args, char *buf, int index, char flags);
int handle_u(va_list args, char *buf, int index, char flags);
int print_unsigned_with_precision(unsigned int n, int precision);
int print_number_with_precision(int n, int precision);
int handle_precision(va_list args, char *buf, int index, int precision, char specifier);
int handle_flags(va_list args, char *buf, int index, char flags, const char *format);
int _printf(const char *format, ...);

#endif /* MAIN_H */
