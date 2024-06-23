#include<stdio.h>
int strlen(char *s)
{
    int len=0;

    while(*s!='\0')
    {
        s++;
        len++;
    }

    return len;
}

int main()
{
    char t[100];
    char *str;
    str = t;

    printf("Enter a string: ");
    scanf("%[^\n]s",str);
    printf("length: %d\n",strlen(str));
    return 0;
}
