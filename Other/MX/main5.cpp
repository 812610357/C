#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float m, h, bmi;
    printf("please input your weight and height (spe by \",\" ):");
    scanf("m=%f,h=%f", &m, &h);
    bmi = m / pow(h, 2);
    printf("BMI=%f  ", bmi);
    if (bmi < 18.5)
        printf("Underweigh\n");
    else if (bmi < 25)
        printf("Normal\n");
    else if (bmi < 30)
        printf("Overweigh\n");
    else
        printf("Obese\n");
    system("pause");
    return 0;
}