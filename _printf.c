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

int printnumber(int number, int k, int t)
{
    int  e, r, o = 2, y = 1, u, p, h = 10, i = 0, l, m = 0, q, w = 6, s, f = -1, v = 0;


    if (k == 1 && number > 0)
    {
        _putchar('+');
    }
    if (k == 2 && number >= 0)
    {
        _putchar(' ');
        i++;
    }
    if (k == 5 && number< 100000 && number > -10000)
    {
        q = number;
        if (q < 10 && q >= 0)
        {
            _putchar('0');
            _putchar('0');
            _putchar('0');
            _putchar('0');
            _putchar('0');
            f += 5;
        }
        else
        {
            if (q < 0)
            {
                _putchar('-');
                q *= -1;
                v = 1;
            }
            while (q / 10 > 0)
            {
                q = q / 10;
                w--;
            }
            for (s = 0; s < w - 1; s++)
            {
                _putchar('0');
                f++;
            }
        }

    }
    if (t == 6 && number < 100000 && number > -10000 && k != 5)
    {
        q = number;
        if (q < 10 && q >= 0)
        {
            _putchar(' ');
            _putchar(' ');
            _putchar(' ');
            _putchar(' ');
            _putchar(' ');
            f += 5;
        }
        else
        {
            if (q < 0)
            {
                q *= -1;
                w--;
            }
            while (q / 10 > 0)
            {
                q = q / 10;
                w--;
            }
            for (s = 0; s < w - 1; s++)
            {
                _putchar(' ');
                f++;
            }
        }

    }
    if (number < 0)
    {
        number *= -1;
        if (v == 0)
        {
            _putchar('-');
        }
        if (k != 1)
        {
            i++;
        }
    }
    if (number < 10)
    {
        _putchar(number + '0');
        return (1 + f);
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
    return (o + i + f);
}
unsigned int printunnumber(unsigned int number)
{
    unsigned int  e, r, o = 2, y = 1, u, p, h = 10, i = 0, l, m = 0;

    if (number < 10)
    {
        printnumber(number, 0, 0);
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
            printnumber(u, 0, 0);
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
            printnumber(p, 0, 0);
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
        printnumber(binaryNum[j], 0, 0);
        r++;
    }
    return (r);
}

unsigned int _octal(unsigned int n, int l, int t)
{
    unsigned int q, r, d;
    unsigned int arr[50], w = 1, e;
    int f = 0;

    if (n == 0)
    {
        if (l == 5)
        {
            _putchar('0');
            _putchar('0');
            _putchar('0');
            _putchar('0');
            _putchar('0');
            f += 5;
        }
        if (t == 6 && l == 0)
        {
        _putchar(' ');
        _putchar(' ');
        _putchar(' ');
        _putchar(' ');
        _putchar(' ');
        f += 5;
        }
        printunnumber(0);
        return (2 + f);
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
        if (l == 5 && n < 100000)
        {
            for (d = 0; d < (6 - w + 1); d++)
            {
                _putchar('0');
                r++;
            }
            l = 6;
        }
        if (t == 6 && n < 100000 && l == 0)
        {
            for (d = 0; d < (6 - w + 1); d++)
            {
                _putchar(' ');
                r++;
            }
            t++;
        }
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

unsigned int _hexadecimal(long int n, int l, int t)
{
    unsigned int q, r, d;
    unsigned int arr[50], w = 1, e;
    int f = 0;

    if (n == 0)
    {
        if (l == 5)
        {
            _putchar('0');
            _putchar('0');
            _putchar('0');
            _putchar('0');
            _putchar('0');
            f += 5;
        }
        else if (t == 6)
        {
            _putchar(' ');
            _putchar(' ');
            _putchar(' ');
            _putchar(' ');
            _putchar(' ');
            f += 5;
        }
        printunnumber(0);
        return (2 + f);
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
        if (l == 5 && n < 100000)
        {
            for (d = 0; d < (6 - w + 1); d++)
            {
                _putchar('0');
                r++;
            }
            l++;
        }
        else if (t == 6 && n < 100000 && l < 5 )
        {
            for (d = 0; d < (6 - w + 1); d++)
            {
                _putchar(' ');
                r++;
            }
            t++;
        }
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

unsigned int _Hexadecimal(long int n, int l, int t)
{
    unsigned int q, r, d;
    unsigned int arr[50], w = 1, e;
    int f = 0;


    if (n == 0)
    {
        if (l == 5)
        {
            _putchar('0');
            _putchar('0');
            _putchar('0');
            _putchar('0');
            _putchar('0');
            f += 5;
        }
        else if (t == 6)
        {
            _putchar(' ');
            _putchar(' ');
            _putchar(' ');
            _putchar(' ');
            _putchar(' ');
            f += 5;
        }
        printunnumber(0);
        return (2 + f);
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
        if (l == 5 && n < 100000)
        {
            for (d = 0; d < (6 - w + 1); d++)
            {
                _putchar('0');
                r++;
            }
            l++;
        }
        else if (t == 6 && n < 100000 && l < 5)
        {
            for (d = 0; d < (6 - w + 1); d++)
            {
                _putchar(' ');
                r++;
            }
            t++;
        }
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

int _Put(char *w, int t)
{
    int r = 0, q = 0, u;

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
        if (t != 0)
        {
            for (u = 0; u < (t - q); u++)
            {
                _putchar(' ');
                r++;
            }
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
                _Hexadecimal(w[q], 0, 0);
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
        if ((s[w] >= 65 && s[w] <= 90) || (s[w] >= 97 && s[w] <= 122))
        {
        for (r = 0; r < 52; r++)
        {
            if (s[w] == a[r])
            {
                _putchar(b[r]);
            }
        }
        }
        else
        {
            _putchar(s[w]);
        }
        w++;
    }
    return (d);
}

int _printf(const char *format, ...)
{
    int d = 0,r = 0, e = 0, q, o = 0, b, a, l = 0, z, v, y, g = 0, W, O = 0, K;
    int long t, j;
    char *w;
    char *R;
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
                    if (format[e + 1] == '-')
                    {
                        if (format[e + 2] == '6')
                        {
                            r--;
                            e++;
                            l = 7;
                        }
                        r--;
                        e++;
                    }
                    if (format[e + 1] == '.' || format[e + 1] == '0')
                    {
                        if (format[e + 2] == '6')
                        {
                            e++;
                            l = 5;
                            r--;
                        }
                        else if (format[e + 2] == '0')
                        {
                            e++;
                            r--;
                            l = 6;
                        }
                        else if (format[e + 2] == 'd' || format[e + 2] == 'u' || format[e + 2] == 'o' || format[e + 2] == 'x' || format[e + 2] == 'X' || format[e + 2] == 's')
                        {
                            l = 6;
                        }
                        e++;
                    }
                    if (format[e + 1] == '*')
                    {
                        e++;
                        l = 4;
                        g = 1;
                    }
                    if (format[e + 1] == '6')
                    {
                        e++;
                        l = 4;
                    }
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
                            if (g == 1)
                            {
                                va_arg(s, int);
                            }
                            if (l != 4)
                            {
                            _putchar(va_arg(s, int));
                            r--;
                            e++;
                            }
                            else
                            {
                                y = va_arg(s, int);
                                _putchar(' ');
                                _putchar(' ');
                                _putchar(' ');
                                _putchar(' ');
                                _putchar(' ');
                                _putchar(y);
                                r += 3;
                                e++;
                            }
                            break;
                        case 's':
                            if (g == 1)
                            {
                                va_arg(s, char *);
                            }
                            if (l == 5)
                            {
                                R = va_arg(s, char *);
                                while (R[O] != '\0')
                                {
                                    O++;
                                }
                                if (O > 6)
                                {
                                    O = 6;
                                }
                                _put(R, O);
                                r += O - 3;
                                e++;
                            }
                            else if (l == 6)
                            {
                                e++;
                                r = 0;
                            }
                            else if (l != 4)
                            {
                            w = va_arg(s, char *);
                            q = _Put(w, 0);
                            r += q - 2;
                            e++;
                            }
                            else
                            {
                                w = va_arg(s, char *);
                                q = _Put(w, 6);
                                r += q - 3;
                                e++;
                            }
                            break;
                        case 'd':
                        case 'i':
                            if (g == 1)
                            {
                                va_arg(s, int);
                            }
                            if (l == 7)
                            {
                                z = va_arg(s, int);
                                if (z == INT_MIN)
                                {
                                    _putchar('-');
                                    o += printunnumber(INT_MIN);
                                    o--;
                                }
                                else
                                {
                                    o = printnumber(z, l, 0);
                                }
                                for (K = 0; K < 5; K++)
                                {
                                    if (o + 2 < 6)
                                    {
                                        _putchar(' ');
                                        o = 5;
                                    }
                                }
                                r += o - 1;
                                e++;
                            }
                            else if (l == 6)
                            {
                                W = va_arg(s, int);
                                if (W == 0)
                                {
                                    e++;
                                    r -= 3;
                                }
                                else
                                {
                                    o = printnumber(W, l, 0);
                                    r += o - 2;
                                    e++;
                                }
                            }
                            else if (l == 5)
                            {
                                o = printnumber(va_arg(s, int), l, 6);
                                r += o - 2;
                                e++;
                            }
                            else if (l != 4)
                            {
                            z = va_arg(s, int);
                            if (z == INT_MIN)
                            {
                                _putchar('-');
                                o += printunnumber(INT_MIN);
                                o--;
                            }
                            else
                            {
                                o = printnumber(z, l, 0);
                            }
                            r += o - 1;
                            e++;
                            }
                            else
                            {
                                o = printnumber(va_arg(s, int), l, 6);
                                r += o - 2;
                                e++;
                            }
                            break;
                        case 'b':
                            b = binary(va_arg(s, int));
                            r += b - 3;
                            e++;
                            break;
                        case 'u':
                            if (g == 1)
                            {
                                (unsigned int) va_arg(s, unsigned int);
                            }
                            if (l == 7)
                            {
                                v = (unsigned int) va_arg(s, unsigned int);
                                if (v < 0)
                                {
                                    a = printunnumber(v);
                                }
                                else
                                {
                                    a = printnumber(v, 0, 0);
                                    r++;
                                }
                                for (K = 0; K < 5; K++)
                                {
                                    if (a + 2 < 6)
                                        a += 5;
                                }
                                r += a - 2;
                                e++;
                            }
                            else if (l == 6)
                            {
                                W =  va_arg(s, unsigned int);
                                if (W == 0)
                                {
                                    e++;
                                    r -= 3;
                                }
                                else
                                {
                                    v = W;
                                    if (v < 0)
                                    {
                                        a = printunnumber(v);
                                        r--;
                                    }
                                    else
                                    {
                                        a = printnumber(v, l, 0);
                                    }
                                    r += a - 2;
                                    e++;
                                }
                            }
                            else if (l == 5)
                            {
                                v = (unsigned int) va_arg(s, unsigned int);
                                if (v < 0)
                                {
                                    a = printunnumber(v);
                                    r--;
                                }
                                else
                                {
                                    a = printnumber(v, l, 6);
                                }
                                r += a - 2;
                                e++;
                            }
                            else if (l != 4)
                            {
                                v = (unsigned int) va_arg(s, unsigned int);
                                if (v < 0)
                                {
                                    a = printunnumber(v);
                                }
                                else
                                {
                                    a = printnumber(v, 0, 0);
                                    r++;
                                }
                                r += a - 2;
                                e++;
                            }
                            else
                            {
                                v = (unsigned int) va_arg(s, unsigned int);
                                if (v < 0)
                                {
                                    a = printunnumber(v);
                                    r--;
                                }
                                else
                                {
                                    a = printnumber(v, 0, 6);
                                }
                                r += a - 2;
                                e++;
                            }
                            break;
                        case 'o':
                            if (g == 1)
                            {
                                (unsigned int) va_arg(s, unsigned int);
                            }
                            if (l == 7)
                            {
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
                                    m = _octal(u, 0, 0);
                                }
                                else
                                {
                                    m = _octal((unsigned int) va_arg(s, unsigned int), 0, 0);
                                }
                                for (K = 0; K < 5; K++)
                                {
                                    if (m + 2 < 6)
                                        m += 5;
                                }
                                r += (int)m - 3;
                                e++;
                            }
                            else if (l == 6)
                            {
                                W = va_arg(s, unsigned int);
                                if (W == 0)
                                {
                                    e++;
                                    r -= 3;
                                }
                                else
                                {
                                    m = _octal(W, l, 6);
                                    r += (int)m - 4;
                                    e++;
                                }
                            }
                            else if (l == 5)
                            {
                                m = _octal((unsigned int) va_arg(s, unsigned int), l, 6);
                                r += (int)m - 4;
                                e++;
                            }
                            else if (l != 4)
                            {
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
                                m = _octal(u, 0, 0);
                            }
                            else
                            {
                                m = _octal((unsigned int) va_arg(s, unsigned int), 0, 0);
                            }
                            r += (int)m - 3;
                            e++;
                            }
                            else
                            {
                                m = _octal((unsigned int) va_arg(s, unsigned int), 0, 6);
                                r += (int)m - 4;
                                e++;
                            }
                            break;
                        case 'x':
                            if (g == 1)
                            {
                                va_arg(s, long int);
                            }
                            if (l == 7)
                            {
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
                                    m = _hexadecimal(j, l, 0);
                                }
                                else
                                {
                                    m = _hexadecimal(va_arg(s, long int), l, 0);
                                }
                                for (K = 0; K < 5; K++)
                                {
                                    if (m + 2 < 6)
                                        m += 5;
                                }
                                r += (int)m - 3;
                                e++;
                            }
                            else if (l == 6)
                            {
                                W = va_arg(s, long int);
                                if (W == 0)
                                {
                                    e++;
                                    r -= 3;
                                }
                                else
                                {
                                    m = _hexadecimal(W, l, 6);
                                    r += (int)m - 4;
                                    e++;
                                }
                            }
                            else if (l == 5)
                            {
                                m = _hexadecimal(va_arg(s, long int), l, 6);
                                r += (int)m - 4;
                                e++;
                            }
                            else if (l != 4)
                            {
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
                                m = _hexadecimal(j, l, 0);
                            }
                            else
                            {
                                m = _hexadecimal(va_arg(s, long int), l, 0);
                            }
                            r += (int)m - 3;
                            e++;
                            }
                            else
                            {
                                m = _hexadecimal(va_arg(s, long int), l, 6);
                                r += (int)m - 4;
                                e++;
                            }
                            break;
                        case 'X':
                            if (g == 1)
                            {
                                va_arg(s, long int);
                            }
                            if (l == 7)
                            {
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
                                    m = _Hexadecimal(j, l, 0);
                                }
                                else
                                {
                                    m = _Hexadecimal(va_arg(s, long int), l, 0);
                                }
                                for (K = 0; K < 5; K++)
                                {
                                    if (m + 2 < 6)
                                        m += 5;
                                }
                                r += (int)m - 3;
                                e++;
                            }
                            else if (l == 6)
                            {
                                W = va_arg(s, long int);
                                if (W == 0)
                                {
                                    e++;
                                    r -= 3;
                                }
                                else
                                {
                                    m = _Hexadecimal(W, l, 6);
                                    r += (int)m - 4;
                                    e++;
                                }
                            }
                            else if (l == 5)
                            {
                                m = _Hexadecimal(va_arg(s, long int), l, 6);
                                r += (int)m - 4;
                                e++;
                            }
                            else if (l != 4)
                            {
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
                                m = _Hexadecimal(j, l, 0);
                            }
                            else
                            {
                                m = _Hexadecimal(va_arg(s, long int), l, 0);
                            }
                            r += (int)m - 3;
                            e++;
                            }
                            else
                            {
                                m = _Hexadecimal(va_arg(s, long int), l, 6);
                                r += (int)m - 4;
                                e++;
                            }
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
