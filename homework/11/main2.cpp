#include <stdio.h>
#define N 3
struct student
{
    int num;
    char name[20];
    int score;
};
int main()
{
    int i;
    struct student s[N]; /*定义结构体类型数组,长度100*/
    for (i = 0; i < N; i++)
    {
        printf("input number:");
        scanf("%d", &s[i].num);
        printf("input  name:");
        scanf("%s", &s[i].name);
        printf("input score:");
        scanf("%d", &s[i].score); //
    }
    printf("Number:  Name:    score:\n");
    for (i = 0; i < N; i++)
        printf("%-8d%-10s%d\n", s[i].num, s[i].name, s[i].score);
}
