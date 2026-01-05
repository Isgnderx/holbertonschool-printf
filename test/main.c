#include <stdio.h>
#include "main.h"

int main(void)
{
	int len1, len2;
	char *str = "Hello, World!";

	len1 = _printf("String: %s\n", str);
	len2 = printf("String: %s\n", str);

	_printf("Length _printf: %d\n", len1);
	printf("Length printf: %d\n", len2);

	_printf("Char: %c, Percent: %%\n", 'A');
	printf("Char: %c, Percent: %%\n", 'A');

	_printf("Null string: %s\n", NULL);

	/* edge case: format NULL */
	len1 = _printf(NULL);
	printf("_printf(NULL) returned: %d\n", len1);

	return (0);
}

