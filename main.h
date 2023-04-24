#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format
 * @fn: Function
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format
 * @fm_t: Function
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handleprint(const char *fmt, int *i,
va_list l, char b[], int f, int w, int p, int s);

int printchar(va_list t, char b[],
	int f, int w, int p, int s);
int printstring(va_list t, char b[],
	int f, int w, int p, int s);
int printpercent(va_list t, char b[],
	int f, int w, int p, int s);

int printint(va_list t, char b[],
	int f, int w, int p, int s);
int printbinary(va_list t, char b[],
	int f, int w, int p, int s);
int printun(va_list t, char b[],
	int f, int w, int p, int s);
int octal(va_list types, char buffer[],
	int f, int w, int p, int s);
int hexadecimal(va_list t, char b[],
	int f, int w, int p, int s);
int printhexaupper(va_list t, char b[],
	int f, int w, int p, int s);

int printhexa(va_list t, char mapto[],
char b[], int f, char flagch, int w, int p, int s);

int printnonprintable(va_list t, char b[],
	int f, int w, int p, int s);

int printpointer(va_list t, char b[],
	int f, int w, int p, int s);

int getflags(const char *format, int *i);
int getwidth(const char *format, int *i, va_list l);
int getprecision(const char *format, int *i, va_list l);
int getsize(const char *format, int *i);

int printreverse(va_list t, char b[],
	int f, int w, int p, int s);

int printrot13string(va_list t, char b[],
	int f, int w, int p, int s);

int handlewritechar(char c, char b[],
	int f, int w, int p, int s);
int writenumber(int ispositive, int d, char b[],
	int f, int w, int p, int s);
int writenum(int d, char b[], int f, int w, int p,
	int l, char padd, char extrac);
int writepointer(char b[], int d, int l,
	int w, int f, char padd, char extrac, int paddstart);

int writeun(int isnegative, int d,
char b[],
	int f, int w, int p, int s);

int isprintable(char);
int appendhexacode(char, char[], int);
int is_digit(char);

long int convertsizenumber(long int n, int s);
long int convertun(unsigned long int n, int s);

#endif /* MAIN_H */
