#include <stdio.h>
#include <stdlib.h>

int main()
{
	{
		long n, m;
		int i = 1;
		printf("n=");
		scanf("%d", &n);
		m = n;
		while (m >= 10)
		{
			m = m / 10;
			i = i * 10;
		}
		n = n % i;
		printf("%d\n", n);
		system("pause");
	}
	{
		int i;
		for (i = 2; i <= 100; i = i + 2)
			;
		{
			printf("%d\n", i);
		}
	}
	{
		int i = 1, n;
		double sum = 0;
		printf("请输入n=");
		scanf("%d", &n);
		while (i <= n)
		{
			sum = (double)1 / i + sum;
			i++;
		}
		printf("sum=%lf\n", sum);
		system("pause");
	}
	{
		int i, n = 0;
		for (i = 1; i < 11; ++i)
		{
			n = 5 * i;
			printf("5*%d=%d\n", i, n);
		}
		system("pause");
	}
	{
		int i = 1, n = 0;
		while (i < 11)
		{
			n = 5 * i;
			printf("5*%d=%d\n", i, n);
			i = i + 1;
		}
		system("pause");
	}
	{
		int a, b, c;
		float x;
		printf("the number ");
		scanf("a=%d,b=%d,c=%d", &a, &b, &c);
		x = (float)a / (b - c);
		printf("%f\n", x);
		system("pause");
	}
	{
		float F, C;
		printf("Please enter the corresponding Celsius temperatureC: ");
		scanf("%f", &C);
		F = 9 * C / 5 + 32;
		printf("Corresponding degrees Fahrenheit:%f\n", F);
		printf("Please enter the corresponding Celsius temperature: ");
		scanf("%f", &F);
		C = (F - 32) * 5 / 9;
		printf("Corresponding degrees Fahrenheit:%f\n", C);
		system("pause");
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
