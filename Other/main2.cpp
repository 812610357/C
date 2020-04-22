#include <stdio.h>

int main()
{
    int a[10], i, t, min;
    printf("input 10 number\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    min = 0;
    for (i = 0; i < 10; i++)
    {
        if (a[i] < a[min])
            min = i;
    }
    t = a[0];
    a[0] = a[min];
    a[min] = t;
    for (i = 0; i < 10; i++)
        printf("%d  ", a[i]);
    return 0;
}