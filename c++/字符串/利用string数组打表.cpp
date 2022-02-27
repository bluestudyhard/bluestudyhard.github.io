#include <bits/stdc++.h>//数字表
using namespace std;
string a[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
    string s;
    cin>>s;
    if (s[0]=='-')
        cout<<"fu";
    for (int i = 0;i<s.size();i++)
    {
        if (i)//不在末尾留空格的输出方法
            cout<<" ";
        cout<<a[s[i]-'0'];//因为，si-0就等于这个数，而这个数正好对应a[]的下标
    }
}
