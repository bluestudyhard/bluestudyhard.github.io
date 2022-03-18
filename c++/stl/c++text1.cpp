#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool v[10000];
int n, m, i = 0, j, sum = 1, sum1, k, ans;
int minn = 999999999;
int a[10000], b[10000];
void dfs(int u, int sum, int starx)
{
    if (u == b[i])
    {
        if (sum == a[i])
            ans++;
        return;
    }
    cout<<"sum:  "<<sum<<"  "<<u<<endl;
    for (j = starx; j < a[i]; j++)
    {   cout<<"sum:  "<<sum<<"  "<<u<<endl;
        dfs(u + 1, sum + j, starx + 1);
        cout<<"sum:  "<<sum<<"  "<<u<<endl;
    }
}
int main()
{
    cin >> k;
    for (i = 0; i < k; i++)
    {
        cin >> a[i] >> b[i];
        dfs(0, 0, 0);
        cout << ans << endl;
    }
}
