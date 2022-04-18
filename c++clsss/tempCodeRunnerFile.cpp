#include <iostream>
#include <string.h>
using namespace std;
char *mytrim(char *s)
{
    int t = strlen(s) - 1;
    while (s[t] == ' ')
        s[t--] = '\0';
    return s;
}
int main()
{
    char s[100];
    gets(s);
    *mytrim(s);
    puts(s);
}