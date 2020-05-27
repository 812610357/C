#include <stdio.h>
#define N 1
struct student
{
    char num[6];
    char name[8];
    int score[4];
} stu[N];
void input(struct student stu[]); //
void print(struct student stu[]);
int main()
{
    input(stu);
    print(stu);
}
void input(struct student stu[])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        printf("\nplease input %d of %d\n", i + 1, N);
        printf("num: ");
        scanf("%s", stu[i].num); //
        printf("name: ");
        scanf("%s", stu[i].name);
        for (j = 0; j < 3; j++)
        {
            printf("score %d.", j + 1);
            scanf("%d", &stu[i].score[j]); //
        }
        printf("\n");
    }
}
void print(struct student stu[])
{
    int i, j;
    printf("\nNo. Name    Score1 Score2 Score3\n");
    for (i = 0; i < N; i++)
    {
        printf("%-5s%-9s", stu[i].num, stu[i].name);
        for (j = 0; j < 3; j++)
            printf("%-8d", stu[i].score[j]); //
        printf("\n");
    }
}
