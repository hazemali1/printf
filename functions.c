#include "main.h"

/**
 * printchar - Prints a char
 * @t: Va_arg
 * @b: Buffer
 * @f: Flags
 * @w: Width
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printchar(va_list t, char b[],
	int f, int w, int p, int s)
{
	char c = va_arg(t, int);

	return (handlewritechar(c, b, f, w, p, s));
}

/**
 * printstring - Prints a string
 * @t: Va_arg
 * @b: Buffer
 * @f: Flags
 * @w: Width.
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printstring(va_list t, char b[],
	int f, int w, int p, int s)
{
	int l = 0, i;
	char *str = va_arg(t, char *);

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	if (str == NULL)
	{
		str = "(null)";
		if (p >= 6)
			str = "      ";
	}

	while (str[l] != '\0')
		l++;

	if (p >= 0 && p < l)
		l = p;

	if (w > l)
	{
		if (f & F_MINUS)
		{
			write(1, &str[0], l);
			for (i = w - l; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - l; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], l);
			return (w);
		}
	}

	return (write(1, str, l));
}

/**
 * printpercent - Prints a percent
 * @t: Va_arg
 * @b: Buffer
 * @f: Flags
 * @w: Width.
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printpercent(va_list t, char b[],
	int f, int w, int p, int s)
{
	UNUSED(t);
	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);
	return (write(1, "%%", 1));
}

/**
 * printint - Print int
 * @t: Va_arg
 * @b: Buffer
 * @f: Flags
 * @w: Width.
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printint(va_list t, char b[],
	int f, int w, int p, int s)
{
	int i = BUFFER - 2;
	int isnegative = 0;
	long int n = va_arg(t, long int);
	unsigned long int num;

	n = convertsizenumber(n, s);

	if (n == 0)
		b[i--] = '0';

	b[BUFFER - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		isnegative = 1;
	}

	while (num > 0)
	{
		b[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (writenumber(isnegative, i, b, f, w, p, s));
}

/**
 * printbinary - Prints
 * @t: Va_arg
 * @b: Buffer
 * @f: Flags
 * @w: Width.
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printbinary(va_list t, char b[],
	int f, int w, int p, int s)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int c;

	UNUSED(b);
	UNUSED(f);
	UNUSED(w);
	UNUSED(p);
	UNUSED(s);

	n = va_arg(t, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, c = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			c++;
		}
	}
	return (c);
}
