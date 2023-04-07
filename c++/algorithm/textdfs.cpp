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

/*蓝桥杯题库*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int b[2] = {0, 1};
bool st[100];
int a[33];
void dfs(int k)
{
    if (k > 5)
    {
        for (int i = 1; i <= 5; i++)
        {
            cout << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        a[k] = b[i];
        dfs(k + 1);
        a[k] = 0;
    }
}
// 10转16
string zhuan(int n)
{
    string s = "0123456789ABCDEF";
    string result = "";
    while (n)
    {
        result = s[n % 16] + result;
        n /= 16;
    }
    return result;
}
string zhuan8(ll n)
{
    string s = "";
    string ss = "0123456789";
    while (n)
    {
        int t = n % 8;
        s = ss[t] + s;
        n /= 8;
    }
    return s;
}
// 16转10
ll sixToTen(string s)
{
    ll result = 0;
    for (int i = s.size() - 1, j = 0; i >= 0; i--, j++)
    {
        if (isdigit(s[i]))
            result = result + ((s[i] - '0') * pow(16, j));
        else
            result = result + ((s[i] - 'A' + 10) * pow(16, j));
    }
    return result;
}
ll aa[1000][1000];
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
// ll fpow(int a, int b)
// {
//     int sum = 0;
//     while (b)
//     {
//         if (b & 1) //%2
//         {
//             a *= 2;
//             sum *= a;
//         }
//     }
// }
int main()
{
    // cout << "s2: " << s2 << endl;
    // cout << "s1: " << s1 << endl;
    // cout << "t1:" << t1 << endl;
    /*龟兔赛跑 模拟 这类题 尽量用+，不要减，加更好理解，然后看看能不能投机*/
    // v1 rabbit  v2 turtle  t 领先 s 休息秒数 L total len
    // int v1, v2, t, s, l;
    // cin >> v1 >> v2 >> t >> s >> l;
    // int t1 = 0, t2, s1 = 0, s2 = 0;
    // t2 = l / v2;
    // for (t1; t1 < t2 && s1 < l; t1++)
    // {
    //     if (s1 - s2 >= t)
    //     {
    //         s2 += v2 * s;
    //         t1 += s;
    //     }
    //     s1 += v1;
    //     s2 += v2;
    // }
    // if (t1 < t2)
    // {
    //     cout << "R" << endl
    //          << t1;
    // }
    // else if (s1 < s2)
    // {
    //     cout << "T" << endl
    //          << t2;
    // }
    // else
    // {
    //     cout << "D" << endl
    //          << t2;
    // }

    /*构造哈夫曼树*/
    // vector<int> tree;
    // int n, m, minn1, minn2, sum = 0, weight = 0;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> m;
    //     tree.push_back(m);
    // }
    // while (tree.size() > 1)
    // {
    //     if (tree.size() == 1)
    //         break;
    //     sort(tree.begin(), tree.end());
    //     sum = tree[0] + tree[1];
    //     tree.erase(tree.begin(), tree.begin() + 2);
    //     tree.push_back(sum);
    //     weight += sum;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << aa[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    /*杨辉三角 40分*/
    // int n, cnt = 0;
    // vector<int> numbers;
    // cin >> n;
    // aa[0][1] = 1;
    // aa[0][0] = 0;
    // for (int i = 1; i <= 400; i++)
    // {
    //     for (int j = 1; j <= 400; j++)
    //         aa[i][j] = aa[i - 1][j] + aa[i - 1][j - 1];
    // }
    // for (int i = 0; i < 400; i++)
    // {
    //     for (int j = 1; j <= 400; j++)
    //     {
    //         if (aa[i][j] == 0)
    //             continue;
    //         else if (aa[i][j] != 0)
    //             ++cnt;
    //         if (aa[i][j] == n)
    //         {
    //             cout << cnt << endl;
    //             return 0;
    //         }
    //     }
    // }
    // cout << cnt << endl;
    // for (int i = 0; i < 400; i++)
    // {
    //     for (int j = 1; j <= 400; j++)
    //     {
    //         if (aa[i][j] == 0)
    //             continue;
    //         cout << aa[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int cnt[10];
    for (int i = 0; i <= 9; i++)
        cnt[i] = 2021;
    int ans = 0;
    bool flag = false;
    while (!flag && ++ans)
    {
        int temp = ans;
        while (temp)
        {
            cnt[temp % 10]--;
            temp /= 10;
        }
        for (int i = 0; i <= 9; i++)
        {
            if (cnt[i] < 0)
            {
                flag = true;
                break;
            }
        }
    }
    cout << ans - 1;
    return 0;
}