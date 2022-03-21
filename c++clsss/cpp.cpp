/*#include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000], j, n, k, sum, m;
bool v[1000];
void dfs(int u)
{ /*终止条件*/
/*    int i;
    if (u > m)
    {
        for (i = 1; i <= m; i++)
            cout<<setw(3)<<a[i];//c++中打间隔的方式
        cout << endl;
        return;
    }
    for (i = a[u - 1] + 1; i <= n; i++)
    {
        a[u] = i; // 1 25
        dfs(u + 1);
    }
}
int main()
{
    cin >> n >> m;
    dfs(1);
}*/
/*#include <bits/stdc++.h>
using namespace std;
int a[5000], s[5000];
int n, m, k, x, y, b, c, d, maxx = 0;
int i, j;
pair<int, int> v[50000];
int main()
{
    cin >> n >> m >> k;
    for (i = 1; i <= k; i++)
    {
        cin >> b >> d >> c;
        v[i].first = b * d;
        v[i].second = c;
    }
    sort(v, v + k);
    for (i = 1; i <= k - 1; i++)
    {
        v[k].first -= v[i].first;
    }
    cout << v[k].first << " " << v[k].second;
}*/
/*#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int Max = 1e7;
ll vector(pair<ll,ll>) kk;
int n, m, k, x, y, b, c, d;
int i, j;
ll a[Max];
bool cmp(pair<ll,ll>a,pair<ll,ll>b)
{
    return b.second > a.second;
}
pair<ll, ll> v[Max];
int main()
{
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i], v[i].first = a[i];
    for (i = 0; i < n; i++)
    {
        cin >> b;
        v[i].second = a[i] - b;
    }
    sort(v, v + n, cmp);
    for (i = 0; i < k; i++)
    {
        if (v[i].second < 0)
            break;
        v[i].first -= v[i].second;
    }
    int sum = 0;
    for (i = 0; i < n; i++)
        sum += v[i].first;
    cout << sum;
}
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int  Max = 1e7;
ll a[Max],s[Max];
int n,m,k,x,y,b,c,d,maxx= 0;
int i,j;
pair <ll,ll>v[Max];
int f[Max];
int fib(int n)
{
    f[0] = 1;
    f[1] = 1;
    for(i = 2;i<=n;i++)
    {
        f[i] = f[i-1]+f[i-2];
    }
}
int main()
{
    
}