#include <stdio.h>
#include <stdlib.h>

#define N 5

int SumRow(int (*p)[N]);

int main()
{
    int a[N][N] = {{1, 2, 3, 4, 5},
                   {4, 5, 6, 7, 8},
                   {7, 8, 9, 1, 2},
                   {0, 8, 7, 3, 4},
                   {6, 5, 4, 3, 2}};
    for (int i = 0; i < 5; i++)
        printf("第%d行的和为%d\n", i + 1, SumRow(a + i));
    system("pause");
    return 0;
}

int SumRow(int (*p)[N])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += *(*p + i);
    return sum;
}