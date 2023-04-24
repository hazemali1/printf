#include "main.h"

/**
 * handleprint - Prints
 * @fmt: Format
 * @l: Va_arg
 * @id: Parameter
 * @b: Buffer
 * @f: Flags
 * @w: Width.
 * @p: Precision
 * @s: Size
 * Return: 1 or 2
 */
int handleprint(const char *fmt, int *id, va_list l, char b[],
	int f, int w, int p, int s)
{
	int i, unknowlen = 0, printedchars = -1;
	fmt_t fmt_types[] = {
		{'c', printchar}, {'s', printstring}, {'%', printpercent},
		{'i', printint}, {'d', printint}, {'b', printbinary},
		{'u', printun}, {'o', octal}, {'x', hexadecimal},
		{'X', printhexaupper}, {'p', printpointer}, {'S', printnonprintable},
		{'r', printreverse}, {'R', printrot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*id] == fmt_types[i].fmt)
			return (fmt_types[i].fn(l, b, f, w, p, s));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*id] == '\0')
			return (-1);
		unknowlen += write(1, "%%", 1);
		if (fmt[*id - 1] == ' ')
			unknowlen += write(1, " ", 1);
		else if (w)
		{
			--(*id);
			while (fmt[*id] != ' ' && fmt[*id] != '%')
				--(*id);
			if (fmt[*id] == ' ')
				--(*id);
			return (1);
		}
		unknowlen += write(1, &fmt[*id], 1);
		return (unknowlen);
	}
	return (printedchars);
}
