#include "main.h"

int _putchar(char c)
{
    return (write(1, &c, 1));
}

void _put(char str[], int size)
{
    if (size > 0)
        write(1, &str[0], size);
}

int printnumber(int number, int k)
{
    int  e, r, o = 2, y = 1, u, p, h = 10, i = 0, l, m = 0;

    if (k == 1 && number > 0)
    {
        _putchar('+');
    }
    if (k == 2 && number >= 0)
    {
        _putchar(' ');
        i++;
    }
    if (number < 0)
    {
        number *= -1;
        _putchar('-');
        if (k != 1)
        {
            i++;
        }
    }
    if (number < 10)
    {
        _putchar(number + '0');
        return (1);
    }
    r = number;
    while (r / 10 >= 10)
    {
        r /= 10;
        o++;
    }
    for (e = 1; e < o; e++)
    {
        y *= 10;
    }
    for (e = 0; e < o; e++)
    {
        if (e == 0)
        {
            u = number / y;
            _putchar(u + '0');
            y /= 10;
        }
        else
        {
            u = number / y;
            while (u >= 10)
            {
                if (m == 0)
                {
                    l = h;
                }
                p = u % l;
                u = p;
                l /= 10;
                m++;
            }
            m = 0;
            _putchar(p + '0');
            y /= 10;
            h *= 10;
        }
    }
    return (o + i);
}
unsigned int printunnumber(unsigned int number)
{
    unsigned int  e, r, o = 2, y = 1, u, p, h = 10, i = 0, l, m = 0;

    if (number < 10)
    {
        printnumber(number, 0);
        return (1);
    }
    r = number;
    while (r / 10 >= 10)
    {
        r /= 10;
        o++;
    }
    for (e = 1; e < o; e++)
    {
        y *= 10;
    }
    for (e = 0; e < o; e++)
    {
        if (e == 0)
        {
            u = number / y;
            printnumber(u, 0);
            y /= 10;
        }
        else
        {
            u = number / y;
            while (u > 10)
            {
                if (m == 0)
                {
                    l = h;
                }
                p = u % l;
                u = p;
                l /= 10;
                m++;
            }
            m = 0;
            printnumber(p, 0);
            y /= 10;
            h *= 10;
        }
    }
    return (o + i);
}

int binary(int n)
{
    int r = 1, i = 0, j;
    int binaryNum[32];

    if (n == 0)
    {
        _putchar('0');
        return (1);
    }
    for ( ;n > 0; )
    {
        binaryNum[i++] = n % 2;
        n /= 2;
    }
    for (j = i - 1; j >= 0; j--)
    {
        printnumber(binaryNum[j], 0);
        r++;
    }
    return (r);
}

unsigned int _octal(unsigned int n)
{
    unsigned int q, r;
    unsigned int arr[50], w = 1, e;

    if (n == 0)
    {
        printunnumber(0);
        return (2);
    }
    q = n;
    while (q != 0)
    {
        arr[w++] = q % 8;
        q = q / 8;
    }
    r = w;
    for (e = w - 1; e > 0; e--)
    {
        printunnumber( arr[e]);
    }

    return (r);
}

