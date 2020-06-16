#include <stdio.h>
int fun(int a[], int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < 60)
            k++;
    return k;
}
int main()
{
    int a[10] = {
        82,
        23,
        34,
        45,
        87,
        87,
        87,
        87,
        87,
        87,
    };
    int b = fun(a, 10);
    return 0;
}