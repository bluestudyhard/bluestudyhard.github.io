#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fib(int n)
{
    return fib(n) * fib(n - 1);
}
// vector<int> kk;
// int n;
// void dfs(int u)
// {
//     if (u > n)
//     {
//         for (auto i : kk)
//             cout << i << " ";
//         cout << endl;
//         return;
//     }
//     kk.push_back(u);
//     dfs(u + 1);
//     kk.pop_back();
//     dfs(u + 1);
//     return;
// }
int a[50]; // 0
bool f[50];
int n, m;
void dfs(int u) // start 记录节点
{
    if (u > m)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = a[u - 1] + 1; i <= n; i++)
    {
        a[u] = i;
        dfs(u + 1);
        // u-1
    }
    return;
}
int main()
{
    cin >> n >> m;
    dfs(1);
    // int n;
    // string s;
    // cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> s;

    //     if (s[0] == 'y' || s[0] == 'Y')
    //     {
    //         if (s[1] == 'e' || s[1] == 'E')
    //         {
    //             if (s[2] == 's' || s[2] == 'S')
    //             {
    //                 cout << "YES" << endl;
    //                 continue;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         cout << "NO" << endl;
    //         continue;
    //     }

    //     cout << "NO" << endl;
    // }
    // bool st[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // int n, m;
    // string s;
    // cin >> n;
    // while (n--)
    // {
    //     int cnt = 0;
    //     cin >> m;
    //     cin >> s;
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         if (st[s[i]] == false)
    //         {
    //             cnt += 2;
    //             st[s[i]] = true;
    //         }
    //         else
    //         {
    //             ++cnt;
    //             st[s[i]] = false;
    //         }
    //     }image.pngl;
    // }
    // int n, t;
    // cin >> t;
    // while (t--)
    // {
    //     string s;
    //     cin >> n >> s;.-
    //     set<char> ss;
    //     for (auto x : s)
    //         ss.insert(x);
    //     cout << ss.size() * 2 + s.size() - ss.size() << endl; //因为set去重，只出现一次字母，x2，然后加上所有的字符，再减去已经x2的就行了
    // }

    // vector<int> a = {1,2,3};
    // a.erase(a.begin()+2);
    // for(int i = 0;i<a.size();i++)
    //     cout<<a[i]<<" ";

    // set<int> kk;
    // int n, k, sum = 0;
    // cin >> n >> k;
    // int m[n + 1];
    // for (int i = 1; i <= n; i++)
    //     cin >> m[i];
    // for (int i = 1; i <= 2 * k; i += 2)
    // {
    //     if (i == 2*k)
    //         break;
    //     sum += m[i + 1] - m[i];
    // }
    // cout << sum;
    // int n, m;

    // cin >> n;
    // while (n--)
    // {
    //     cin >> m;
    //     int cnt = 0;
    //     int a[m + 5];
    //     for (int i = 1; i <= m; i++)
    //     {
    //         cin >> a[i];
    //     }
    //     sort(a + 1, a + m + 1);
    //     int minn = 1e9;
    //     int minn1 = 0;
    //     for (int i = 1; i <= m - 1; i++)
    //     {
    //         if (a[i] == a[i + 1] && a[i] == a[i - 1])
    //         {
    //             cout << "0" << endl;
    //             break;
    //         }
    //         else if (a[i] < minn)
    //         {
    //             minn = a[i];
    //         }
    //         else if (a[i] == a[i + 1])
    //         {
    //             cnt = 1;
    //             minn1 = a[i + 2] - a[i + 1];
    //             cout << minn1 - minn << endl;
    //             break;
    //         }
    //         else if (a[i - 1] != a[i] && a[i] != a[i + 1] && a[i + 1] != a[i- 1] )
    //         {
    //             int ans = a[i + 1] - a[i - 1];
    //             cout << ans << endl;
    //             break;
    //         }
    //     }

    // }
}