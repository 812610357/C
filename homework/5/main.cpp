#include <stdio.h>
#include <stdlib.h>

float Volume(float a, float b, float c);
unsigned int Age(unsigned int n, unsigned int age);

static float S1, S2, S3;

int main()
{
    {
        float a, b, c;
        printf("�����볤����������ⳤ���Զ��ŷָ�\n");
        scanf("%f,%f,%f", &a, &b, &c);
        float v = Volume(a, b, c);
        printf("���Ϊ%.2f�������������ֱ�Ϊ%.2f��%.2f��%.2f\n", v, S1, S2, S3);
        system("pause");
    }
    {
        unsigned int n = 5, age = 10;
        printf("��5����%d��\n", Age(n, age));
        system("pause");
    }
    return 0;
}

//������������
float Volume(float a, float b, float c)
{
    S1 = a * b;
    S2 = b * c;
    S3 = c * a;
    return a * b * c;
}

//����ݹ�
unsigned int Age(unsigned int n, unsigned int age)
{
    if (n == 0)
        return age;
    else
        return Age(n - 1, age + 2);
}