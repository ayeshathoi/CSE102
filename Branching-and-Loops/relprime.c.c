#include<stdio.h>
#include<conio.h>

int main()
{
    int c,gcd,i,n,m,count=0,temp;
    printf("enter the number:");
    scanf("%d",&c);

    for(i=1; i<c; i++)
    {
        m=i;
        n=c;
        while(temp!=0)
        {
            temp=n%m;
            gcd=m;
            n=m;
            m=temp;
        }
        if(gcd==1)
        {
            count++;
        }
        temp=1;
    }
    printf("The number of relatively prime numbers of the given the number : ");
    printf("%d ",count);
    return 0;
}
