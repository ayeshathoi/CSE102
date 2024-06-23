#include<stdio.h>
int main()
{
    int n;
    scanf("%d ",&n);
    int sum=0,x=1,t=1,i,l;
    for(i=1; i<100; i++)
    {
        printf("%d , x");
        sum+=x;
        printf("%d ",t);
        while(t!=0){
        x*=(x+1);
        printf("%d",x);
        }
    }
    return 0;
}
