#include<stdio.h>
int digit(int n)
{
    int rem;
    int max=0;
    while(n!=0)
    {
        rem=n%10;
        if(rem>max)
            max=rem;
        n/=10;
    }
    printf("%d",max);
    return 0;


}
int main()
{
    int i,n;
    scanf("%d",&n);
    i=digit(n);
    return 0;

}
