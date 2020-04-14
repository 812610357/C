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
	time_t timeIn; // ����ͣ����ʱ��
	time_t timeOut;
};

void mainmenu(); //���˵�
//һ���˵�
void vehicle_information_management(); //������Ϣ����
void information_initialization();	   //��Ϣ��ʼ��
void information_maintenance();		   //��Ϣά��

void parking_information_management();	   //��λ��Ϣ����
void parking_information_initialization(); //��λ��Ϣ��ʼ��
void parking_information_maintenance();	   //��λ��Ϣά��

void parking_allocation_and_charging();								  //��λ�������շ�
void automatically_assigned();										  //�Զ�����
void manual_maintenance_and_adjustment(struct car Car[20], FILE *fp); //�˹�ά������
void chucun(struct car a[], int b);									  //�泵
void tiaozheng(struct car Car[20], FILE *fp, int f);				  //��λ����
void charging(struct car Car[20], FILE *fp);						  //ȡ���շ�

void parking_information_query();					   //��λ��Ϣ��ѯ
void function_carnumber(struct car Car[20], FILE *fp); //���ƺŲ�ѯ
void function_floor(struct car Car[20], FILE *fp);
;												 //��ѯ¥��
void function_pos(struct car Car[20], FILE *fp); //��λ��ѯ

void function5();
int main()
{
	system("color 0B"); //�����������ɫ������ɾ��
	mainmenu();
	system("pause");
	return 0;
}
void mainmenu() //���˵�
{
	int a;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            ��ӭʹ��ͣ��������ϵͳ!\n");
	printf("                           �������ֽ�������Ҫ�Ĳ�����\n");
	printf("\n\n");
	printf("                               1.������Ϣ����\n");
	printf("                               2.��λ��Ϣ����\n");
	printf("                               3.��λ�������շ�\n");
	printf("                               4.��λ��Ϣ��ѯ\n");
	printf("                               5.�˳�\n");
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
		printf("����������������룡");
		mainmenu();
		break;
	}
}
void vehicle_information_management() //������Ϣ����
{
	int a;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            ��ӭʹ��ͣ��������ϵͳ!\n");
	printf("                           �������ֽ�������Ҫ�Ĳ�����\n");
	printf("\n\n");
	printf("                               1.��Ϣ��ʼ��\n");
	printf("                               2.���ص���һ��\n");
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
		printf("����������������룡");
		vehicle_information_management();
		break;
	}
}
void parking_information_management() //��λ��Ϣ����
{
	int a;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            ��ӭʹ��ͣ��������ϵͳ!\n");
	printf("                           �������ֽ�������Ҫ�Ĳ�����\n");
	printf("\n\n");
	printf("                               1.��λ��Ϣ��ʼ��\n");
	printf("                               2.��λ��Ϣ״̬\n");
	printf("                               3.���ص���һ��\n");
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
		printf("����������������룡");
		parking_information_management();
		break;
	}
}
void parking_allocation_and_charging() //��λ�������շ�
{
	struct car Car[20];
	FILE *fp;
	int a;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            ��ӭʹ��ͣ��������ϵͳ!\n");
	printf("                           �������ֽ�������Ҫ�Ĳ�����\n");
	printf("\n\n");
	printf("                               1.�泵\n");
	printf("                               2.�˹�ά������\n");
	printf("                               3.ȡ���շ�\n");
	printf("                               4.���ص���һ��\n");
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
		printf("����������������룡");
		parking_allocation_and_charging();
		break;
	}
}
void parking_information_query() //��λ��Ϣ��ѯ
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
	for (i = 0; i < 20; i++) //��ȡ�ļ�����
	{
		fread(&Car[i], sizeof(struct car), 1, fp);
		//printf("file write error\n");
	}
	fclose(fp);
	int b;
	printf("\n\n\n\n");
	printf("                     *************************************\n");
	printf("                            ��ӭʹ��ͣ��������ϵͳ!\n");
	printf("                           �������ֽ�������Ҫ�Ĳ�����\n");
	printf("\n\n");
	printf("                               1.���ƺŲ�ѯ\n");
	printf("                               2.��ѯ¥��\n");
	printf("                               3.��λ��ѯ\n");
	printf("                               4.���ص���һ��\n");
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
		printf("����������������룡");
		parking_information_query();
		break;
	}
}

