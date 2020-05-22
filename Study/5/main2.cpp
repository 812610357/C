#include <stdio.h>

int func(char *s, char a, int n)
{
    int j;
    *s = a;
    j = n;
    while (*s < s[j])
    {
        j--;
    }
    return j;
}

void sub(char *a, char b)
{
    while (*(a++) != '\0')
        ;
    while (*(a - 1) < b)
        *(a--) = *(a - 1);
    *(a--) = b;
}

void delch(char *s)
{
    int i, j;
    char *a;
    a = s;
    for (i = 0, j = 0; a[i] != '\0'; i++)
        if (a[i] >= '0' && a[i] <= '9')
        {
            s[j] = a[i];
            j++;
        }
    s[j] = '\0';
}

void su(char *a)
{
    char *t;
    if (*a)
    {
        t = a;
        t++;
        su(t);
        putchar(*a);
    }
}

int main()
{
    {
        char s[10] = "12ABC34";
        su(s);
    }
    {
        char item[] = "12abc3";
        delch(item);
        puts(item);
    }
    {
        char *s = "12134";
        int k = 0, a = 0;
        while (s[k + 1] != '\0')
        {
            k++;
            if (k % 2 == 0)
            {
                a = a + (s[k] - '0' + 1);
                continue;
            }
            a = a + (s[k] - '0');
        }
        printf("k=%d a=%d\n", k, a);
    }
    {
        char s[] = "97531", c;
        c = getchar();
        sub(s, c);
        puts(s);
    }
    {
        char c[6];
        int i;
        for (i = 1; i < 5; i++)
            *(c + i) = 'A' + i + 1;
        printf("%d\n", func(c, 'E', 5));
    }
}