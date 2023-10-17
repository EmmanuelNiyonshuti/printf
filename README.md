printf Project

This project implements a simplified version of the printf function in C.
The printf function is responsible for producing formatted output to the standard output stream.

Table of Contents
Introduction
Getting Started
Project Structure
Usage
Supported Conversion Specifiers
Advanced Features
Authors

Introduction

The goal of this project is to create a custom printf function that can handle specific conversion specifiers and produce formatted output.
It adheres to the guidelines provided by the Betty style checker and follows best practices for C programming.
The project aims to enhance understanding of variadic functions,
string manipulation, and handling different data types in C.

Getting Started

To use this printf implementation, follow these steps:

Clone the repository to your local machine.

Compile the source files using the provided compilation command:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

Run the compiled program:

./a.out

Project Structure
main.h: Header file containing function prototypes and necessary includes.
_printf.c: Main implementation of the custom printf function.
handle_specifier.c: Implementation of functions to handle different conversion specifiers.
_putchar.c: Manually implemented _putchar function for output.

Usage

The custom printf function can be used in a manner similar to the standard printf.

See the provided test cases in the main.c file for usage examples.
/**
*main - Entry Point.
*
*Return: Always 0.
*/
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "printf");
    return 0;
}

Supported Conversion Specifiers
%c: Character
%s: String
%%: Percent sign
%d and %i: Signed integers
%b: Binary representation of an unsigned integer
%u: Unsigned integer
%o: Octal representation
%x and %X: Hexadecimal representation


Advanced Features
The project includes advanced features such as handling flags (+, space, #),
length modifiers (l, h),
field width, precision, and custom conversion specifiers (S, p, r, R).

Author:
NIYONSHUTI Emmanuel
