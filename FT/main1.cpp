#include <stdio.h>

int fun(int n)
{
    int i;
    for (i = 0; n >= 1; i++)
    {
        printf("%d,", n % 10);
        n /= 10;
    }
}

int main()
{
    int n = 4215;
    fun(n);
    return 0;
}