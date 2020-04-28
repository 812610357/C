#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float r, s;
    printf("please input:R=");
    scanf("%f", &r);
    s = acos(-1.0) * r * r;
    printf("S=%f\n", s);
    system("pause");
    return 0;
}