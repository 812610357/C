#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10], min, i;
    printf("请输入10个整数\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for (i = 1; i < 10; i++)
        if (a[i] < a[0])
            a[0] = a[i];
    printf("最小的数字是%d", a[0]);
    system("pause");
    return 0;
}