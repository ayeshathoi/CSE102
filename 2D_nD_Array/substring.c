#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
int apppear(char * str, char * toSearch);
int main()
{
    char str[MAX_SIZE], desired[MAX_SIZE];
    int count;
    printf("Enter any string: ");
    gets(str);
    printf("Enter word to search occurrences: ");
    gets(desired);
    count = appear(str, desired);
    printf("Total occurrences of '%s': %d", desired, count);
    return 0;
}
int appear(char * str, char * desired)
{
    int i, j, found, count=0;
    int len, dsrlen;

    len = strlen(str);
    dsrlen = strlen(desired);

    for(i=0; i <= len-dsrlen; i++)
    {
        found = 1;
        for(j=0; j<dsrlen; j++)
        {
            if(str[i + j] != desired[j])
            {
                found = 0;
                break;
            }
        }

        if(found == 1)
        {
            count++;
        }
    }

    return count;
}
