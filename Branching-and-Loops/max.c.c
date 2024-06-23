#include<stdio.h>
int main()
{
    char m;
    int a=0,count=1,i;
    printf("The number is : ");
    while(m!='\n')
    {
        scanf("%c",&m);
        if(m==a)
            count++;
        if(a<m)
        {
            a=m;
            count=1;
        }
    }
    printf("The frequency of the largest digit in the number : ");
    printf("%d",count);
    return 0;
}
