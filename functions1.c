#include "main.h"

/**
 * printtun - prints unsigned
 * @t: va_list
 * @b: Buffer
 * @f: flags
 * @w: get
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printun(va_list t, char b[],
	int f, int w, int p, int s)
{
	int i = BUFFER - 2;
	unsigned long int n = va_arg(t, unsigned long int);

	n = convertun(n, s);

	if (n == 0)
		b[i--] = '0';

	b[BUFFER - 1] = '\0';

	while (n > 0)
	{
		b[i--] = (n % 10) + '0';
		n /= 10;
	}

	i++;

	return (writeun(0, i, b, f, w, p, s));
}

/**
 * octal - Print octal
 * @t: va_arg
 * @b: Buffer
 * @f: flags
 * @w: width
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int octal(va_list t, char b[],
	int f, int w, int p, int s)
{

	int i = BUFFER - 2;
	unsigned long int n = va_arg(t, unsigned long int);
	unsigned long int init_num = n;

	UNUSED(w);

	n = convertun(n, s);

	if (n == 0)
		b[i--] = '0';

	b[BUFFER - 1] = '\0';

	while (n > 0)
	{
		b[i--] = (n % 8) + '0';
		n /= 8;
	}

	if (f & F_HASH && init_num != 0)
		b[i--] = '0';

	i++;

	return (writeun(0, i, b, f, w, p, s));
}

/**
 * hexadecimal - Prints hexadecimal
 * @t: va_arg
 * @b: Buffer
 * @f: Flags
 * @w: Widht
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int hexadecimal(va_list t, char b[],
	int f, int w, int p, int s)
{
	return (printhexa(t, "0123456789abcdef", b,
		f, 'x', w, p, s));
}

/**
 * printhexaupper - upper hexadecimal
 * @t: va_arg
 * @b: Buffer
 * @f: Flags
 * @w: Width
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printhexaupper(va_list t, char b[],
	int f, int w, int p, int s)
{
	return (printhexa(t, "0123456789ABCDEF", b,
		f, 'X', w, p, s));
}

/**
 * printhexa - hexadecimal
 * @t: Va_arg
 * @mapto: Map
 * @b: Buffer
 * @f: flags
 * @flagch: flags
 * @w: width
 * @p: Precision
 * @s: Size
 * Return: Int
 */
int printhexa(va_list t, char mapto[], char b[],
	int f, char flagch, int w, int p, int s)
{
	int i = BUFFER - 2;
	unsigned long int n = va_arg(t, unsigned long int);
	unsigned long int init_num = n;

	UNUSED(w);

	n = convertun(n, s);

	if (n == 0)
		b[i--] = '0';

	b[BUFFER - 1] = '\0';

	while (n > 0)
	{
		b[i--] = mapto[n % 16];
		n /= 16;
	}

	if (f & F_HASH && init_num != 0)
	{
		b[i--] = flagch;
		b[i--] = '0';
	}

	i++;

	return (writeun(0, i, b, f, w, p, s));
}
