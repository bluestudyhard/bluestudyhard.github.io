/*洛谷dfs训练 奇怪的电梯*/
// #include <bits/stdc++.h>
// using namespace std;

// int n, a[300];
// bool st[300];
// int c, d, minn = INT_MAX;
// void dfs(int k, int cnt)
// {
//     if (cnt >= minn)
//         return;
//     if (k == d)
//     {
//         minn = min(minn, cnt);
//         return;
//     }

//     if (k - a[k] > 0 && !st[k])
//     {
//         st[k] = true;
//         dfs(k - a[k], cnt + 1);
//         st[k] = false;
//     }
//     if (k + a[k] <= n && !st[k])
//     {
//         st[k] = true;
//         dfs(k + a[k], cnt + 1);
//         st[k] = false;
//     }
// }

// int main()
// {
//     cin >> n >> c >> d;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     dfs(c, 0);
//     if (minn == INT_MAX)
//     {
//         cout << -1;
//         return 0;
//     }
//     cout << minn;
//     return 0;
// }

/*洛谷 烤鸡*/

// #include <bits/stdc++.h>
// using namespace std;

// int n, ans[100001][11]; // n<=30
// int a[11];
// int sum = 0, cnt = 0;
// int st[205];
// void dfs(int k)
// {
//     if (sum > n)
//         return;
//     if (k > 10)
//     {
//         if (sum == n)
//         {
//             ++cnt;
//             for (int i = 1; i <= 10; i++)
//                 ans[cnt][i] = a[i];
//         }
//         return;
//     }
//     for (int i = 1; i <= 3; i++)
//     {
//         a[k] = i;
//         sum += i;
//         dfs(k + 1);
//         sum -= i;
//         a[k] = 0;
//     }
// }
// int main()
// {
//     cin >> n;
//     dfs(1);
//     cout << cnt << endl;
//     for (int i = 1; i <= cnt; i++)
//     {
//         for (int j = 1; j <= 10; j++)
//             cout << ans[i][j] << " ";
//         cout << endl;
//     }
//     return 0;
// }

/*PTA天梯赛预选赛，第一题推箱子*/
#include <bits/stdc++.h>
using namespace std;
int a[25][25];
int st[25][25];
int n;

int main()
{
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            a[i][j] = s[j] - '0';
        }
    }
    

    return 0;
}