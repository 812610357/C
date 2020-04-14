#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int Fun(int a, int b, int c);

int main()
{
	{
		double n, i = 1;
		printf("请输入一个正整数\nn=");
		do
		{
			scanf("%lf", &n);
			if (floor(n + 0.5) != n || n <= 0) //如果输入的数据有误，则重新输入
				printf("您输入的数据有误，请重新输入\nn=");
			else
				i++;
		} while (i == 1);
		if (n == 1) //特殊情况，当输入1时反馈
			printf("1不是素数\n");
		else
		{
			while (fmod(n, i) && i <= sqrt(n)) //判断是否为质数
				i++;
			if (i > sqrt(n))
				printf("%.0lf是素数\n", n);
			else
				printf("%.0lf不是素数\n", n);
		}
		system("pause");
	}
	{
		int a, b, c;
		printf("\n请输入三角形的三条边长，以逗号分隔\n");
		do
		{
			scanf("%d,%d,%d", &a, &b, &c);
			if (a <= 0 || b <= 0 || c <= 0) //如果输入的数据有误，则重新输入
				printf("您输入的数据有误，请重新输入\n");
			else
				break;
		} while (1);
		switch (Fun(a, b, c))
		{
		case 0:
			printf("以上边长不能构成三角形\n");
			break;
		case 1:
			printf("以上边长能构成一般三角形\n");
			break;
		case 2:
			printf("以上边长能构成等腰三角形\n");
			break;
		case 3:
			printf("以上边长能构成等边三角形\n");
			break;
		}
		system("pause");
	}
	return 0;
}

//判断三角形的形状
int Fun(int a, int b, int c)
{
	if (a + b <= c || b + c <= a || c + a <= b)
		return 0;
	else if (a == b && b == c)
		return 3;
	else if (a == b || b == c || c == a)
		return 2;
	else
		return 1;
}
