#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,i,sum = 0,sum1 = 0,sum2 = 0;
    string s;
    cin >> a;
    cin>>s;
    for (i = 0; i < a; i++)
    {
            if (s[i] == 'o')
            sum++;
            else if (s[i] == 's')
            sum1+=sum;
            else if (s[i] =='u')
            sum2+=sum1;
    }
        cout<<sum2;
}