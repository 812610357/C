#include <stdio.h>
int main()
{
    int a[10], t;
    int i;
    printf("piease input 10 numbers");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < 10; i++)
    {
        if (a[0] > a[i])
        {
            t = a[0];
            a[0] = a[i];
            a[i] = t;
        }
    }
    for (i = 0; i < 10; i++)
        printf("%d ", a[i]);
    return 0;
}