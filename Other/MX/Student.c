#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#define N 5           //学生人数
#define n 3           //科目数量
void input();         //输入数据
void welcome();       //欢迎界面，最开始的界面
void choose();        //功能选择，选abc的界面
void outfile();       // 从文件中读取数据的函数
void major_average(); //求各个科目的平均分
void stu_average();   //求每位学生的平均分
void sort_average();  //按照每位学生平均分进行排序然后输出
void judge_level();   //判断学生总平均分成绩的函数
void judge_next();    //判断每个函数之后需要进行的操作

//鼠标右键选择可以跳到定义，abc选项可大写可小写选择

struct student
{
    char name[20];
    float score[n];
    char major[n][20];
    float avarage;
};
char subject[10][20]; //最多10门科目
typedef struct student ss;
ss s[N];
void welcome()
{
    printf("\n\n\n\n\t\t\t\t**********欢迎使用学生信息查询系统**********\n");
    printf("请输入学生的信息");
    printf("（按下任意键继续）...");
    getchar();
    system("cls");
    input();
}
void input()
{
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        printf("请输入第%d个学生的姓名:", i + 1);
        gets(s[i].name);
        printf("请输入第%d个学生的科目及成绩：\n", i + 1);
        int j;
        s[i].avarage = 0;
        for (j = 0; j < n; j++)
        {
            printf("科目%d：", j + 1);
            gets(s[i].major[j]);
            printf("成绩为：");
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
    printf("按任意键继续...");
    getchar();
    fclose(fp);
    choose();
}
void choose()
{
    system("cls");
    printf("\t\t\t**********欢迎来到学生系统选择界面**********\n\n");
    printf("\t\t\t          A.读取学生文件\n");
    printf("\t\t\t          B.求出每门课程的平均分\n");
    printf("\t\t\t          C.求出每位同学的平均分\n");
    printf("\t\t\t          D.依据平均分进行排序\n");
    printf("\t\t\t          E.评判学生平均分等级\n");
    printf("\t\t\t          F.退出\n");
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
    printf("请输入你要进行的操作");
    printf("\n\n\t\t\t          1.返回菜单\n");
    printf("\t\t\t          2.退出\n");
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
    printf("各个学生的信息如下：\n");
    FILE *fp;
    fp = fopen("student.txt", "w+");
    int i = 0;
    for (i = 0; i < N; i++)
    {
        fread(&s[i], sizeof(ss), 1, fp);
        printf("%s,%s %.2f,%s %.2f,%s %.2f;\n", s[i].name, s[i].major[0], s[i].score[0], s[i].major[1], s[i].score[1], s[i].major[2], s[i].score[2]);
    }
    fclose(fp);
    printf("****学生信息从文件读取完毕****\n");
    judge_next();
}
void major_average()
{
    int i, j, k;
    float m[20]; //对应subject[k]成绩所添加的次数，以方便求总数然后相除求平均
    for (i = 0; i < 20; i++)
        m[i] = 1.0;
    int z = n;             //一个人不可能有两项相同科目的成绩 ,z表示科目数的总值
    float count[20] = {0}; //对应subject的平均成绩
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
        printf("%s的平均分为：%.2f\n", subject[i], count[i]);
    }
    printf("****科目平均分输出完毕****\n");
    printf("按任意键继续...");
    getchar();
    judge_next();
}
void stu_average()
{
    printf("各个学生的平均成绩如下：\n");
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%s,平均成绩为：%.2f\n", s[i].name, s[i].avarage);
    }
    printf("****学生平均成绩输出完毕****\n");
    printf("按任意键继续...");
    getchar();
    judge_next();
}
void sort_average()
{
    int i, j;
    printf("对各个学生按照平均分排序：\n");
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
        printf("%s的平均分为%.2f,No.%d\n", s[i].name, s[i].avarage, i + 1);
    }
    printf("****学生排序输出完成****\n");
    printf("按任意键继续...");
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
            printf("%s,平均分为%.2f,等级为A+\n", s[i].name, s[i].avarage);
        if (x >= 90 && x < 100)
            printf("%s,平均分为%.2f,等级为A\n", s[i].name, s[i].avarage);
        if (x >= 80 && x < 90)
            printf("%s,平均分为%.2f,等级为B\n", s[i].name, s[i].avarage);
        if (x >= 70 && x < 80)
            printf("%s,平均分为%.2f,等级为C\n", s[i].name, s[i].avarage);
        if (x >= 60 && x < 70)
            printf("%s,平均分为%.2f,等级为D\n", s[i].name, s[i].avarage);
        if (x < 60)
            printf("%s,平均分为%.2f,等级为F\n", s[i].name, s[i].avarage);
    }
    printf("****学生等级输入完成****\n");
    printf("按任意键继续...");
    getchar();
    judge_next();
}
int main()
{
    welcome();
    infile();
    return 0;
}
