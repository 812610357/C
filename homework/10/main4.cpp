#include <stdio.h>
#include <stdlib.h>

#define N 100

int GetLength(char *p);

int main()
{
    char a[N];
    printf("请输入一个字符串\n");
    gets(a);
    printf("字符串长度为%d\n", GetLength(a));
    system("pause");
    return 0;
}

int GetLength(char *p)
{
    int i;
    while (*p)
    {
        p++;
        i++;
    }
    return i;
}