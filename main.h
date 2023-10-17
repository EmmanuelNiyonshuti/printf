#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int _putchar(char c);
int handle_char(va_list args, char *buf, int index);
int handle_string(va_list args, char *buf, int index);
int handle_percent(va_list args, char *buf, int index);
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
int handle_reverse(va_list args, char *buf, int index);
int print_char_width(char c, int width);
int print_number_width(int num, int width);
int print_str_width(char *str, int width);
int handle_conversion_specifier(char specifier, va_list args, int width);
char *rot13(char *str);
int _printf(const char *format, ...);

#endif /* MAIN_H */
