#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct car
{
	char carnumber[20];
	int floor;
	int position;
	int time;
	time_t timeIn; // 进入停车场时间
	time_t timeOut;
};

void mainmenu(); //主菜单
//一级菜单
void vehicle_information_management(); //车辆信息管理
void information_initialization();	   //信息初始化
void information_maintenance();		   //信息维护

void parking_information_management();	   //车位信息管理
void parking_information_initialization(); //车位信息初始化
void parking_information_maintenance();	   //车位信息维护

void parking_allocation_and_charging();								  //车位分配与收费
void automatically_assigned();										  //自动分配
void manual_maintenance_and_adjustment(struct car Car[20], FILE *fp); //人工维护调整
void chucun(struct car a[], int b);									  //存车
void tiaozheng(struct car Car[20], FILE *fp, int f);				  //车位调整
void charging(struct car Car[20], FILE *fp);						  //取车收费

void parking_information_query();					   //车位信息查询
void function_carnumber(struct car Car[20], FILE *fp); //车牌号查询
void function_floor(struct car Car[20], FILE *fp);
;												 //查询楼层
void function_pos(struct car Car[20], FILE *fp); //车位查询

void function5();
int main()
{
	system("color 0B"); //调整程序的颜色，可以删除
	mainmenu();
	system("pause");
	return 0;
}
void mainmenu() //主菜单
{
	int a;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            欢迎使用停车场管理系统!\n");
	printf("                           输入数字进行您想要的操作。\n");
	printf("\n\n");
	printf("                               1.车辆信息管理\n");
	printf("                               2.车位信息管理\n");
	printf("                               3.车位分配与收费\n");
	printf("                               4.车位信息查询\n");
	printf("                               5.退出\n");
	printf("                     *************************************\n");
	scanf("%d", &a);
	system("cls");
	switch (a)
	{
	case 1:
		vehicle_information_management();
		break;
	case 2:
		parking_information_management();
		break;
	case 3:
		parking_allocation_and_charging();
		break;
	case 4:
		parking_information_query();
		break;
	case 5:
		system("cls");
		break;
	default:
		printf("输入错误！请重新输入！");
		mainmenu();
		break;
	}
}
void vehicle_information_management() //车辆信息管理
{
	int a;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            欢迎使用停车场管理系统!\n");
	printf("                           输入数字进行您想要的操作。\n");
	printf("\n\n");
	printf("                               1.信息初始化\n");
	printf("                               2.返回到上一级\n");
	printf("                     *************************************\n");
	scanf("%d", &a);
	system("cls");
	switch (a)
	{
	case 1:
		information_initialization();
		break;
	case 2:
		mainmenu();
		break;
	default:
		printf("输入错误！请重新输入！");
		vehicle_information_management();
		break;
	}
}
void parking_information_management() //车位信息管理
{
	int a;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            欢迎使用停车场管理系统!\n");
	printf("                           输入数字进行您想要的操作。\n");
	printf("\n\n");
	printf("                               1.车位信息初始化\n");
	printf("                               2.车位信息状态\n");
	printf("                               3.返回到上一级\n");
	printf("                     *************************************\n");
	scanf("%d", &a);
	system("cls");
	switch (a)
	{
	case 1:
		parking_information_initialization();
		break;
	case 2:
		parking_information_maintenance();
		break;
	case 3:
		mainmenu();
		break;
	default:
		printf("输入错误！请重新输入！");
		parking_information_management();
		break;
	}
}
void parking_allocation_and_charging() //车位分配与收费
{
	struct car Car[20];
	FILE *fp;
	int a;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            欢迎使用停车场管理系统!\n");
	printf("                           输入数字进行您想要的操作。\n");
	printf("\n\n");
	printf("                               1.存车\n");
	printf("                               2.人工维护调整\n");
	printf("                               3.取车收费\n");
	printf("                               4.返回到上一级\n");
	printf("                     *************************************\n");
	scanf("%d", &a);
	system("cls");
	switch (a)
	{
	case 1:
		automatically_assigned();
		break;
	case 2:
		manual_maintenance_and_adjustment(Car, fp);
		break;
	case 3:
		charging(Car, fp);
		break;
	case 4:
		mainmenu();
		break;
	default:
		printf("输入错误！请重新输入！");
		parking_allocation_and_charging();
		break;
	}
}
void parking_information_query() //车位信息查询
{
	char a, ds[10];
	int i = 0, j = 0, k = 0, carNO, fee;
	char carn;
	int floor, pos;
	struct car Car[20];
	FILE *fp;
	if ((fp = fopen("car.dat", "rb+")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	time_t t1[200];
	for (i = 0; i < 20; i++) //读取文件数据
	{
		fread(&Car[i], sizeof(struct car), 1, fp);
		//printf("file write error\n");
	}
	fclose(fp);
	int b;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            欢迎使用停车场管理系统!\n");
	printf("                           输入数字进行您想要的操作。\n");
	printf("\n\n");
	printf("                               1.车牌号查询\n");
	printf("                               2.查询楼层\n");
	printf("                               3.车位查询\n");
	printf("                               4.返回到上一级\n");
	printf("                     *************************************\n");
	scanf("%d", &b);
	system("cls");
	switch (b)
	{
	case 1:
		function_carnumber(Car, fp);
		break;
	case 2:
		function_floor(Car, fp);
		break;
	case 3:
		function_pos(Car, fp);
		break;
	case 4:
		mainmenu();
		break;
	default:
		printf("输入错误！请重新输入！");
		parking_information_query();
		break;
	}
}

void information_initialization() //信息初始化
{
	FILE *fp;
	int i, j, k, n;
	printf("请输入停车场中的车辆的数量：\n");
	scanf("%d", &n);
	struct car Car[n];
	void input(struct car a[], int b);
	input(Car, n);
	fp = fopen("car.dat", "wb");
	for (i = 0; i < n; i++)
	{
		fwrite(&Car[i], sizeof(struct car), 1, fp);
	}
	fclose(fp);
	void scrprint(struct car a[], int b);
	scrprint(Car, n);
	printf("按回车键返回上一级。");
	getchar();
	getchar();
	system("cls");
	vehicle_information_management();
}
void information_maintenance() //信息维护
{
}
void parking_information_initialization() //车位信息初始化
{
	int a, b;
	printf("请输入停车场的层数：\n");
	scanf("%d", &a);
	printf("请输入每层的车位数量：\n");
	scanf("%d", &b);
	printf("停车场初始化完成!\n共%d层，每层有%d个车位。", a, b);
	printf("按回车键返回上一级。");
	getchar();
	getchar();
	system("cls");
	parking_information_management();
}
void parking_information_maintenance() //车位信息状态
{
	FILE *fp;
	int i;
	fp = fopen("car.dat", "r");
	struct car Car[20];
	for (i = 0; i < 20; i++) //读取文件数据
	{
		fread(&Car[i], sizeof(struct car), 1, fp);
	}

	for (i = 0; i < 20; i++)
	{
		if (Car[i].floor != 0 && Car[i].floor < 3 && Car[i].position != 0 && Car[i].position < 11)
		{
			printf("%d层%d号车位已被占用\n", Car[i].floor, Car[i].position);
		}
		else if (i == 21)
		{
			printf("停车场还是空的。\n");
			break;
		}
	}
	printf("按回车键返回上一级。");
	getchar();
	getchar();
	system("cls");
	parking_information_management();
}
void automatically_assigned() //存车
{
	FILE *fp;
	int i, j, k, n;
	printf("请输入要存车辆的数量：\n");
	scanf("%d", &n);
	struct car Car[n];
	void input(struct car a[], int b);
	chucun(Car, n);
	fp = fopen("car.dat", "wb");
	for (i = 0; i < n; i++)
	{
		fwrite(&Car[i], sizeof(struct car), 1, fp);
	}
	fclose(fp);
	void scrprint(struct car a[], int b);
	printf("存车成功！\n按回车键返回上一级。");
	getchar();
	getchar();
	system("cls");
	vehicle_information_management();
}

void input(struct car a[], int b)
{
	int i;
	printf("楼层 车位号 车牌    \n");
	printf("-我-是-萌-萌-哒-的-分-界-线-\n");
	for (i = 0; i < b; i++)
	{
		scanf("%d %d %s", &a[i].floor, &a[i].position, &a[i].carnumber);
		time(&a[i].timeIn);
	}
}
void chucun(struct car a[], int b)
{
	int i;
	printf("请输入要存车辆的楼层 位置 车牌号\n");

	for (i = 0; i < b; i++)
	{
		scanf("%d %d %s", &a[i].floor, &a[i].position, &a[i].carnumber);
		time(&a[i].timeIn);
	}
}

void scrprint(struct car a[], int b)
{
	int i;
	printf("\n楼层 车位号   车牌    停入时间");
	printf("\n-----还-----是-----我-----啦-----");
	for (i = 0; i < b; i++)
	{
		printf("\n%d    %d      %s   %s", a[i].floor, a[i].position, a[i].carnumber, ctime(&a[i].timeIn));
	}
}
void charging(struct car Car[20], FILE *fp) //取车收费，原数据清空
{
	int i = 0;
	printf("请输出即将离开的车的车牌号：\n");
	getchar();
	char s[20];
	gets(s);
	if ((fp = fopen("car.dat", "rb+")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	for (i = 0; i < 20; i++) //读取文件数据
	{
		fread(&Car[i], sizeof(struct car), 1, fp);
	}
	for (i = 0; i <= 20; i++)
	{
		if (strcmp(s, Car[i].carnumber) == 0)
			break;
	}
	time_t t2;
	if (i == 21)
		printf("抱歉，没有这辆车！");
	else
	{
		time(&t2);
		Car[i].time = t2 - Car[i].timeIn;
		int price = Car[i].time / 10;
		printf("车牌号为%s的车共收费%d元\n期待再次相遇\n", Car[i].carnumber, price);
		Car[i].carnumber[0] = 0;
		Car[i].floor = 0;
		Car[i].position = 0;
		Car[i].time = 0;
		Car[i].timeIn = 0;
		Car[i].timeOut = 0;
		fseek(fp, 0, 0);
		for (i = 0; i < 20; i++)
		{
			fwrite(&Car[i], sizeof(struct car), 1, fp);
		}
	}
	fclose(fp);
	printf("按回车键返回上一级。");
	getchar();
	getchar();
	system("cls");
	parking_allocation_and_charging();
}
void function_carnumber(struct car Car[20], FILE *fp) //车牌号查询
{
	int i = 0, e = 0;
	char carn[10];
	time_t t2;
	printf("请输入车牌号：");
	getchar();
	gets(carn);
	if ((fp = fopen("car.dat", "rb")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	for (i = 0; i <= 20; i++)
	{
		if (strcmp(Car[i].carnumber, carn) == 0)
			break;
		else
			e++;
	}
	if (e == 21)
	{
		printf("没有这辆车哦！");
	}
	else
	{
		time(&t2);
		Car[i].time = (t2 - Car[i].timeIn);
		printf("                      车牌号 层号 车位号 停车时间(秒)\n");
		printf("                      %s     %d      %d        %d\n", Car[i].carnumber, Car[i].floor, Car[i].position, Car[i].time);
	}
	fclose(fp);
	printf("按回车键返回上一级。");
	getchar();
	system("cls");
	parking_information_query();
}

void function_floor(struct car Car[20], FILE *fp) //查询楼层
{
	printf("请输入您要查的楼层：");
	int fl, p, i = 0;
	time_t t2;
	scanf("%d", &fl);
	getchar();
	if ((fp = fopen("car.dat", "rb")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	int e = 0;
	for (i = 0; i < 21; i++)
	{
		if (Car[i].floor == fl && Car[i].carnumber[0])
			break;
		else
			e++;
	}
	if (e == 20)
		printf("这楼层木有车哦！");
	else
	{
		printf("                      车牌号 层号 车位号 停车时间(秒)\n");
		for (i = 0; i <= 20; i++)
		{
			if (Car[i].floor == fl && Car[i].carnumber[0])
			{
				time(&t2);
				Car[i].time = (t2 - Car[i].timeIn);
				printf("                      %s     %d      %d        %d\n", Car[i].carnumber, Car[i].floor, Car[i].position, Car[i].time);
			}
		}
	}
	fclose(fp);
	printf("按回车键返回上一级。");
	getchar();
	system("cls");
	parking_information_query();
}

void function_pos(struct car Car[20], FILE *fp) //车位查询
{
	printf("请输入您要查询的楼层和对应车位：");
	int fl, pos, i = 0;
	time_t t2;
	scanf("%d%d", &fl, &pos);
	getchar();
	if ((fp = fopen("car.dat", "rb")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	for (i = 0; i <= 20; i++)
	{
		if (Car[i].floor == fl && Car[i].position == pos)
		{
			time(&t2);
			Car[i].time = (t2 - Car[i].timeIn);
			printf("                      车牌号 层号 车位号 停车时间(秒)\n");
			printf("                      %s     %d      %d        %d\n", Car[i].carnumber, Car[i].floor, Car[i].position, Car[i].time);
			break;
		}
		else
			continue;
	}
	if (i == 21)
		printf("这里木有车哦！");
	fclose(fp);
	printf("按回车键返回上一级。");
	getchar();
	system("cls");
	parking_information_query();
}
void tiaozheng(struct car Car[20], FILE *fp, int f) //人工维护调整
{

	if ((fp = fopen("car.dat", "rb+")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	int i = 0, j = 0, k = 1;
	for (i = 0; i < 20; i++) //读取文件数据
	{
		fread(&Car[i], sizeof(struct car), 1, fp);
	}
	struct now
	{
		int floor;
		int posi;
	} now[20];
	for (i = 0; i < 21; i++)
	{
		if (i < 11)
		{
			now[i].floor = 1;
			now[i].posi = 0;
		}
		else
		{
			now[i].floor = 2;
			now[i].posi = 0;
		}
	}
	for (i = 0; i < 21; i++)
	{
		for (k = 1; k < 21; k++)
		{
			if (Car[k].floor == now[i].floor && Car[k].position)
			{
				now[i].posi = 1;
				break;
			}
		}
	}
	for (i = 0; i < 21; i++)
	{
		if (now[i].posi == 0)
			break;
	}
	if (i == 21)
		printf("抱歉没有空车位了诶！");
	else
	{
		/*printf("当前空的车位有:\n");
		printf("        层号       车位号 \n");
		for(i=0;i<21;i++)
		{
			if(now[i].posi==0)
			{
				printf("%8d%8d\n",now[i].floor,now[i].posi);	
			}
		}*/
		int a, b;
		printf("请输入您想停车的位置：");
		scanf("%d%d", &a, &b);
		Car[f].floor = a;
		Car[f].position = b;
		fseek(fp, 0, 0);
		for (i = 0; i < 20; i++)
		{
			fwrite(&Car[i], sizeof(struct car), 1, fp);
		}
		/*int m=Car[f].position;
		int n=Car[f].floor;
		now[(n-1)*10+m].posi=0;
		Car[f].floor==a;Car[f].position=b;*/
		printf("调整成功！\n");
	}
	fclose(fp);
}
void manual_maintenance_and_adjustment(struct car Car[20], FILE *fp) //人工维护
{
	int i = 0, e = 0;
	char carn[10];
	time_t t2;
	printf("请输入车牌号：");
	getchar();
	gets(carn);
	if ((fp = fopen("car.dat", "rb")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	for (i = 0; i < 20; i++) //读取文件数据
	{
		fread(&Car[i], sizeof(struct car), 1, fp);
	}
	for (i = 0; i <= 20; i++)
	{
		if (strcmp(Car[i].carnumber, carn) == 0)
			break;
		else
			e++;
	}
	int f = i;
	if (e == 20)
	{
		printf("没有这辆车哦！");
	}
	else
	{
		printf("您当前的车位是%d层%d号位\n", Car[i].floor, Car[i].position);

		printf("请问您需要调整位置吗？\n请输入Y或N\n");
		char a;
		scanf("%c", &a);
		switch (a)
		{
		case 'Y':
			tiaozheng(Car, fp, f);
			break;
		case 'N':
			printf("好的呢！祝您停车愉快！");
			break;
		default:
			printf("输入错误！请重新输入！");
			parking_allocation_and_charging();
			break;
		}
	}
	fclose(fp);
	printf("按回车键返回上一级。");
	getchar();
	getchar();
	system("cls");
	parking_allocation_and_charging();
}
