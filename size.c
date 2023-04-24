#include "main.h"

/**
 * getsize - Size
 * @format: Format
 * @i: PArameter
 *
 * Return: Size
 */
int getsize(const char *format, int *i)
{
	int curri = *i + 1;
	int size = 0;

	if (format[curri] == 'l')
		size = S_LONG;
	else if (format[curri] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curri - 1;
	else
		*i = curri;

	return (size);
}
