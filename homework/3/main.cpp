#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	{
		char c;
		int let = 0, num = 0, spa = 0, oth = 0;
		printf("请输入字符：");
		while ((c = getchar()) != '\n')
		{
			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			{
				let++;
				continue;
			}
			if (c >= '0' && c <= '9')
			{
				num++;
				continue;
			}
			if (c == ' ')
			{
				spa++;
				continue;
			}
			oth++;
		}
		printf("字符统计\n");
		printf("英文字母：%-4d个\n", let);
		printf("    数字：%-4d个\n", num);
		printf("    空格：%-4d个\n", spa);
		printf("其他字符：%-4d个\n", oth);
		system("pause");
	}
	{
		printf("10000以内的同构数有\n");
		long i = 1;
		while (i <= 10000)
		{
			long t = i;
			int n = 1;
			while (t)
			{
				t = t / 10;
				n = n * 10;
			}
			if (i * i % n == i)
				printf("%6d", i);
			i++;
		}
		printf("\n");
		system("pause");
	}
	return 0;
}