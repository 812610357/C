#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    {
        int n = 0, i = 1;
        n += (++i)++;
        printf("n=%d,i=%d", n, i);
    }
    {
        int i, num, neg = 0, posit = 0;
        for (i = 1; i <= 6; i++)
        {
            scanf("%d", &num);
            if (num != 0)
            {
                if (num > 0)
                    posit++;
                else
                    neg++;
            }
        }
        printf("啊neg=%d,posit=%d\n", neg, posit);
        system("pause");
    }
    {
        int m, n;
        scanf("%d,%d", &m, &n);
        while (m != n)
        {
            while (m > n)
                m -= n;
            while (n > m)
                n -= m;
        }
        printf("m=%d\n", m);
        system("pause");
    }
    {
        int m, i, k, h = 0, leap = 1;
        printf("\n");
        for (m = 101; m <= 200; m++)
        {
            k = sqrt(m + 1);
            for (i = 2; i <= k; i++)
                if (m % i == 0)
                {
                    leap = 0;
                    break;
                }
            if (leap)
            {
                printf("%-4d", m);
                h++;
                if (h % 10 == 0)
                    printf("\n");
            }
            leap = 1;
        }
        printf("\nThe?total?is?%d", h);
    }
    {
        float x, y, z;
        scanf("%f,%f", &x, &y);
        z = x / y;
        while (1)
        {
            if (fabs(z) > 1.0)
            {
                x = y;
                y = z;
                z = x / y;
            }
            else
                break;
        }
        printf("%f\n", y);
        system("pause");
    }
    {
        int i, j, N = 4;
        for (i = 1; i <= N; i++)
        {
            for (j = 1; j < i; j++)
                printf(" ");
            printf("*");
            printf("\n");
        }
        system("pause");
    }
    {
        int i, j = 0, a = 0;
        for (i = 1; i <= 4; i++)
        {
            for (j = 1; j <= 10 - i; j++)
                printf(" ");
            for (j = 1; j <= 2 * i - 1; j++)
                printf("*");
            printf("\n");
        }
        system("pause");
    }
    {
        printf("%d", sizeof(long double));
        int m = 0;
        char c;
        while (c = getchar() != '\n')
            m++;
        printf("%d", m);
        system("pause");
    }
    {
        int a = 1, b = 2, c = 0, t;
        while (a < b < c)
        {
            t = a;
            a = b;
            c--;
        }
        printf("%d,%d,%d", a, b, c);
        system("pause");
    }
    {
        int x = 0, s = 0;
        while (!x != 0)
            s += ++x;
        printf("%d", s);
        system("pause");
    }
    {
        int i;
        char k;
        for (i = 1; i < 3; i++)
        {
            scanf("%c", &k);
            switch (k)
            {
            case '0':
                printf("a");
            case '1':
                printf("n");
            }
        }
        system("pause");
    }
    {
        int i;
        for (i = 2; i != 0;)
            printf("%d\n", i--);
        system("pause");
    }
    {
        int n, i = 0;
        long double s = 0;
        printf("请输入0至511之间的整数 n=");
        scanf("%d", &n);
        while (i <= n)
        {
            s = s + pow(4, i);
            i++;
        }
        printf("s=%.0f\n", s);
        system("pause");
    }
    {
        int n, i = 1;
        printf("请输入1至9之间的整数 n=");
        scanf("%d", &n);
        unsigned long int a = 0, b = 1;
        while (i <= n)
        {
            a = 10 * a + i;
            b = b * 10 + 1;
            i++;
            printf("%dX9+%d=%d\n", a, i, b);
        }
        system("pause");
    }
    {
        int i, j, k = 10;
        for (i = 0; i < 2; i++)
        {
            k++;
            {
                int k = 0;
                for (j = 0; j <= 3; j++)
                {
                    if (j % 2)
                        continue;
                    k++;
                }
            }
            k++;
        }
        printf("k=%d\n", k);
        system("pause");
    }
    {
        int a = 4, b = 5, c = 6, d = 7, e;
        e = a > b ? a : c > d ? c : d;
        printf("%d\n", e);
        int f = 2e16;
        printf("%d\n", f--);
        char c1, c2, c3, c4, c5, c6;
        int a1, a2, a3;
        scanf("%d%d%d", &a1, &a2, &a3);
        printf("%d,%d,%d\n", a1, a2, a3);
        int x = 0;
        int y = 0;
        char z = 'a';
        scanf("%d%c%d", &x, &z, &y);
        printf("%d,%c,%d\n", x, z, y);
        float i = 10;
        int j = 10;
        printf("%d,%f\n", ++i, --j);
        b = 0x17;
        printf("%d\n", (b++, ++b));
        printf("%d,%d\n", b++, ++b);
        printf("%d\n", b);
        a = 4;
        b = 3;
        a += 1;
        e = a;
        c = ++a + b;
        d = e++ + b;
        printf("%d,%d,%d,%d", a, b, c, d);
        a = 5;
        a1 = a / b;
        a2 = (float)a / b;
        printf("%f,%f\n", a1, a2);
        b = 4;
        a = 10;
        a %= b + 1;
        printf("%d\n", a);
        char ch;
        ch = getchar();
        ch = ch + 32;
        putchar(ch);
        putchar('\n');
    }
    return 0;
}