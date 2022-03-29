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
*#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int Max = 1e7;
int n, m, x, y, b, c, d;
int maxx = 0, maxxx = -1;
int i, j;
pair<ll, ll> v;
bool cmp(string a, string b)
{
    return a + b < b + a;
}
vector<int> a[Max];
int main()
{
    int pos[100];
    int k = 1;
    string s;
    cin >> n;
    cin >> s;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            pos[k] = i;
            k++;
        }
    }
    for (i = 0; i < k; i++)
    {
        d = (pos[i + 1] - pos[i])/2;
        maxx = max(maxx, d);
    }
    cout << maxx;
}
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n, m, x, y, b, c, d, i, j;
const int Max = 1e7;
const int money = 251;
const int coin = 5;
int minn[Max], type[coin] = {1, 5, 10, 25, 50}; // minn数组内容,记录硬币数量,下标表示金额。
void dp()
{
    for (int k = 0; k < money; k++)
        minn[k] = INT_MAX;
    minn[0] = 0;
    for (i = 0; i < coin; i++)
        for (j = type[i]; j < money; j++) //这两个循环把所有硬币种类都算了一遍取了最小值。
        {
            minn[j] = min(minn[j], minn[j - type[i]] + 1);
            cout << minn[j] << endl;
        }
}
ll fpow(ll a, ll b)
{
    ll sum = 1;
    while (b)
    {
        if (b & 1) //如果是0就跳一位不乘比如11 1011 101 10 1 a1 * a2 * a8
            sum = sum * a % c;
        a = a*a%c;
        b >>= 1;
    }
    return sum;
}
int main()
{
    clock_t tbegin, tend;
    tbegin = clock();
    {
        
    }
    tend = clock();
    printf("\ntime cost : %.3f\n", (tend - tbegin) / 1000.);
}