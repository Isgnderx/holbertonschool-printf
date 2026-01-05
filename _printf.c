#include "main.h"

/**
 * _printf - prints according to format
 * @format: format string
 *
 * Return: number of chars printed, -1 if format is NULL
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *s;
	char c;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format) /* end of string after % */
				break;

			if (*format == 'c') /* char */
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (*format == 's') /* string */
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
			else if (*format == '%') /* literal % */
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				/* unknown specifier: ignore, do not print */
				;
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

