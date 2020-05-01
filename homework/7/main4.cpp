#include <stdio.h>
#include <stdlib.h>

#define N 10

static int len = N;

int Index(int num, int data[]);
void Del(int index, int data[]);

int main()
{
    int data[N], i, num, index;
    printf("请输入一个包含%d个元素的数组:\n", N);
    for (i = 0; i < len; i++)
        scanf("%d", &data[i]);
    printf("输入的数组为：\n");
    for (i = 0; i < len; i++)
        printf("%d  ", data[i]);
    printf("\n");
    printf("请输入你想删除的数字：");
    scanf("%d", &num);
    do
    {
        index = Index(num, data);
        if (index == -1)
            break;
        else
            Del(index, data);
    } while (1);
    printf("调整后的数组为：\n");
    for (i = 0; i < len; i++)
        printf("%d  ", data[i]);
    printf("\n");
    system("pause");
    return 0;
}
//查找元素的下标
int Index(int num, int data[])
{
    for (int i = 0; i < len; i++)
        if (num == data[i])
        {
            return i;
            break;
        }
    return -1;
}
//把该删除的元素后面的元素前移
void Del(int index, int data[])
{
    len--;
    for (int i = index; i < len; i++)
        data[i] = data[i + 1];
}