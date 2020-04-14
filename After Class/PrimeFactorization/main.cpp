#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void HideCursor();
void Gotoxy(int x, int y);
void DrawBox();

int main()
{

	double a, b, i=1;
	int len = 0;
	printf("��������Ҫ����ķ�Χ����������ֱ���Ϊ����0�����������硰3-100��\n");
	do//�������������������������롣
	{
		scanf_s("%lf-%lf", &a, &b);
		if (floor(a + 0.5) != a || floor(b + 0.5) != b || a <= 0 || b <= 0)
			printf("�������������������������\n");
		else
			i++;
	}while (i == 1);
	
	FILE* fp;
	fp = fopen("data.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��");
		exit(0);
	}

	HideCursor();
	system("cls");
	printf("���ڴ���%0.lf-%0.lf֮�����\n", a, b);
	DrawBox();

	if (a > b)//���a>b���򽻻�a��b��ֵ��
	{
		double c = a;
		a = b;
		b = c;
	}

	double m = a;
	if (m == 1)//�������������������ݰ���1ʱ��ֱ�������Ȼ��������һ�����ݡ�
	{
		fprintf(fp,"1=1\n\n");
		m++;
	}

	while(m<=b)
	{
		Gotoxy(0, 6);
		printf("���ڴ���%.0lf�����Ժ�", m);
		fprintf(fp,"%.0lf=", m);
		while (fmod(m, i) && i <= sqrt(m))//�ж��Ƿ�Ϊ����
			i++;
		if (i > sqrt(m))
			i = m;
		double n = m / i;
		fprintf(fp,"%.0lf", i);

		while(n-1)//�Ժ�����������������
		{
			while (fmod(n, i) && i <= sqrt(n))
				i++;
			if (i > sqrt(n))
				i = n;
			n = n / i;
			fprintf(fp,"*%.0lf", i);
			Gotoxy(52, 3);
			printf("�����%.2lf%%", 100 * (m - a) / (b - a));
			if (25 * (m - a) / (b - a) - 1 > len)
			{
				len++;
				Gotoxy(2 * len, 3);
				printf("��");
			}
		}

		fprintf(fp,"\n\n");
		m++;
		i = 2;
	}

	Gotoxy(0, 3);
	printf("�U �������������������������������������������������U �����100.00%");
	Gotoxy(0, 6);
	printf("��������ɣ��ļ��ѱ��������������ļ���\n�鿴������");
	system("pause");
	fclose(fp);
	system("data.txt");
	return 0;
}

void HideCursor()//���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//��ߵ�0�����겻�ɼ�
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void Gotoxy(int x, int y)//����ƶ�
{
	HANDLE hout; //����������hout
	COORD coord; //����ṹ��coord
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);//��ñ�׼�������Ļ�����
	SetConsoleCursorPosition(hout, coord);//�ƶ����
}

void DrawBox()//���߿�
{
	printf("\n�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("�U                                                 �U");
	printf("\n�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
}