#include <stdio.h>
#include <stdlib.h>

int main()
{
    {
        float x, y;
        printf("������x=");
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
        printf("�����ѯ���·���:");
        scanf("%d", &m);
        switch (m)
        {
        case 1:
        case 2:
        case 3:
            printf("��������·��ڴ���\n");
            break;
        case 4:
        case 5:
        case 6:
            printf("��������·����ļ�\n");
            break;
        case 7:
        case 8:
        case 9:
            printf("��������·����＾\n");
            break;
        case 10:
        case 11:
        case 12:
            printf("��������·��ڶ���\n");
            break;
        default:
            printf("�������ֵ����\n");
            break;
        }
        system("pause");
    }
    return 0;
}