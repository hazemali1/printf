#include "main.h"

/**
 * getflags - Flags
 * @format: Format
 * @i: Parameter
 * Return: Flags
 */
int getflags(const char *format, int *i)
{

	int j, curri;
	int f = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curri = *i + 1; format[curri] != '\0'; curri++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curri] == FLAGS_CH[j])
			{
				f |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curri - 1;

	return (f);
}
