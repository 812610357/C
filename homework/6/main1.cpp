//法一
#include <stdio.h>
#include <stdlib.h>

void Switch(int a[], int m, int n);

int main()
{
    int a[10] = {12, 23, -13, 56, -1, 14, 32, 57, 0, -20};
    int min, i;
    for (i = 1; i < 10; i++)
    {
        if (a[i] < a[0])
        {
            Switch(a, i, 0);
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n最小的数字是%d\n", a[0]);
    system("pause");
    return 0;
}

void Switch(int a[], int m, int n)
{
    int s = a[m];
    a[m] = a[n];
    a[n] = s;
}