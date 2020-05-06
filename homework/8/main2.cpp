#include <stdio.h>
#define N 20
int fun(float *s, int n, float *aver)
{
    float av, t;
    int count, i;
    count = 0;
    t = 0.0;
    for (i = 0; i < n; i++)
        t += s[i];
    av = t / n;
    for (i = 0; i < n; i++)
        if (s[i] < av)
            count++;
    *aver = av;   //
    return count; //
}

main()
{
    float a, s[30], *aver;
    int m = 0;
    printf("\nPlease enter marks ( -1 to end):\n ");
    scanf("%f", &a);
    while (a > 0)
    {
        s[m] = a;
        m++;
        scanf("%f", &a);
    }
    printf("\nThe number of students : %d\n", fun(s, m, aver));
    printf("Ave = %6.2f\n", *aver);
}
