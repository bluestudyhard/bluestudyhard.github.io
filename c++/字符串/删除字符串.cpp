#include<string.h>
void delchar( char *str, char c )
{
    int i,l,j;
    l = strlen(str);
    for (i = 0,j = 0;i<l;i++) 
        if (str[i]!=c)//            例，找a，abbb，b!=a，然后
            str[j++] = str[i];
        str[j] = '\0';//输出时遇到空符直接终止，所以不能直接通过想到空符删除
}