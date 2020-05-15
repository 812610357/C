#include <stdio.h>
#include <stdlib.h>

main()
{
    {
        int x[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, *p;
        p = x + 3;
        printf("%d", *(p++));
        system("pause");
    }
    {
        char *s[4], **p;
        int i;
        s[0] = "China";
        s[1] = "Shanghai";
        s[2] = "Beijing";
        s[3] = "Wuhan";
        p = s;
        for (i = 0; i < 4; i++)
            printf("%s\n", p[i]);
        system("pause");
    }
    {
        char ch[2][5] = {"6937", "8254"}, *p[2];
        int i, j, s = 0;
        for (i = 0; i < 2; i++)
            p[i] = ch[i];
        for (i = 0; i < 2; i++)
            for (j = 0; p[i][j] > '\0'; j += 2)
                s = 10 * s + p[i][j] - '0';
        printf("% d\n", s);
        system("pause");
    }
}