#include "main.h"

void printbuffer(char b[], int *buffind);

/**
 * _printf - Printf
 * @format: format
 * Return: Int
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printedchars = 0;
	int f, w, p, s, buffind = 0;
	va_list l;
	char b[BUFFER];

	if (format == NULL)
		return (-1);

	va_start(l, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			b[buffind++] = format[i];
			if (buffind == BUFFER)
				printbuffer(b, &buffind);
			printedchars++;
		}
		else
		{
			printbuffer(b, &buffind);
			f = getflags(format, &i);
			w = getwidth(format, &i, l);
			p = getprecision(format, &i, l);
			s = getsize(format, &i);
			++i;
			printed = handleprint(format, &i, l, b,
				f, w, p, s);
			if (printed == -1)
				return (-1);
			printedchars += printed;
		}
	}

	printbuffer(b, &buffind);

	va_end(l);

	return (printedchars);
}

/**
 * printbuffer - Prints buffer
 * @b: Buffer
 * @buffind: Parameter
 */
void printbuffer(char b[], int *buffind)
{
	if (*buffind > 0)
		write(1, &b[0], *buffind);

	*buffind = 0;
}
