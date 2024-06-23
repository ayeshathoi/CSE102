#include <stdio.h>
#include <stdlib.h>
int main()
{

    int *ptr,*cnt;
    int n, i, j, max=0, num, sum = 0,count=1;
    printf("Enter any number : ");
    scanf("%d",&n);
    ptr = (int*)malloc(n * sizeof(int));
    cnt = (int*)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Enter %d numbers : ", n);
        for (i = 0; i < n; ++i)
            scanf("%d",ptr+i);
        for (i = 0; i < n; ++i)
        {
            count=1;
            if(*(ptr+i)>=0 && *(ptr+i)<=10000)
            {
                for(j=i+1; j<n; j++)
                {
                    if(*(ptr+i)==*(ptr+j))
                    {
                        count++;
                        *(cnt+j)=0;
                    }
                }
                *(cnt+i)=count;
                if(count>max)
                    max=count;
            }

        }
        printf("The mode of given numbers : ");
        for(i=0; i<n; i++)
        {

            if(*(cnt+i)==max)
                printf("%d ",*(ptr+i));
        }
    }

    return 0;
}
