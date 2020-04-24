#include <stdio.h>
#include <stdlib.h>

int main()
{
    {
        int a[3][3] = {{1, 2}, {3, 4}, {5, 6}};
        int i, j, s = 0;
        for (i = 0; i < 3; i++)
            for (j = 0; j <= i; j++)
                s += a[i][j];
        printf("%d\n", s);
        system("pause");
    }
    {
        int i, k, a[10], p[3];
        k = 5;
        for (i = 0; i < 10; i++)
            a[i] = i;
        for (i = 0; i < 3; i++)
            p[i] = a[i * (i + i)];
        for (i = 0; i < 3; i++)
            k += p[i] * 2;
        printf("%d\n", k);
        system("pause");
    }
    {
        int b[3][3] = {0, 1, 2, 0, 1, 2, 0, 1, 2}, i, j, t = 0;
        for (i = 0; i < 3; i++)
            for (j = i; j <= i; j++)
                t = t + b[i][b[j][i]];
        printf("%d\n", t);
        system("pause");
    }
    {
        int a[10], t;
        int i;
        printf("piease input 10 numbers");
        for (i = 0; i < 10; i++)
        {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < 10; i++)
        {
            if (a[0] > a[i])
            {
                t = a[0];
                a[0] = a[i];
                a[i] = t;
            }
        }
        for (i = 0; i < 10; i++)
            printf("%d ", a[i]);
        system("pause");
    }
    return 0;
}