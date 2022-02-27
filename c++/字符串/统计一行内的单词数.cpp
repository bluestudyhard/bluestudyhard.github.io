#include<bits/stdc++.h>
using namespace std;
int main()
{   //Let's go to room 209.
    //5
    //本题目要求编写程序统计一行字符中单词的个数.
    //所谓“单词”是指连续不含空格的字符串，各单词之间用空格分隔，空格数可以是多个
    string s;
    getline(cin,s);
    int sum;
    if(s[0]==' ')//避免了全是空格的情况
        sum = 0;
    else
        sum = 1;
    for(int i = 0;i<s.length()-1;i++)//避免了判断结尾有空格
    {  
        if(s[i]==' '&&s[i+1]!=' ')//保证是间隔内的单词
            sum++;
    }
    cout<<sum;
}