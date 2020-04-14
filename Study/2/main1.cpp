#include <stdio.h>
int fun1(int a, int b);
int fun2(int a, int b);

int fun1(int a, int b)
{
    int c;
    a += a;
    b += b;
    c = fun2(a, b);
    return c * c;
}
int fun2(int a, int b)
{
    int c;
    c = a * b % 3;
    return c;
}
int main()
{
    int x = 11, y = 19;
    printf("%d\n", fun1(x, y));
    return 0;
}