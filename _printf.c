#include "main.h"

/**
 * _printf - prints according to format
 * @format: format string
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	char *s;

	va_start(args, format);

	if (!format)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				if (!s)
					s = "(null)";
				while (*s)
				{
					write(1, s, 1);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
			format++;
		}
		else
		{
			write(1, format, 1);
			count++;
			format++;
		}
	}

	va_end(args);
	return (count);
}

