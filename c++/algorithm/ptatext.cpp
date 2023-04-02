#include <bits/stdc++.h>
using namespace std;
int main()
{
    string ss[1005];
    int a[1005];
    int n, m, x, y;
    string s;
    cin >> n;

    while (n--)
    {
        cin >> s >> x >> y;
        a[x] = y;
        ss[x] = s;
    }
    int cnt, res;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        cin >> res;
        cout << ss[res] << " " << a[res] << endl;
    }
}