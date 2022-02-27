该题目思路与找最大最小不一样，这个是根据字符串长短来判断的，这时候需要用到
string数组，
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, maxx = 0, p, i;
    string s[1000];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> s[i];
        if (s[i].length() > maxx)
        {
            maxx = s[i].length();
            p = i; //标记位置
        }
        else
            continue;
    }
    cout << "The longest is: " << s[p];
}
