#include "stdio.h"
#define M 10
main()
{
    int a[M], m, n, temp;
    for (m = 0; m < M; m++)
        scanf("%d", a + m);
    m = 0;
    n = M - 1;
    while (m < n)
    {
        temp = *(a + m);
        *(a + m) = *(a + n); //
        *(a + n) = temp;
        m++;
        n--;
    }
    for (m = 0; m < M; m++)
        printf("%3d", *(a + m));
}