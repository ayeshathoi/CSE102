#include <stdio.h>
#define SIZE 1
int arr[SIZE];
int *numbers;
void check(float x, float y,float z,int  *numbers);
int main()
{
    float x,y,z;
    numbers=&arr;
    for(; ;)
    {
        printf("Enter three numbers : ");
        scanf("%f %f %f",&x,&y,&z);
        check(x,y,z,numbers);
        if(arr[0]==1)
            printf("It is a Triangle");
        else printf("It is a Not Triangle");
        if(arr[1]==1)
            printf("\nIt is a Right angled triangle\n");
        else printf("\nIt is a Not Right angled triangle\n");
        return 0;
    }
}
void check(float x,float y, float z, int *numbers)
{
    if(x+y>z && y+z>x && x+z>y )
        *(numbers)=1;
    else *(numbers)==0;
    int sum,sum1,sum2,sum3,sum4,sum5;
    float l,m,n;
    l=x*1000;
    m=y*1000;
    n=z*1000;
    sum=(m*m+l*l);
    sum1=n*n;
    sum2=(n*n+m*m);
    sum3=l*l;
    sum4=(l*l+n*n);
    sum5=m*m;
    if(sum==sum1)
        *(numbers+1)=1;
    else if(sum2==sum3)
        *(numbers+1)=1;
    else if(sum4==sum5)
        *(numbers+1)=1;
    else *(numbers+1)==0;
}
