#include <stdio.h>
#include <stdlib.h>

int SumRow(int (*p)[5]);

int main()
{
    int a[5][5] = {{1, 2, 3, 4, 5},
                   {4, 5, 6, 7, 8},
                   {7, 8, 9, 1, 2},
                   {0, 8, 7, 3, 4},
                   {6, 5, 4, 3, 2}};
    for (int i = 0; i < 5; i++)
        printf("第%d行的和为%d\n", i + 1, SumRow(a + i));
    system("pause");
    return 0;
}

int SumRow(int (*p)[5])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += *(*p + i);
    return sum;
}