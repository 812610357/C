#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#define N 5           //ѧ������
#define n 3           //��Ŀ����
void input();         //��������
void welcome();       //��ӭ���棬�ʼ�Ľ���
void choose();        //����ѡ��ѡabc�Ľ���
void outfile();       // ���ļ��ж�ȡ���ݵĺ���
void major_average(); //�������Ŀ��ƽ����
void stu_average();   //��ÿλѧ����ƽ����
void sort_average();  //����ÿλѧ��ƽ���ֽ�������Ȼ�����
void judge_level();   //�ж�ѧ����ƽ���ֳɼ��ĺ���
void judge_next();    //�ж�ÿ������֮����Ҫ���еĲ���

//����Ҽ�ѡ������������壬abcѡ��ɴ�д��Сдѡ��

struct student
{
    char name[20];
    float score[n];
    char major[n][20];
    float avarage;
};
char subject[10][20]; //���10�ſ�Ŀ
typedef struct student ss;
ss s[N];
void welcome()
{
    printf("\n\n\n\n\t\t\t\t**********��ӭʹ��ѧ����Ϣ��ѯϵͳ**********\n");
    printf("������ѧ������Ϣ");
    printf("�����������������...");
    getchar();
    system("cls");
    input();
}
void input()
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("�������%d��ѧ��������:", i + 1);
        gets(s[i].name);
        printf("�������%d��ѧ���Ŀ�Ŀ���ɼ���\n", i + 1);
        int j;
        s[i].avarage = 0;
        for (j = 0; j < n; j++)
        {
            printf("��Ŀ%d��", j + 1);
            gets(s[i].major[j]);
            printf("�ɼ�Ϊ��");
            float a;
            scanf("%f", &a);
            s[i].score[j] = a;
            s[i].avarage += s[i].score[j];
            getchar();
        }
        s[i].avarage /= n;
    }
}
void infile()
{
    FILE *fp;
    fp = fopen("student.txt", "w+");
    int i;
    for (i = 0; i < N; i++)
    {
        fwrite(&s[i], sizeof(ss), 1, fp);
        printf("%s,%s %.2f,%s %.2f,%s %.2f;\n", s[i].name, s[i].major[0], s[i].score[0], s[i].major[1], s[i].score[1], s[i].major[2], s[i].score[2]);
    }
    printf("�����������...");
    getchar();
    fclose(fp);
    choose();
}
void choose()
{
    system("cls");
    printf("\t\t\t**********��ӭ����ѧ��ϵͳѡ�����**********\n\n");
    printf("\t\t\t          A.��ȡѧ���ļ�\n");
    printf("\t\t\t          B.���ÿ�ſγ̵�ƽ����\n");
    printf("\t\t\t          C.���ÿλͬѧ��ƽ����\n");
    printf("\t\t\t          D.����ƽ���ֽ�������\n");
    printf("\t\t\t          E.����ѧ��ƽ���ֵȼ�\n");
    printf("\t\t\t          F.�˳�\n");
    char ch = getchar();
    switch (ch)
    {
    case 'A':
    case 'a':
        outfile();
        break;
    case 'B':
    case 'b':
        major_average();
        break;
    case 'C':
    case 'c':
        stu_average();
        break;
    case 'D':
    case 'd':
        sort_average();
        break;
    case 'E':
    case 'e':
        judge_level();
        break;
    case 'F':
    case 'f':
        exit(0);
    default:
        choose();
    }
}
void judge_next()
{
    printf("��������Ҫ���еĲ���");
    printf("\n\n\t\t\t          1.���ز˵�\n");
    printf("\t\t\t          2.�˳�\n");
    int a;
    scanf("%d", &a);
    switch (a)
    {
    case 1:
        choose();
        break;
    case 2:
        exit(0);
        break;
    default:
        choose();
        break;
    }
}
void outfile()
{
    printf("����ѧ������Ϣ���£�\n");
    FILE *fp;
    fp = fopen("student.txt", "w+");
    int i = 0;
    for (i = 0; i < N; i++)
    {
        fread(&s[i], sizeof(ss), 1, fp);
        printf("%s,%s %.2f,%s %.2f,%s %.2f;\n", s[i].name, s[i].major[0], s[i].score[0], s[i].major[1], s[i].score[1], s[i].major[2], s[i].score[2]);
    }
    fclose(fp);
    printf("****ѧ����Ϣ���ļ���ȡ���****\n");
    judge_next();
}
void major_average()
{
    int i, j, k;
    float m[20]; //��Ӧsubject[k]�ɼ�����ӵĴ������Է���������Ȼ�������ƽ��
    for (i = 0; i < 20; i++)
        m[i] = 1.0;
    int z = n;             //һ���˲�������������ͬ��Ŀ�ĳɼ� ,z��ʾ��Ŀ������ֵ
    float count[20] = {0}; //��Ӧsubject��ƽ���ɼ�
    for (j = 0; j < N; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (j == 0)
            {
                strcpy(subject[i], s[j].major[i]);
                count[i] = s[j].score[i];
            }
            if (j > 0)
            {
                for (k = 0; k < z; k++)
                {
                    if (strcmp(subject[k], s[j].major[i]) == 0)
                    {
                        count[k] += s[j].score[i];
                        m[k]++;
                        break;
                    }
                }
                if (k == z)
                {
                    strcpy(subject[k], s[j].major[i]);
                    z++;
                    count[k] = s[j].score[i];
                }
            }
        }
    }
    for (i = 0; i < z; i++)
    {
        count[i] /= m[i];
        printf("%s��ƽ����Ϊ��%.2f\n", subject[i], count[i]);
    }
    printf("****��Ŀƽ����������****\n");
    printf("�����������...");
    getchar();
    judge_next();
}
void stu_average()
{
    printf("����ѧ����ƽ���ɼ����£�\n");
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%s,ƽ���ɼ�Ϊ��%.2f\n", s[i].name, s[i].avarage);
    }
    printf("****ѧ��ƽ���ɼ�������****\n");
    printf("�����������...");
    getchar();
    judge_next();
}
void sort_average()
{
    int i, j;
    printf("�Ը���ѧ������ƽ��������\n");
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1 - i; j++)
        {
            if (s[j].avarage < s[j + 1].avarage)
            {
                ss t;
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        printf("%s��ƽ����Ϊ%.2f,No.%d\n", s[i].name, s[i].avarage, i + 1);
    }
    printf("****ѧ������������****\n");
    printf("�����������...");
    getchar();
    judge_next();
}
void judge_level()
{
    int i;
    for (i = 0; i < N; i++)
    {
        float x = s[i].avarage;
        if (x >= 100)
            printf("%s,ƽ����Ϊ%.2f,�ȼ�ΪA+\n", s[i].name, s[i].avarage);
        if (x >= 90 && x < 100)
            printf("%s,ƽ����Ϊ%.2f,�ȼ�ΪA\n", s[i].name, s[i].avarage);
        if (x >= 80 && x < 90)
            printf("%s,ƽ����Ϊ%.2f,�ȼ�ΪB\n", s[i].name, s[i].avarage);
        if (x >= 70 && x < 80)
            printf("%s,ƽ����Ϊ%.2f,�ȼ�ΪC\n", s[i].name, s[i].avarage);
        if (x >= 60 && x < 70)
            printf("%s,ƽ����Ϊ%.2f,�ȼ�ΪD\n", s[i].name, s[i].avarage);
        if (x < 60)
            printf("%s,ƽ����Ϊ%.2f,�ȼ�ΪF\n", s[i].name, s[i].avarage);
    }
    printf("****ѧ���ȼ��������****\n");
    printf("�����������...");
    getchar();
    judge_next();
}
int main()
{
    welcome();
    infile();
    return 0;
}
