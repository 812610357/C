#include <stdio.h>
main()
{
    int a[11] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90}, x, i, p; //
    scanf("%d", &x);
    for (i = 0, p = 10; i < 10; i++)
        if (x < a[i])
        {
            p = i;
            break; //
        }
    for (i = 9; i >= p; i--)
        a[i + 1] = a[i]; //
    a[i + 1] = x;        //
    for (i = 0; i <= 10; i++)
        printf("%5d\n", a[i]);
    printf("\n");
}