#include <stdio.h>
int sub(int n)
{
    int a;
    if (n == 1)
        return 1;
    a = n + sub(n - 1);
    return a;
}
int main()
{
    int b;
    b = sub(5);
    return 0;
}