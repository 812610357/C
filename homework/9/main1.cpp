#include <stdio.h>
int main()
{
    int a[10], i, *p;
    p = a;
    for (i = 0; i < 10; i++)
        scanf("%d", p++);
    printf("\n");
    p -= 10; //
    for (i = 0; i < 10; i++, p++)
        printf("%d ", *p);
    printf("\n");
}
