#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{ // 洛谷 计数游戏
    // char c;
    // char s[100000];
    // int cnt = 0, w = 0, l = 0;
    // while (cin >> c && c != 'E')
    // {
    //     s[++cnt] = c;
    // }
    // // 11
    // for (int i = 1; i <= cnt; i++)
    // {
    //     if (s[i] == 'W')
    //         w++;
    //     else if (s[i] == 'L')
    //         l++;
    //     // 分差大于11 比如说 11 10 还得打
    //     if ((w >= 11 || l >= 11) && abs(w - l) > 2)
    //     {
    //         cout << w << ":" << l << endl;
    //         w = 0, l = 0;
    //     }
    // }
    // cout << w << ":" << l << endl;
    // w = 0, l = 0;
    // cout << endl;
    // for (int i = 1; i <= cnt; i++)
    // {
    //     if (s[i] == 'W')
    //         w++;
    //     else if (s[i] == 'L')
    //         l++;
    //     if ((w >= 21 || l >= 21) && abs(w - l) > 2)
    //     {
    //         cout << w << ":" << l << endl;
    //         w = 0, l = 0;
    //     }
    // }
    // cout << w << ":" << l << endl;
    /**
     * 洛谷 扫雷
     */
    // int m, n;
    // cin >> m >> n;
    // char lei[m + 5][n + 5] = {'\0'};
    // int a[m + 5][n + 5] = {0};
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cin >> lei[i][j];
    //         // cout << lei[i][j];
    //         a[i][j] = 0;
    //     }
    //     // cout << endl;
    // }
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (lei[i][j] == '*')
    //         {
    //             a[i][j - 1]++;     //左
    //             a[i][j + 1]++;     //右
    //             a[i - 1][j]++;     //上
    //             a[i + 1][j]++;     //下
    //             a[i - 1][j - 1]++; // 左上
    //             a[i + 1][j - 1]++; // 右上
    //             a[i - 1][j + 1]++; // 左下
    //             a[i + 1][j + 1]++; // 右下
    //         }
    //     }
    // }
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (lei[i][j] == '*')
    //         {
    //             cout << '*';
    //         }
    //         else
    //             cout << a[i][j];
    //     }
    //     cout << endl;
    // }
    /**
     * 洛谷 p1563
     */
    /*
    vector<pair<int, string>> k;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int nums;
        string name;
        cin >> nums >> name; // 0 s
        k.push_back(make_pair(nums, name));
    }
    int ans = 0;
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        if (k[ans % n].first == a) // 00 表示-，11表示-，相同为-
        {
            ans -= b;
        }
        else // 方向相反就＋
            ans += b;
        if (ans < 0)
        {
            ans = (ans + n) % n;
        }
    }
    cout << k[ans % n].second << endl;
    return 0;
*/
    /*
        有两个想法，一个是用二维数组，把他有没有被点的状态，就是二维数组里面存true false 判断下一个有没有被点，被点就变成true
        就这个而言，可以再整一个bool数组，来判断每一个牌是否被点，全部默认为FALSE 反正你这牌也就12张
    */
/**/
}