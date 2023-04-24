#include "main.h"

/**
 * printpointer - Pointer variable
 * @t: Va_arg
 * @b: Buffer
 * @f: flags
 * @w: Width
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printpointer(va_list t, char b[],
	int f, int w, int p, int s)
{
	char extrac = 0, padd = ' ';
	int d = BUFFER - 2, l = 2, paddstart = 1;
	unsigned long numaddrs;
	char mapto[] = "0123456789abcdef";
	void *a = va_arg(t, void *);

	UNUSED(w);
	UNUSED(s);

	if (a == NULL)
		return (write(1, "(nil)", 5));

	b[BUFFER - 1] = '\0';
	UNUSED(p);

	numaddrs = (unsigned long)a;

	while (numaddrs > 0)
	{
		b[d--] = mapto[numaddrs % 16];
		numaddrs /= 16;
		l++;
	}

	if ((f & F_ZERO) && !(f & F_MINUS))
		padd = '0';
	if (f & F_PLUS)
		extrac = '+', l++;
	else if (f & F_SPACE)
		extrac = ' ', l++;

	d++;

	return (writepointer(b, d, l,
		w, f, padd, extrac, paddstart));
}

/**
 * printnonprintable - Prints
 * @t: Va_arg
 * @b: Buffer
 * @f: Flags
 * @w: Width
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printnonprintable(va_list t, char b[],
	int f, int w, int p, int s)
{
	int i = 0, offset = 0;
	char *str = va_arg(t, char *);

	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (isprintable(str[i]))
			b[i + offset] = str[i];
		else
			offset += appendhexacode(str[i], b, i + offset);

		i++;
	}

	b[i + offset] = '\0';

	return (write(1, b, i + offset));
}

/**
 * printreverse - Rev
 * @t: Va_arg
 * @b: Buffer
 * @f: Flags
 * @w: Width
 * @p: Precision
 * @s: Size
 * Return: Int
 */

int printreverse(va_list t, char b[],
	int f, int w, int p, int s)
{
	char *str;
	int i, c = 0;

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(s);

	str = va_arg(t, char *);

	if (str == NULL)
	{
		UNUSED(p);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		c++;
	}
	return (c);
}

/**
 * printrot13string - Rot13.
 * @t: Va_arg
 * @b: Buffer
 * @f: flags
 * @w: Width
 * @p: Prec
 * @s: Size
 * Return: Int
 */
int printrot13string(va_list t, char b[],
	int f, int w, int p, int s)
{
	char x;
	char *str;
	unsigned int i, j;
	int c = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(t, char *);
	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				c++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			c++;
		}
	}
	return (c);
}