void information_initialization() //��Ϣ��ʼ��
{
	FILE *fp;
	int i, j, k, n;
	printf("������ͣ�����еĳ�����������\n");
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
	printf("���س���������һ����");
	getchar();
	getchar();
	system("cls");
	vehicle_information_management();
}
void information_maintenance() //��Ϣά��
{
}
void parking_information_initialization() //��λ��Ϣ��ʼ��
{
	int a, b;
	printf("������ͣ�����Ĳ�����\n");
	scanf("%d", &a);
	printf("������ÿ��ĳ�λ������\n");
	scanf("%d", &b);
	printf("ͣ������ʼ�����!\n��%d�㣬ÿ����%d����λ��", a, b);
	printf("���س���������һ����");
	getchar();
	getchar();
	system("cls");
	parking_information_management();
}
void parking_information_maintenance() //��λ��Ϣ״̬
{
	FILE *fp;
	int i;
	fp = fopen("car.dat", "r");
	struct car Car[20];
	for (i = 0; i < 20; i++) //��ȡ�ļ�����
	{
		fread(&Car[i], sizeof(struct car), 1, fp);
	}

	for (i = 0; i < 20; i++)
	{
		if (Car[i].floor != 0 && Car[i].floor < 3 && Car[i].position != 0 && Car[i].position < 11)
		{
			printf("%d��%d�ų�λ�ѱ�ռ��\n", Car[i].floor, Car[i].position);
		}
		else if (i == 21)
		{
			printf("ͣ�������ǿյġ�\n");
			break;
		}
	}
	printf("���س���������һ����");
	getchar();
	getchar();
	system("cls");
	parking_information_management();
}
void automatically_assigned() //�泵
{
	FILE *fp;
	int i, j, k, n;
	printf("������Ҫ�泵����������\n");
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
	printf("�泵�ɹ���\n���س���������һ����");
	getchar();
	getchar();
	system("cls");
	vehicle_information_management();
}

void input(struct car a[], int b)
{
	int i;
	printf("¥�� ��λ�� ����    \n");
	printf("-��-��-��-��-��-��-��-��-��-\n");
	for (i = 0; i < b; i++)
	{
		scanf("%d %d %s", &a[i].floor, &a[i].position, &a[i].carnumber);
		time(&a[i].timeIn);
	}
}
void chucun(struct car a[], int b)
{
	int i;
	printf("������Ҫ�泵����¥�� λ�� ���ƺ�\n");

	for (i = 0; i < b; i++)
	{
		scanf("%d %d %s", &a[i].floor, &a[i].position, &a[i].carnumber);
		time(&a[i].timeIn);
	}
}

