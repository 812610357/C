#include <stdio.h>
#include <stdlib.h>

int main()
{
    {
        int a[12] = {1, 4, 7, 9, 11, 18, 34, 44, 50, 65, 70, 88}, x, i, start, end;
        printf("input number x");
        scanf("%d", &x);
        for (start = 0, end = 11; start <= end;)
        {
            i = start + (end - start) / 2;
            if (x == a[i])
                printf("%d", i + 1);
            else if (x > a[i])
                end = i - 1;
            else
                start = i + 1;
        }
        if (start > end)
            printf("not find");
        system("pause");
    }
    {
        int a[] = {4, 0, 2, 3, 1}, i, j, t;
        for (i = 1; i < 5; i++)
        {
            t = a[i];
            j = i - 1;
            while (j >= 0 && t > a[j])
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = t;
        }
        for (i = 0; i < 5; i++)
            printf("%4d", a[i]);
        system("pause");
    }
    return 0;
}