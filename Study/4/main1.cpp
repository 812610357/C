#include <stdio.h>

void fun(int *a, int i, int j)
{
    int t;
    if (i < j)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
        fun(a, ++i, --j);
    }
}
main()
{
    int a[] = {1, 2, 3, 4, 5, 6}, i;
    fun(a, 0, 5);
    for (i = 0; i < 6; i++)
        printf("%d", a[i]);
}