#include <stdio.h>
struct s
{
    int x;
    float a;
} a[3];
void fun(int *s)
{
    static int j = 0;
    do
    {
        s[j] += s[j + 1];
    } while (++j < 2);
}
main()
{
    printf("%d\n", sizeof(a));
    int k, b[10] = {1, 2, 3, 4, 5};
    for (k = 1; k < 3; k++)
        fun(b);
    for (k = 0; k < 5; k++)
        printf("%d", b[k]);
}
