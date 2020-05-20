#define N 10
#include <stdio.h>
#include <string.h>
int main()
{
    int i, j, s;          //
    char a[N][30], t[30]; //
    printf("\n初始数组:\n");
    for (i = 0; i < N; i++)
        gets(a[i]);
    for (i = 0; i < sizeof(a) / 30; i++)         //
        for (j = 0; j < sizeof(a) / 30 - i; j++) //
            if (strcmp(a[j], a[j + 1]) > 0)      //
            {
                strcpy(t, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], t);
            }
    printf("\n排序后:\n");
    for (i = 0; i < N; i++)
        printf("%s\n", a[i]);
}
