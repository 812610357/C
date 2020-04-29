#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 100

int GetLen(char str[]);

int main()
{
    char a[MAXLEN + 1], b[MAXLEN + 1];
    int len_a, len_b, i;
    printf("请输入第一个字符串：");
    gets(a);
    printf("请输入第二个字符串：");
    gets(b);
    len_a = GetLen(a);
    len_b = GetLen(b);
    printf("字符串1为：");
    for (i = 0; i < len_a; i++)
        printf("%c   ", a[i]);
    printf("\n字符串2为：");
    for (i = 0; i < len_b; i++)
        printf("%c   ", b[i]);
    printf("\nASCII码差：");
    for (i = 0; i < len_a && i < len_b; i++)
        printf("%-4d", abs(b[i] - a[i]));
    printf("\n第%d位之后的其中一个字符串中无字符，不再进行比较\n", i);
    system("pause");
    return 0;
}
//计算字符串的长度
int GetLen(char str[])
{
    int i = 0;
    do
    {
        i++;
    } while (str[i] != '\0');
    return i;
}