#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,s1;//考虑到有空格输入，所以用字符串
    getline(cin,s);
    sort(s.begin(), s.end()); //头，尾 sort (a,a+10)同理
        s1=s;//字符串可以直接相等
    for (int i = 0, j = 0; i < s.size(); i++, j++)
    {
        if (s[i+1] == s1[j])//因为排序后，相同的字符会连在一起，
        //所以直接后一位比前一位就可以去重了
            continue;//跳过重复的
        else
            cout << s[i];
    }
}