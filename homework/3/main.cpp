#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	{
		char c;
		int let = 0, num = 0, spa = 0, oth = 0;
		printf("�������ַ���");
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
		printf("�ַ�ͳ��\n");
		printf("Ӣ����ĸ��%-4d��\n", let);
		printf("    ���֣�%-4d��\n", num);
		printf("    �ո�%-4d��\n", spa);
		printf("�����ַ���%-4d��\n", oth);
		system("pause");
	}
	{
		printf("10000���ڵ�ͬ������\n");
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