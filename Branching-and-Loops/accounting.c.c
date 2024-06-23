#include<stdio.h>
int main()
{
    int unit;
    float bill;
    printf("Please enter the value of the unit : ");
    scanf("%d",&unit);
    if(unit<=100)
        bill=1.0*.5*unit;
    else if(unit<=200)
        bill=.5*100+1.0*.8*(unit-100);
    else if(unit>200)
        bill=.5*100+.8*100+1.0*1.2*(unit-200);
    printf("The value of bill is : ");
    printf("%.2f",bill);
    return 0;
}
