#include <stdio.h>

int main()
{
    int i, j, m;
    double x, term=1.00,sum=1.00;
    printf("Enter the value of x(in degrees)\n");
    scanf("%lf", &x);
    if(x>360)
    {
        m=x/360;
        x=x-m*360;

    }
    else if(x<-360)
    {
        m=x/360;
        x=x-m*360;
    }
    /*  Degrees to radians */
    x = x * (3.141592654 / 180.0);
    for (i = 1; i < 100; i = i + 1)
    {
        term=(term*x*x)/(2*i*(2*i-1));
        if(i%2==0)
        {
            sum+=term;
        }
        else sum-=term;
    }
    printf("Sum of the cosine series = %7.6lf\n", sum);
    return 0;
}
