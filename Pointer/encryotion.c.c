#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    char a;
    scanf("%c",&a);
    void *s;
    s=(char*)malloc(n*sizeof(char));
    scanf("%[^\n]s",s);
    long long int *en=(long long int*)s;
    for(i=0; i<n/8; i++)
    {
        printf("%lld ",*(en+i));
    }
    free(s);
    return 0;
}
