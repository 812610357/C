#include <stdio.h>

int p = 1;

int f(int n);

int main(void)
{
    int i;
    for (i = 1; i <= 5; i++)
    {
        printf("%d\n", f(3));
    }
    return 0;
}

int f(int n)
{
    p = p * n;
    return p;
}