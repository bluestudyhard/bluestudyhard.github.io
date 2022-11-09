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
    int n, m, cnt, a1, a2;

    string s1, s2;
    vector<string> k1;
    vector<string> k2;
    vector<string> k3;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cnt;
        if (cnt == 0)
        {

            cin >> s1;
            if (isupper(s1[0]))
                continue;
            k1.push_back(s1);
        }
        else
        {
            cin >> s2;
            if (isupper(s2[0]))
                continue;
            k2.push_back(s2);
        }
    }
    k3.insert(k3.begin(), k1.begin(), k1.end());
    k3.insert(k3.end(), k2.begin(), k2.end());
    int len = k3.size(); // 7
                         //  cout << len << endl;
    int p = 0;
    for (int j = 1; j <= m; j++)
    {
        cin >> a1 >> a2;
        if (a1 == 0)
        {
            p = (p + a2) % len;
        }
        else
        {
            p = p - a2;
            if (p <= 0)
                p = (len - a2) % len;
        }
        //  cout << p << endl;
    }

    cout << k3[p - 1];
    return 0;
}