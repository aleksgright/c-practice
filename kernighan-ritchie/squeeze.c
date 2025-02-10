#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define ABC_SIZE 26

//removes only latin alphabet letters
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    char usage[ABC_SIZE] = {0};
    for (i = 0; s2[i] != '\0'; i++)
    {
        usage[s2[i] - 'a'] = 1;
    }

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        if (!usage[s1[i] - 'a'])
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main()
{
    char string1[] = "carburatour";
    char string2[] = "capibara";
    squeeze(string1, string2);
    assert(strcmp(string1, "utou") == 0);
    printf("%s\n", string1);
    return 0;
}