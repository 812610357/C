#include <stdio.h>

main()
{
    int a[4][4], i, j, k;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            a[i][j] = i - j;
    for (i = 1; i < 4; i++)
        for (j = i + 1; j < 4; j++)
        {
            k = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = k;
        }
    for (i = 0; i < 4; i++)
    {
        printf("\n");
        for (j = 0; j < 4; j++)
            printf("%4d", a[i][j]);
    }
}