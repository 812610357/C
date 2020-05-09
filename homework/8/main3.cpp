#include <stdio.h>
#define N 7 //
main()
{
    char a[N][N];
    int i, j, z;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            a[i][j] = ' '; //
    z = 0;
    for (i = 0; i < (N + 1) / 2; i++)
    {
        for (j = z; j < N - z; j++)
            a[i][j] = '*';
        z = z + 1;
    }
    z = (N - 1) / 2; //
    for (i = (N + 1) / 2; i < N; i++)
    {
        z = z - 1;
        for (j = z; j < N - z; j++)
            a[i][j] = '*';
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%c", a[i][j]); //
        printf("\n");
    }
}
