#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    int **arr;
    scanf("%d", &n);
    arr = (int **) malloc (n * sizeof(int *));
    for (i = 0; i < n; i++) {
        arr[i] = (int *) malloc (n * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            arr[i][j] = 10;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

