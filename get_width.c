#include "main.h"

/**
 * getwidth - Width
 * @format: Format
 * @i: Parameter
 * @l: Va_arg
 *
 * Return: width
 */
int getwidth(const char *format, int *i, va_list l)
{
	int curri;
	int w = 0;

	for (curri = *i + 1; format[curri] != '\0'; curri++)
	{
		if (is_digit(format[curri]))
		{
			w *= 10;
			w += format[curri] - '0';
		}
		else if (format[curri] == '*')
		{
			curri++;
			w = va_arg(l, int);
			break;
		}
		else
			break;
	}

	*i = curri - 1;

	return (w);
}
