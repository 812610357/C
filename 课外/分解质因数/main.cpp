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
	printf("请输入您要计算的范围，输入的数字必须为大于0的整数，例如“3-100”\n");
	do//如果输入的数据有误，则重新输入。
	{
		scanf_s("%lf-%lf", &a, &b);
		if (floor(a + 0.5) != a || floor(b + 0.5) != b || a <= 0 || b <= 0)
			printf("您输入的数据有误，请重新输入\n");
		else
			i++;
	}while (i == 1);
	
	FILE* fp;
	fp = fopen("data.txt", "w");
	if (fp == NULL)
	{
		printf("文件打开失败");
		exit(0);
	}

	HideCursor();
	system("cls");
	printf("正在处理%0.lf-%0.lf之间的数\n", a, b);
	DrawBox();

	if (a > b)//如果a>b，则交换a、b的值。
	{
		double c = a;
		a = b;
		b = c;
	}

	double m = a;
	if (m == 1)//特殊情况，当输入的数据包含1时，直接输出，然后跳到下一个数据。
	{
		fprintf(fp,"1=1\n\n");
		m++;
	}

	while(m<=b)
	{
		Gotoxy(0, 6);
		printf("正在处理%.0lf，请稍后", m);
		fprintf(fp,"%.0lf=", m);
		while (fmod(m, i) && i <= sqrt(m))//判断是否为质数
			i++;
		if (i > sqrt(m))
			i = m;
		double n = m / i;
		fprintf(fp,"%.0lf", i);

		while(n-1)//对和数查找所有质因数
		{
			while (fmod(n, i) && i <= sqrt(n))
				i++;
			if (i > sqrt(n))
				i = n;
			n = n / i;
			fprintf(fp,"*%.0lf", i);
			Gotoxy(52, 3);
			printf("已完成%.2lf%%", 100 * (m - a) / (b - a));
			if (25 * (m - a) / (b - a) - 1 > len)
			{
				len++;
				Gotoxy(2 * len, 3);
				printf("█");
			}
		}

		fprintf(fp,"\n\n");
		m++;
		i = 2;
	}

	Gotoxy(0, 3);
	printf("║ ████████████████████████║ 已完成100.00%");
	Gotoxy(0, 6);
	printf("计算已完成，文件已保存至程序所在文件夹\n查看计算结果");
	system("pause");
	fclose(fp);
	system("data.txt");
	return 0;
}

void HideCursor()//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//后边的0代表光标不可见
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void Gotoxy(int x, int y)//光标移动
{
	HANDLE hout; //定义句柄变量hout
	COORD coord; //定义结构体coord
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);//获得标准输出（屏幕）句柄
	SetConsoleCursorPosition(hout, coord);//移动光标
}

void DrawBox()//画边框
{
	printf("\n╔═════════════════════════════════════════════════╗\n");
	printf("║                                                 ║");
	printf("\n╚═════════════════════════════════════════════════╝\n");
}