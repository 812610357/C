#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

void Reorder(char (*p)[N]);

int main()
{
    int i;
    char a[10][N] = {"sad", "wqe", "4ew", "32e", "ew1", "45y", "eri", "i8y", "ji6", "766"};
    for (i = 0; i < 10; i++)
        gets(a[i]);
    Reorder(a);
    for (i = 0; i < 10; i++)
        printf("%s\n", a[i]);
    system("pause");
    return 0;
}
//选择排序法
void Reorder(char (*p)[N])
{
    int i, j, min;
    char temp[N];
    for (i = 0; i < 9; i++)
    {
        min = i;
        for (j = i + 1; j < 10; j++)
            if (strcmp(*(p + min), *(p + j)) > 0)
                min = j;
        strcpy(temp, *(p + min));
        strcpy(*(p + min), *(p + i));
        strcpy(*(p + i), temp);
    }
}
