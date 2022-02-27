#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, i;
    cin >> n >> a;
    string s;
    for (i = 1, a--; i <= n; i++)
    {
        s = char('z' - a % 26) + s;
        a /= 26;
    }
    cout << s;
}