#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s = 0;
    for (int i = 2; i <= 100; i += 2)
    {
        s = s + i;
    }
    printf("sum=%d", s);
    system("pause");
    return 0;
}