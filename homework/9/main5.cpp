#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, i, j, *p[3] = {&a, &b, &c}, *temp = NULL;
    for (i = 0; i < 3; i++)
        scanf("%d", p[i]);
    for (i = 0; i < 3; i++)
        for (j = i + 1; j < 3; j++)
            if (*p[i] > *p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
    for (i = 0; i < 3; i++)
        printf("%d ", *p[i]);
    printf("\n");
    system("pause");
    return 0;
}