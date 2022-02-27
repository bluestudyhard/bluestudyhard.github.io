#include <bits/stdc++.h> //memset(a,0,sizeof(a)); menset初始化
using namespace std;
int main()
{
    string s; //直接用string初始化时是双引号加单词
    cin>>s;
    int boy = 0, girl = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'b' || s[i+1] == 'o' || s[i+2] == 'y')//不能用else if，因为if与else if 是嵌套，而，这个题目，这两个是并列关系
            boy++;
        if (s[i] == 'g' || s[i+1] == 'i' || s[i+2] == 'r' || s[i+3] == 'l')
            girl++;
    }
    cout<<boy<<endl;
    cout<<girl;
}