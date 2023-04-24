#include "main.h"

/**
 * getprecision - Precision
 * @format: Format
 * @i: Parameter
 * @l: Va_arg
 * Return: Precision.
 */
int getprecision(const char *format, int *i, va_list l)
{
	int curri = *i + 1;
	int p = -1;

	if (format[curri] != '.')
		return (p);

	p = 0;

	for (curri += 1; format[curri] != '\0'; curri++)
	{
		if (is_digit(format[curri]))
		{
			p *= 10;
			p += format[curri] - '0';
		}
		else if (format[curri] == '*')
		{
			curri++;
			p = va_arg(l, int);
			break;
		}
		else
			break;
	}

	*i = curri - 1;

	return (p);
}
