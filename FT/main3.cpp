#include <stdio.h>
int x1 = 30, x2 = 40;
void sub(int x, int y);
int main()
{
    int x3 = 10, x4 = 20;
    sub(x3, x4);
    sub(x2, x1);
    return 0;
}

void sub(int x, int y)
{
    x1 = x;
    x = y;
    y = x1;
}