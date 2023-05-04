#include "main.h"

/**
 * handlewritechar - Prints a string
 * @c: Parameter
 * @b: Buffer
 * @f: Flags
 * @w: Width
 * @p: precision
 * @s: Size
 *
 * Return: Int
 */
int handlewritechar(char c, char b[],
	int f, int w, int p, int s)
{
	int i = 0;
	char padd = ' ';

	UNUSED(p);
	UNUSED(s);

	if (f & F_ZERO)
		padd = '0';

	b[i++] = c;
	b[i] = '\0';

	if (w > 1)
	{
		b[BUFFER - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			b[BUFFER - i - 2] = padd;

		if (f & F_MINUS)
			return (write(1, &b[0], 1) +
					write(1, &b[BUFFER - i - 1], w - 1));
		else
			return (write(1, &b[BUFFER - i - 1], w - 1) +
					write(1, &b[0], 1));
	}

	return (write(1, &b[0], 1));
}

/**
 * writenumber - Prints
 * @isnegative: PArameter1
 * @i: Parameter2
 * @b: Buffer
 * @f: Flags
 * @w: Width
 * @p: precision
 * @s: Size
 *
 * Return: Int
 */
int writenumber(int isnegative, int i, char b[],
	int f, int w, int p, int s)
{
	int l = BUFFER - i - 1;
	char padd = ' ', extrach = 0;

	UNUSED(s);

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (isnegative)
		extrach = '-';
	else if (f & F_PLUS)
		extrach = '+';
	else if (f & F_SPACE)
		extrach = ' ';

	return (writenum(i, b, f, w, p,
		l, padd, extrach));
}

/**
 * writenum - Writing
 * @d: PArameter
 * @b: Buffer
 * @f: Flags
 * @w: width
 * @p: Precision specifier
 * @l: Number length
 * @padd: Pading char
 * @extrac: Extra char
 *
 * Return: Int
 */
int writenum(int d, char b[],
	int f, int w, int p,
	int l, char padd, char extrac)
{
	int i, paddstart = 1;

	if (p == 0 && d == BUFFER - 2 && b[d] == '0' && w == 0)
		return (0);
	if (p == 0 && d == BUFFER - 2 && b[d] == '0')
		b[d] = padd = ' ';
	if (p > 0 && p < l)
		padd = ' ';
	while (p > l)
		b[--d] = '0', l++;
	if (extrac != 0)
		l++;
	if (w > l)
	{
		for (i = 1; i < w - l + 1; i++)
			b[i] = padd;
		b[i] = '\0';
		if (f & F_MINUS && padd == ' ')
		{
			if (extrac)
				b[--d] = extrac;
			return (write(1, &b[d], l) + write(1, &b[1], i - 1));
		}
		else if (!(f & F_MINUS) && padd == ' ')
		{
			if (extrac)
				b[--d] = extrac;
			return (write(1, &b[1], i - 1) + write(1, &b[d], l));
		}
		else if (!(f & F_MINUS) && padd == '0')
		{
			if (extrac)
				b[--paddstart] = extrac;
			return (write(1, &b[paddstart], i - paddstart) +
				write(1, &b[d], l - (1 - paddstart)));
		}
	}
	if (extrac)
		b[--d] = extrac;
	return (write(1, &b[d], l));
}

/**
 * writeun - Writes unsigned
 * @isnegative: is negative
 * @d: Parameter
 * @b: Buffer
 * @f: Flagss
 * @w: Width
 * @p: Precisio
 * @s: Size
 *
 * Return: Int
 */
int writeun(int isnegative, int d,
	char b[],
	int f, int w, int p, int s)
{
	int l = BUFFER - d - 1, i = 0;
	char padd = ' ';

	UNUSED(isnegative);
	UNUSED(s);

	if (p == 0 && d == BUFFER - 2 && b[d] == '0')
		return (0);

	if (p > 0 && p < l)
		padd = ' ';

	while (p > l)
	{
		b[--d] = '0';
		l++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';

	if (w > l)
	{
		for (i = 0; i < w - l; i++)
			b[i] = padd;

		b[i] = '\0';

		if (f & F_MINUS)
		{
			return (write(1, &b[d], l) + write(1, &b[0], i));
		}
		else
		{
			return (write(1, &b[0], i) + write(1, &b[d], l));
		}
	}

	return (write(1, &b[d], l));
}

/**
 * writepointer - Address
 * @b: Buffer
 * @d: PArameter1
 * @l: Lengt
 * @w: Width
 * @f: Flags
 * @padd: Parmameter2
 * @extrac: Parameter3
 * @paddstart: Parameter
 *
 * Return: Int
 */
int writepointer(char b[], int d, int l,
	int w, int f, char padd, char extrac, int paddstart)
{
	int i;

	if (w > l)
	{
		for (i = 3; i < w - l + 3; i++)
			b[i] = padd;
		b[i] = '\0';
		if (f & F_MINUS && padd == ' ')
		{
			b[--d] = 'x';
			b[--d] = '0';
			if (extrac)
				b[--d] = extrac;
			return (write(1, &b[d], l) + write(1, &b[3], i - 3));
		}
		else if (!(f & F_MINUS) && padd == ' ')
		{
			b[--d] = 'x';
			b[--d] = '0';
			if (extrac)
				b[--d] = extrac;
			return (write(1, &b[3], i - 3) + write(1, &b[d], l));
		}
		else if (!(f & F_MINUS) && padd == '0')
		{
			if (extrac)
				b[--paddstart] = extrac;
			b[1] = '0';
			b[2] = 'x';
			return (write(1, &b[paddstart], i - paddstart) +
				write(1, &b[d], l - (1 - paddstart) - 2));
		}
	}
	b[--d] = 'x';
	b[--d] = '0';
	if (extrac)
		b[--d] = extrac;
	return (write(1, &b[d], BUFFER - d - 1));
}
