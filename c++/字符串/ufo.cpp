#include <bits/stdc++.h> //memset(a,0,sizeof(a)); menset初始化
using namespace std;
int main()
{
    string s, s1;
    cin >> s >> s1;
    int i, sum = 1, sum1 = 1;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] -= '@';
            sum *= s[i];
        }
    }
    for (i = 0; i < s1.size(); i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s1[i] -= '@';
            sum1 *= s1[i];
        }
    }

    if (sum % 47 == sum1 % 47)
        cout << "GO";
    else
        cout << "STAY";
}
