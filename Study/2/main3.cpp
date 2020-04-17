#include <stdio.h>
#include <stdlib.h>

long f1(int p)
{
    int k, r = 0;
    int f2(int r);
    for (k = 1; k <= r; k++)
        r = r + k;
    return f2(r);
}
int f2(int q)
{
    int i, c = 1;
    for (i = 1; i <= q; i++)
        c = c * i;
    return c;
}
int main()
{
    int i, s = 0;
    for (i = 2; i <= 5; i++)
        s = s + f1(i);
    printf("s=%d\n", s);
    system("pause");
    return 0;
}