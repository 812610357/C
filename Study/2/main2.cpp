#include <stdio.h>
int func(int a, int b);

main()
{
    int k = 4, m = 1, p;

    p = func(k, m);

    printf("%d,", p);

    p = func(k, m);

    printf("%d\n", p);
    return 0;
}

int func(int a, int b)
{

    static int m = 0, i = 2;

    i += m + 1;

    m = i + a + b;

    return (m);
}