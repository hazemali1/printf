#include "main.h"

/**
 * isprintable - is printable
 * @c: Parameter
 *
 * Return: Return 0, 1
 */
int isprintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * appendhexacode - Append hexadecimal code
 * @b: Buffer
 * @i: Parameter
 * @asciicode: Ascii
 * Return: Always 3
 */
int appendhexacode(char asciicode, char b[], int i)
{
	char mapto[] = "0123456789ABCDEF";

	if (asciicode < 0)
		asciicode *= -1;

	b[i++] = '\\';
	b[i++] = 'x';

	b[i++] = mapto[asciicode / 16];
	b[i] = mapto[asciicode % 16];

	return (3);
}

/**
 * is_digit - is a digit
 * @c: Parameter
 *
 * Return: Return 0, 1
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convertsizenumber - Size
 * @n: Parameter1
 * @s: Parameter2
 *
 * Return: Long int
 */
long int convertsizenumber(long int n, int s)
{
	if (s == S_LONG)
		return (n);
	else if (s == S_SHORT)
		return ((short)n);

	return ((int)n);
}

/**
 * convertun - Convert unsigned
 * @n: Parameter
 * @s: Size
 *
 * Return: Long int
 */
long int convertun(unsigned long int n, int s)
{
	if (s == S_LONG)
		return (n);
	else if (s == S_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
