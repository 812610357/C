#include <stdio.h>
#include <stdlib.h>

float Volume(float a, float b, float c);
unsigned int Age(unsigned int n, unsigned int age);

static float S1, S2, S3;

int main()
{
    {
        float a, b, c;
        printf("请输入长方体的三条棱长，以逗号分隔\n");
        scanf("%f,%f,%f", &a, &b, &c);
        float v = Volume(a, b, c);
        printf("体积为%.2f，三个面的面积分别为%.2f，%.2f，%.2f\n", v, S1, S2, S3);
        system("pause");
    }
    {
        unsigned int n = 5, age = 10;
        printf("第5个人%d岁\n", Age(n, age));
        system("pause");
    }
    return 0;
}

//计算体积和面积
float Volume(float a, float b, float c)
{
    S1 = a * b;
    S2 = b * c;
    S3 = c * a;
    return a * b * c;
}

//年龄递归
unsigned int Age(unsigned int n, unsigned int age)
{
    if (n == 1 || n == 0)
        return age;
    else
        return Age(n - 1, age + 2);
}