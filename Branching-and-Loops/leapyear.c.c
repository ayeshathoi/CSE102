#include<stdio.h>
int main()
{
    int year;
    printf("Enter a year : ");
    scanf("%d",&year);
    year%100==0?(year%400==0? printf("Leap year"):printf("Not a leap year")):(year%4==0?printf("Leap year"):printf("Not a leap year"));
    return 0;
}
