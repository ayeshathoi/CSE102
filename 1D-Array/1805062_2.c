#include <stdio.h>
int main()
{
    int arr[100], freq[100];
    int size, i, j, count,max=0,m;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements in array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
        freq[i] = -1;
    }


    for(i=0; i<size; i++)
    {
        if(arr[i]>=0 && arr[i]<=100)
        {
            count = 1;
            for(j=i+1; j<size; j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                    freq[j] = 0;
                }
            }
            if(freq[i] != 0)
            {
                freq[i] = count;
            }
        }
    }
    for(i=0; i<size; i++)
    {
        if(max<freq[i])
        {
            max=freq[i];
            m=arr[i];
        }
    }
    printf("%d\n",m);
    return 0;
}
