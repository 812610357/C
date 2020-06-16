#include <stdio.h>

int main()
{
    char a[3][10];
    for (int i = 0; i < 3; i++)
        scanf("%s", a[i]);
    for (int i = 0; i < 3; i++)
        printf("%s", a[i]);
    return 0;
}