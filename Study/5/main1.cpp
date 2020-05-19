#include <stdio.h>

int f(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;
    return (p - s);
}

int main()
{
    {
        printf("%d\n", f("ABCDEF"));
    }
    {
        struct date
        {
            int year;
            int month;
            int day;
        };
        struct s
        {
            struct date birthday;
            char name[20];
        } x[4] = {{2008, 10, 1, "guangzhou"}, {2009, 12, 25, "Tianjin"}};
        printf("%s,%d,%d,%d", x[0].name, x[1].birthday.year);
    }
    {
        struct s
        {
            int a;
            char b;
            float f;
        };
        printf("%d\n", sizeof(struct s));
    }
    {
        struct c
        {
            int x;
            int y;
        } s[2] = {1, 3, 2, 7};
        printf("%d\n", s[0].x * s[1].y);
    }
}