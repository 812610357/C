#include "stdio.h"
main()
{
    int a[11], x, m;
    printf("please input ten numbers:\n");
    for (m = 1; m < 11; m++)
        scanf("%d", a + m);
    printf("please input x:");
    scanf("%d", &x);
    m = 10;
    while (x != *(a + m))
        m--;
    if (m > 0)
        printf("%5d's position is : %4d\n", x, m);
    else
        printf("%d not been found!\n", x);
}