#include <stdio.h>

int main()
{
    {
        typedef union {
            long a[2];
            int b[4];
            char c[8];
        } TY;
        TY our;
        printf("%d\n", sizeof(our));
    }
    {
        union EXAMPLE {
            struct
            {
                int x, y;
            } in;
            int a, b;
        } e;
        e.a = 1;
        e.b = 2;
        e.in.x = e.a * e.b;
        e.in.y = e.a + e.b;
        printf("%d,%d\n", e.in.x, e.in.y);
    }
    {
        union pw {
            int i;
            char ch[2];
        } a;
        a.ch[0] = 13;
        a.ch[1] = 0;
        printf("%d", a.i);
    }
}