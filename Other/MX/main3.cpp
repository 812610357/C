#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float r, s;
    printf("please input:S=");
    scanf("%f", &s);
    r = sqrt(s / acos(-1.0));
    printf("D=%f\n", 2 * r);
    system("pause");
    return 0;
}