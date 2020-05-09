#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindPrimeNumber(int x);

int main()
{
    int a[10] = {121, 240, 45, 13, 57, 64, 17, 300, 39, 21}, b[10] = {}, i, *p = &b[0];
    for (i = 0; i < 10; i++)
        if (FindPrimeNumber(a[i]))
            *p++ = a[i];
    for (i = 0; b[i] != 0; i++)
        printf("%d ", b[i]);
    printf("\n");
    system("pause");
    return 0;
}

int FindPrimeNumber(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i)
            continue;
        else
            return 0;
    return 1;
}

void WriteToArray(int x[], int *p)
{
}