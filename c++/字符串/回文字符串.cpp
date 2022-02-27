#include <stdio.h>
#include <string.h>
int main()
{
    char s[81];
    int i, l;
    gets(s);
    l = strlen(s)-1;//-1的原因是，level 因为考虑到中间那个字符，
    //是两边都不等的，所以l要-1 所以到i>=l时，都相等，就哦了
    printf("%s\n", s);
    for (i = 0; i < l; i++, l--)
        if (s[i] != s[l])
            break;
        if (i>=l)
            printf("Yes");
        else
            printf("No");
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n,i,l;
    getline(cin,s);
    l = s.length() - 1;
    for (i = 0;i<l;i++,l--)
        if (s[i]!=s[l])break;
         if(i>=l)
           cout<<s<<endl<<"Yes";
               else
                cout<<s<<endl<<"No";
}
#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    gets(s);
    int n,i,l;
    l = strlen(s)-1;
    for (i = 0;i<l;i++,l--)
        {
            if (s[i]!=s[l])
                if (i>=l)
                printf("YES");
            else 
            printf("No");
        }
}