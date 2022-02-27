#include <bits/stdc++.h> 这题能学到的 
1. 判断到负号要减去他，而，erase 3 double 化
using namespace std;
int main()
{
    string s;
    cin>>s;
    int l = s.size(),sum = 0;
    double j = 1.0,sum1;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == '2')
            sum++;
    }
    if (s[0] == '-')
    {
        l--;
        j = 1.5 * j;
        s.erase(0,1);
    }
    if ((s[l-1]-'0') % 2 == 0)
        j = 2.0*j;
        sum1 = 100.0*j*double(sum)/double (l);
        printf("%.2f\%\n",sum1);
}
