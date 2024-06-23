#include <stdio.h>

int strcmp(char *s1, char *s2)
{
    while(*s1==*s2)
    {
        if (*s1=='\0')
        {
            return 0;
        }
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int main()
{
    char t1[100], t2[100];
    char *str1, *str2;
    str1=t1;
    str2=t2;

    printf("First String: ");
    scanf("%s",str1);
    printf("Second String: ");
    scanf("%s",str2);

    printf("%d\n",strcmp(str1, str2));

    return 0;
}
