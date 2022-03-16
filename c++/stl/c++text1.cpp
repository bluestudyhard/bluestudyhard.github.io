#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool v[10000];
int n, m, i = 0, j, sum = 1, sum1, k;
int minn = 999999999;
int a[10000], b[10000];
void dfs(int u)
{
    if (u == n)
    {
        return;
    }
    else
    {
        sum *= a[u];
        sum1 += b[u];
        minn = min(abs(sum - sum1), minn);
        cout << "minn = " << minn << endl;
        cout << sum << " " << sum1 << endl;
        dfs(u + 1);
         cout << sum << " " << sum1 << endl;
        sum /= a[u];
        sum1 -= b[u];
    }
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    dfs(0);
    cout << minn;
}
