#include <stdio.h>
int main()
{
    int a[10], i, temp;
    int *p, *q;
    printf("请输入排序数据：\n");
    for (p = a; p < a + 10; p++)
        scanf("%d", p);
    printf("排序前数列：\n");
    for (p = a; p < a + 10; p++)
        printf("%d  ", *p);
    for (i = 0; i < 10 - 1; i++)
    {
        q = &a[i];                           //
        for (p = &a[i + 1]; p < a + 10; p++) //
            if (*p < *q)
                q = p;
        temp = a[i];
        a[i] = *q;
        *q = temp;
    }
    printf("\n排序后数列：\n");
    for (p = a; p < a + 10; p++)
        printf("%d  ", *p);
    printf("\n");
}
