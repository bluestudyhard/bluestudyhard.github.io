#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;//其实就是字符串可以理解为c的字符串数组
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] % 2 == 1)
            cout << s[i];
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] % 2 == 0)
            cout << s[i];
    }
}