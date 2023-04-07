#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, r;
bool st[35];
int a[35];
int sum = 0, cnt = 0;
int kao[10005][11];
void dfs_meiju(int k)
{ /*每次都是选和不选，总共的可能性有2^n种*/
    if (k > n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (st[i])
                cout << i << " ";
        }
        cout << endl;
        return;
    }
    st[k] = true;
    dfs_meiju(k + 1);
    st[k] = false;
    dfs_meiju(k + 1);
}
void dfs_pailie(int k)
{
    if (k > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = true;
            a[k] = i;
            dfs_pailie(k + 1);
            st[i] = false;
            a[k] = 0;
        }
    }
}
void dfs_zuhe(int k, int start)
{
    if (k > r)
    {
        for (int i = 1; i <= r; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++)
    {
        a[k] = i;
        dfs_zuhe(k + 1, i + 1);
        a[k] = 0;
    }
}
void kaoji(int k)
{
    if (sum > n)
        return;
    if (k > 10)
    {
        if (sum == n)
        {
            cnt++;
            for (int i = 1; i <= 10; i++)
            {
                kao[cnt][i] = a[i];
            }

            return;
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        if (sum + i > n)
            return;
        a[k] = i;
        sum += i;
        kaoji(k + 1);
        a[k] = 0;
        sum -= i;
    }
}
bool ishui(string s)
{
    string ss = string(s.rbegin(), s.rend());
    if (ss == s)
        return true;
    return false;
}
bool realhui(int n)
{
    int temp = n;
    int sum = 0;
    while (n)
    {
        int res = n % 10;
        sum = sum * 10 + res;
        n /= 10;
    }
    if (sum == temp)
        return true;
    return false;
}
int summ(int n)
{
    int sum = 0;
    while (n)
    {
        sum = sum + n % 10;
        n /= 10;
    }
    return sum;
}
void qianzhui(int *a, int *b, int n)
{
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
}
int main()
{
    // dfs_meiju(1);
    // dfs_pailie(1);
    int n, m, k;
    int a[100][100], s[100][100];
    s[0][1] = 0, s[1][0] = 0, s[0][0] = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
    return 0;
}