#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int Fun(int a, int b, int c);

int main()
{
	{
		double n, i = 1;
		printf("������һ��������\nn=");
		do
		{
			scanf("%lf", &n);
			if (floor(n + 0.5) != n || n <= 0) //��������������������������
				printf("�������������������������\nn=");
			else
				i++;
		} while (i == 1);
		if (n == 1) //���������������1ʱ����
			printf("1��������\n");
		else
		{
			while (fmod(n, i) && i <= sqrt(n)) //�ж��Ƿ�Ϊ����
				i++;
			if (i > sqrt(n))
				printf("%.0lf������\n", n);
			else
				printf("%.0lf��������\n", n);
		}
		system("pause");
	}
	{
		int a, b, c;
		printf("\n�����������ε������߳����Զ��ŷָ�\n");
		do
		{
			scanf("%d,%d,%d", &a, &b, &c);
			if (a <= 0 || b <= 0 || c <= 0) //��������������������������
				printf("�������������������������\n");
			else
				break;
		} while (1);
		switch (Fun(a, b, c))
		{
		case 0:
			printf("���ϱ߳����ܹ���������\n");
			break;
		case 1:
			printf("���ϱ߳��ܹ���һ��������\n");
			break;
		case 2:
			printf("���ϱ߳��ܹ��ɵ���������\n");
			break;
		case 3:
			printf("���ϱ߳��ܹ��ɵȱ�������\n");
			break;
		}
		system("pause");
	}
	return 0;
}

//�ж������ε���״
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
