#include <stdio.h>

#define N 40

int ReadScore(int score[]);
int FindMaxIndex(int x[], int n);

int main()
{
    int score[N], maxIndex, n;
    n = ReadScore(score);
    printf("Total values are %d\n", n);
    maxIndex = FindMaxIndex(score, n);
    printf("score[%d] is the highest:%d\n", maxIndex, score[maxIndex]);
    return 0;
}

int ReadScore(int score[])
{
    int i;
    printf("请输入成绩，以负值中值\n");
    for (i = 0; i < N; i++)
    {
        scanf("%d", &score[i]);
        if (score[i] < 0)
            break;
    }
    return i;
}

int FindMaxIndex(int x[], int n)
{
    int maxIndex, i;
    maxIndex = 0;
    for (i = 1; i < n; i++)
    {
        if (x[i] > x[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}