void scrprint(struct car a[], int b)
{
	int i;
	printf("\n¥�� ��λ��   ����    ͣ��ʱ��");
	printf("\n-----��-----��-----��-----��-----");
	for (i = 0; i < b; i++)
	{
		printf("\n%d    %d      %s   %s", a[i].floor, a[i].position, a[i].carnumber, ctime(&a[i].timeIn));
	}
}
void charging(struct car Car[20], FILE *fp) //ȡ���շѣ�ԭ�������
{
	int i = 0;
	printf("����������뿪�ĳ��ĳ��ƺţ�\n");
	getchar();
	char s[20];
	gets(s);
	if ((fp = fopen("car.dat", "rb+")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	for (i = 0; i < 20; i++) //��ȡ�ļ�����
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
		printf("��Ǹ��û����������");
	else
	{
		time(&t2);
		Car[i].time = t2 - Car[i].timeIn;
		int price = Car[i].time / 10;
		printf("���ƺ�Ϊ%s�ĳ����շ�%dԪ\n�ڴ��ٴ�����\n", Car[i].carnumber, price);
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
	printf("���س���������һ����");
	getchar();
	getchar();
	system("cls");
	parking_allocation_and_charging();
}
void function_carnumber(struct car Car[20], FILE *fp) //���ƺŲ�ѯ
{
	int i = 0, e = 0;
	char carn[10];
	time_t t2;
	printf("�����복�ƺţ�");
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
		printf("û��������Ŷ��");
	}
	else
	{
		time(&t2);
		Car[i].time = (t2 - Car[i].timeIn);
		printf("                      ���ƺ� ��� ��λ�� ͣ��ʱ��(��)\n");
		printf("                      %s     %d      %d        %d\n", Car[i].carnumber, Car[i].floor, Car[i].position, Car[i].time);
	}
	fclose(fp);
	printf("���س���������һ����");
	getchar();
	system("cls");
	parking_information_query();
}

void function_floor(struct car Car[20], FILE *fp) //��ѯ¥��
{
	printf("��������Ҫ���¥�㣺");
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
		printf("��¥��ľ�г�Ŷ��");
	else
	{
		printf("                      ���ƺ� ��� ��λ�� ͣ��ʱ��(��)\n");
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
	printf("���س���������һ����");
	getchar();
	system("cls");
	parking_information_query();
}

void function_pos(struct car Car[20], FILE *fp) //��λ��ѯ
{
	printf("��������Ҫ��ѯ��¥��Ͷ�Ӧ��λ��");
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
			printf("                      ���ƺ� ��� ��λ�� ͣ��ʱ��(��)\n");
			printf("                      %s     %d      %d        %d\n", Car[i].carnumber, Car[i].floor, Car[i].position, Car[i].time);
			break;
		}
		else
			continue;
	}
	if (i == 21)
		printf("����ľ�г�Ŷ��");
	fclose(fp);
	printf("���س���������һ����");
	getchar();
	system("cls");
	parking_information_query();
}
void tiaozheng(struct car Car[20], FILE *fp, int f) //�˹�ά������
{

	if ((fp = fopen("car.dat", "rb+")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	int i = 0, j = 0, k = 1;
	for (i = 0; i < 20; i++) //��ȡ�ļ�����
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
		printf("��Ǹû�пճ�λ������");
	else
	{
		/*printf("��ǰ�յĳ�λ��:\n");
		printf("        ���       ��λ�� \n");
		for(i=0;i<21;i++)
		{
			if(now[i].posi==0)
			{
				printf("%8d%8d\n",now[i].floor,now[i].posi);	
			}
		}*/
		int a, b;
		printf("����������ͣ����λ�ã�");
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
		printf("�����ɹ���\n");
	}
	fclose(fp);
}
void manual_maintenance_and_adjustment(struct car Car[20], FILE *fp) //�˹�ά��
{
	int i = 0, e = 0;
	char carn[10];
	time_t t2;
	printf("�����복�ƺţ�");
	getchar();
	gets(carn);
	if ((fp = fopen("car.dat", "rb")) == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	for (i = 0; i < 20; i++) //��ȡ�ļ�����
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
		printf("û��������Ŷ��");
	}
	else
	{
		printf("����ǰ�ĳ�λ��%d��%d��λ\n", Car[i].floor, Car[i].position);

		printf("��������Ҫ����λ����\n������Y��N\n");
		char a;
		scanf("%c", &a);
		switch (a)
		{
		case 'Y':
			tiaozheng(Car, fp, f);
			break;
		case 'N':
			printf("�õ��أ�ף��ͣ����죡");
			break;
		default:
			printf("����������������룡");
			parking_allocation_and_charging();
			break;
		}
	}
	fclose(fp);
	printf("���س���������һ����");
	getchar();
	getchar();
	system("cls");
	parking_allocation_and_charging();
}
