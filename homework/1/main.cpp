#include <stdio.h>
#include <stdlib.h>

int main()
{
    {
        float x, y;
        printf("请输入x=");
        scanf("%f", &x);
        {
            if (x > 10)
                y = x - 5;
            else
                y = 4 * x + 2;
        }
        printf("y=%.2f\n", y);
        system("pause");
    }
    {
        int m;
        printf("您想查询的月份是:");
        scanf("%d", &m);
        switch (m)
        {
        case 1:
        case 2:
        case 3:
            printf("您输入的月份在春季\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("您输入的月份在夏季\n");
            break;
        case 7:
        case 8:
        case 9:
            printf("您输入的月份在秋季\n");
            break;
        case 10:
        case 11:
        case 12:
            printf("您输入的月份在冬季\n");
            break;
        default:
            printf("您输入的值有误\n");
            break;
        }
        system("pause");
    }
    return 0;
}