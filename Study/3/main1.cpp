#include <stdio.h>

int main()
{
    float a[10], max, min;
    int i;
    printf("Please input 10 floats");
    for (i = 0; i < 10; i++)
    {
        scanf("%f", &a[i]);
    }
    max = min = a[0];
    for (i = 1; i < 10; i++)
    {
        if (max > a[i])
        {
            max = a[i];
        }
        if (min < a[i])
        {
            min = a[i];
        }
    }
    printf("Max number is:%.2f\nMin number is:%.2f\n", max, min);
    return 0;
}