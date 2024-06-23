#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr;
    int n, i, sum=0, sum1 = 0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Enter %d numbers : ",n );
        for (i = 0; i < n; ++i)
        {
            scanf("%d",ptr+i);
        }
        for (i = 0; i < n; ++i)
        {
            if(i%2!=0)
                sum+=*(ptr+i);
            if(i%2==0)
                sum1+=*(ptr+i);
        }
    }
    if(sum==sum1) printf("Equal");
    else if(sum1<sum)
        printf("Odd index sum is greater");
    else if(sum1>sum)
        printf("Even index sum is greater");
    return 0;
}