void _switch(int n, char x)
{
    char Arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char ARR[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    char s;
    if (x == 'x')
    {
        s = Arr[n - 10];
    }
    else
    {
        s = ARR[n - 10];
    }
    _putchar(s);
}

unsigned int _hexadecimal(long int n)
{
    unsigned int q, r;
    unsigned int arr[50], w = 1, e;

    if (n == 0)
    {
        printunnumber(0);
        return (2);
    }
    q = n;
    while (q != 0)
    {
        arr[w++] = q % 16;
        q = q / 16;
    }
    r = w;
    for (e = w - 1; e > 0; e--)
    {
        if (arr[e] >= 10)
        {
            _switch(arr[e], 'x');
        }
        else
        {
            printunnumber( arr[e]);
        }
    }

    return (r);
}

unsigned int _Hexadecimal(long int n)
{
    unsigned int q, r;
    unsigned int arr[50], w = 1, e;


    if (n == 0)
    {
        printunnumber(0);
        return (2);
    }
    q = n;
    while (q != 0)
    {
        arr[w++] = q % 16;
        q = q / 16;
    }
    r = w;
    for (e = w - 1; e > 0; e--)
    {
        if (arr[e] >= 10)
        {
            _switch(arr[e], 'X');
        }
        else
        {
            printunnumber( arr[e]);
        }
    }

    return (r);
}

int _Put(char *w)
{
    int r = 0, q = 0;

    if (w == NULL)
    {
        _put("(null)", 6);
        r += 6;
    }
    else
    {
        while (w[q])
        {
            q++;
        }
        _put(w, q);
    }
    return (r + q);
}

int _PUT(char *w)
{
    int r = 0, q = 0;

    if (w == NULL)
    {
        _put("(null)", 6);
        r += 6;
    }
    else
    {
        while (w[q])
        {
            if (w[q] == 0 || (w[q] >= 32 && w[q] < 127))
            {
                _putchar(w[q]);
            }
            else
            {
                _putchar('\\');
                _putchar('x');
                if (w[q] < 16)
                {
                    _putchar('0');
                    r++;
                }
                _Hexadecimal(w[q]);
                r += 2;
            }
            q++;
        }
    }
    return (r + q);
}

unsigned long  int _hexadecimall(long  int n)
{
    unsigned long int q, r;
    unsigned long int arr[50], w = 1, e;

    q = n;
    while (q != 0)
    {
        arr[w++] = q % 16;
        q = q / 16;
    }
    r = w;
    for (e = w - 1; e > 0; e--)
    {
        if (arr[e] >= 10)
        {
            _switch(arr[e], 'x');
        }
        else
        {
            printunnumber( arr[e]);
        }
    }

    return (r);
}

int _rev(char *s)
{
    int  d = 0, w;

    if (s[d])
    {
        while (s[d] != '\0')
        {
            d++;
        }
        for (w = d - 1; w >= 0; w--)
        {
            _putchar(s[w]);
        }
    }
    return (d);
}

int _rot13(char *s)
{
    int r, d = 0, w = 0;
    char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    while (s[d] != '\0')
    {
        d++;
    }
    while (s[w] != '\0')
    {
        for (r = 0; r < 51; r++)
        {
            if (s[w] == a[r])
            {
                _putchar(b[r]);
            }
        }
        w++;
    }
    return (d);
}

int _printf(const char *format, ...)
{
    int d = 0,r = 0, e = 0, q, o, b, a, l = 0, z, v;
    int long t, j;
    char *w;
    va_list s;
    unsigned int m, u;

    va_start(s, format);
    if (format)
    {
        while (format[d])
        {
            r++;
            d++;
        }
        while (format[e])
        {
            switch (format[e])
            {
                case '%':
                	if (format[e + 1] == 'l' || format[e + 1] == 'h')
                	{
                		e++;
                		r--;
				o++;
			}
                    if (format[e + 1] == ' ' && format[e + 2] == '+')
                    {
                        e++;
                        l = 1;
                        e++;
                        r--;
                    }
                    if (format[e + 1] == '+')
                    {
                        e++;
                        l = 1;
                        if (format[e + 1] == ' ')
                        {
                            e++;
                            r--;
                        }
                    }
                    if (format[e + 1] == ' ' && format[e + 2])
                    {
                        e++;
                        r--;
                        l = 2;
                    }
                    if (format[e + 1] == '#')
                    {
                        l = 3;
                        e++;
                    }
                    switch (format[e + 1])
                    {
                        case '%':
                            _putchar(format[e + 1]);
                            r--;
                            break;
                        case 'c':
                            _putchar(va_arg(s, int));
                            r--;
                            e++;
                            break;
                        case 's':
                            w = va_arg(s, char *);
                            q = _Put(w);
                            r += q - 2;
                            e++;
                            break;
                        case 'd':
                        case 'i':

                            z = va_arg(s, int);
                            if (z == INT_MIN)
                            {
                                _putchar('-');
                               o += printunnumber(INT_MIN);
                            }
                            else
                            {
                                o = printnumber(z, l);
                            }
                            r += o - 2;
                            e++;
                            break;
                        case 'b':
                            b = binary(va_arg(s, int));
                            r += b - 3;
                            e++;
                            break;
                        case 'u':
                            v = (unsigned int)va_arg(s, unsigned int);
                            if (v < 0)
                            {
                            	a = printunnumber(v);
                        	}
                        	else
                        	{
                        		printnumber(v, 0);
							}
                            r += a - 2;
                            e++;
                            break;
                        case 'o':
                            if (l == 3)
                            {
                                u = (unsigned int) va_arg(s, unsigned int);
                                if (u > 0)
                                {
                                    _putchar('0');
                                }
                                else
                                {
                                    r--;
                                }
                                m = _octal(u);
                            }
                            else
                            {
                                m = _octal((unsigned int) va_arg(s, unsigned int));
                            }
                            r += (int)m - 3;
                            e++;
                            break;
                        case 'x':
                            if (l == 3)
                            {
                                j = va_arg(s, long int);
                                if (j != 0)
                                {
                                    _putchar('0');
                                    _putchar('x');
                                    r++;
                                }
                                else
                                {
                                    r--;
                                }
                                m = _hexadecimal(j);
                            }
                            else
                            {
                                m = _hexadecimal(va_arg(s, long int));
                            }
                            r += (int)m - 3;
                            e++;
                            break;
                        case 'X':
                            if (l == 3)
                            {
                                j = va_arg(s, long int);
                                if (j != 0)
                                {
                                    _putchar('0');
                                    _putchar('X');
                                    r++;
                                }
                                else
                                {
                                    r--;
                                }
                                m = _Hexadecimal(j);
                            }
                            else
                            {
                                m = _Hexadecimal(va_arg(s, long int));
                            }
                            r += (int)m - 3;
                            e++;
                            break;
                        case 'S':

                            w = va_arg(s, char *);
                            q = _PUT(w);
                            r += q - 2;
                            e++;
                            break;
                        case 'p':

                            t = (long int)va_arg(s, void *);
                            _put("0x", 2);
                            _hexadecimall((long int)t);
                            e++;
                            break;
                        case 'r':

                            w = va_arg(s, char *);
                            q = _rev(w);
                            r += q - 2;
                            e++;
                            break;
                        case 'R':

                            w = va_arg(s, char *);
                            q = _rot13(w);
                            r += q - 2;
                            e++;
                            break;
                        case ' ':
                            r = 0;
                            e++;

                            break;


                    }
                    break;
                default:
                    _putchar(format[e]);
                    break;
            }
            e++;
        }
    }
    va_end(s);
    return (r);
}

