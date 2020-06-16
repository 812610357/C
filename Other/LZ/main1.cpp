#include <stdio.h>

int main()
{
    char s[3][10] = {"asdfg", "sas"};
    puts(*(s + 1));
    return 0;
}