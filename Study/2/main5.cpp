#include <stdio.h>
#include <stdlib.h>

void num()
{
    extern int x, y;
    int a = 15, b = 10;
    x = a - b;
    y = a + b;
}
int x, y;
main()
{
    int a = 7, b = 5;
    x = a + b;
    y = a - b;
    num();
    printf("%d,%d\n", x, y);
    system("pause");
}