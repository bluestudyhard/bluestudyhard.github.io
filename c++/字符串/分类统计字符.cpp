#include <stdio.h>
#include<string.h>
#define MAXS 15
void StringCount( char s[] )
{   int letter = 0,blank = 0,digit = 0,other = 0;
    gets(s);
    int l = strlen(s);
    for (int i = 0;i<l;i++)
    {
        if (s[i]>='0'&&s[i]<='9')
            digit++;
       else if ((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z'))//不这样会超边界
              letter++;
      else  if (s[i]==' '||s[i]=='\n')
            blank++;
        else other++;
    }
        printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
}