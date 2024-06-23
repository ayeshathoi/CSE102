#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int **A = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
        A[i] = (int *)malloc(n * sizeof(int));
    int **B = (int **)malloc(n * sizeof(int *));
    for (i=0; i<n; i++)
        B[i] = (int *)malloc(n * sizeof(int));

    int row, col, isSymmetric;

    printf("Enter elements in matrix of size %dx%d: \n",n,n);
    for(row=0; row<n; row++)
    {
        for(col=0; col<n; col++)
        {
            scanf("%d", &A[row][col]);
        }
    }

    for(row=0; row<n; row++)
    {
        for(col=0; col<n; col++)
        {
            B[row][col] = A[col][row];
        }
    }

    isSymmetric = 1;
    for(row=0; row<n && isSymmetric==1; row++)
    {
        for(col=0; col<n; col++)
        {
            if(A[row][col] != B[row][col])
            {
                isSymmetric = 0;
                break;
            }
        }
    }

    if(isSymmetric == 1)
    {
        printf("\nYES");
    }
    else
    {
        printf("\nNO");
    }
    free(A);
    free(B);
    return 0;
}
