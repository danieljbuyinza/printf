#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Given format
 * Return: The number of characters printed
*/
int _printf(const char *format, ...)
{
	char c, *s;
	int no_of_characters_printed;
	va_list args;

	va_start(args, format);
	no_of_characters_printed = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				no_of_characters_printed++;
			} else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s)
				{
					putchar(*s);
					s++;
					no_of_characters_printed++;
				}
			} else if (*format == '%')
			{
				putchar('%');
				no_of_characters_printed++;
			}
		} else
		{
			putchar(*format);
			no_of_characters_printed++;
		}
		format++;
	}
	va_end(args);
	return (no_of_characters_printed);
}

