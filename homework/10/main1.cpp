#include <stdio.h>
void find(int *a, int *max, int *min)
{
    int i;
    *max = *min = 0;
    for (i = 1; i < 7; i++) //
        if (a[i] > a[*max])
            *max = i; //
        else if (a[i] < a[*min])
            *min = i; //
    return;
}
main()
{
    int a[] = {5, 8, 7, 6, 2, 7, 3};
    int max, min;
    find(a, &max, &min);
    printf("%d,%d\n", max, min);
}
