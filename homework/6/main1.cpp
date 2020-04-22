//法一
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10] = {12, 23, -13, 56, -1, 14, 32, 57, 0, -20};
    int min, i;
    for (i = 1; i < 10; i++)
        if (a[i] < a[0])
            a[0] = a[i];
    for (i = 0; i < 10; i++)
        printf("%d  ", a[i]);
    printf("\n最小的数字是%d\n", a[0]);
    system("pause");
    return 0;
}