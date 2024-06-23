#include <stdio.h>
int main()
{
    int a[2] = {2,3};
    int *p;
    p = a;

    printf("%x :: %d\n",p, *p);

    *p++;

    printf("%x :: %d\n",p, *p);

    return 0;
}
