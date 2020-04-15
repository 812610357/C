#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	{
		int n, i = 0;
		double s = 0;
		printf("请输入0至511之间的整数 n=");
		scanf("%d", &n);
		while (i <= n)
		{
			s = s + pow(4, i);
			i++;
		}
		printf("s=%.0f\n", s);
		system("pause");
	}
	{
		int n, i = 1;
		printf("请输入1至9之间的整数 n=");
		scanf("%d", &n);
		int a = 0, b = 1;
		while (i <= n)
		{
			a = 10 * a + i;
			b = b * 10 + 1;
			i++;
			printf("%dX9+%d=%d\n", a, i, b);
		}
		system("pause");
	}
	return 0;
}