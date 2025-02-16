#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escape(char s[], char t[])
{
  int i, j;
  for (i = 0, j = 0; t[i] != '\0' || s[i] != '\0'; i++, j++)
  {
    switch (t[i])
    {
    case '\t':
      s[j++] = '\\';
      s[j] = 't';
      break;
    case '\n':
      s[j++] = '\\';
      s[j] = 'n';
      break;
    default:
      s[j] = t[i];
      break;
    }
  }
  s[++j] = '\0';
}

void revers_escape(char s[], char t[])
{
  int i, j;
  for (i = 0, j = 0; s[i] != '\0' || t[j] != '\0'; i++, j++)
  {
    if (s[i] == '\\')
    {
      switch (s[i + 1])
      {
      case 't':
        t[j] = '\t';
        i++;
        break;
      case 'n':
        t[j] = '\n';
        i++;
        break;
      default:
        t[j] = s[i];
        break;
      }
    }
    else
    {
      t[j] = s[i];
    }
  }
  t[++j] = '\0';
}

int main()
{
  char string1[] = "qqqqqqqqqqqqqqqqqqqqqqqqq";
  char string2[] = "capi\nb\tar\na";
  escape(string1, string2);
  printf("%s\n", string1);
  escape(string1, string2);
  printf("%s\n", string2);
  return 0;
}