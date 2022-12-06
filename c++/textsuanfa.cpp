#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = INT_MAX;
const int MIN = INT_MIN;
int a[1005][1005], sum[1005][1005];
const int months[] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(string s)
{
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] + 1 == s[i + 1] && s[i] + 2 == s[i + 2])
        {
            return true;
        }
    }
    return false;
}
ll pos(int n)
{
    ll sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}
bool isprime(ll n)
{
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int changeten(string s, int radix)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            sum = sum * radix + s[i] - '0';
        else
            sum = sum * radix + s[i] - 'A' + 10;
    }
    return sum;
}
int st[10000];
int u;
void easydfs(int n)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
            cout << st[i] << " ";
        cout << endl;
        return;
    }
    for (int i = st[u - 1] + 1; i <= n; i++)
    {
        st[u] = i;
        easydfs(u + 1);
    }
}
const int N = 1e8 + 20;
ll c[N];
int main()
{
    /*洋的奇幻冒险*/
    // int m, a[7], b[7], flag = 1000;
    // string s1;
    // for (int i = 0; i < 6; i++)
    // {
    //     cin >> a[i];
    // }
    // cin >> s1 >> m;
    // while (m)
    // {
    //     m %= 6;
    // }
    // for (int i = 0, j = m; j < 6 + m; i++, j++)
    // {
    //     b[j % 6] = a[i];
    // }
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << b[i] << " ";
    //     if (b[i] == 1)
    //     {
    //         flag = min(flag, i); // 第一个出现子弹的位置
    //     }
    // }
    // cout << endl;
    // if (flag % 2 == 0)
    // {
    //     if (s1 == "sheep")
    //         cout << "fish" << endl;
    //     else
    //         cout << "sheep" << endl;
    // }
    // else
    // {
    //     if (s1 == "sheep")
    //         cout << s1 << endl;
    //     else
    //         cout << "fish" << endl;
    // }
    // int n, m, a[1000];
    // cin >> n >> m;
    // // 声明了一个两倍的数组
    // // 1 2 3 4 5 6 1 2 3 4 5 6
    // for (int i = 1, j = n + 1; i <= n; i++, j++)
    // {
    //     cin >> a[i];
    //     a[j] = a[i];
    // }
    // while (m)
    // {
    //     if (m < n)
    //         break;
    //     m %= n;
    // }
    // for (int i = n - m + 1; i <= 2 * n - m; i++)
    //     cout << a[i] << " ";
    // int n, m, sum = 0, cnt = 0;
    // cin >> n >> m;
    // for (int i = 1; i <= n; i++)
    //     cin >> a[i];
    // for (int i = 1; i <= n; i++)
    // {
    //     sum += a[i];
    //     if (sum == m)
    //     {
    //         cnt++;
    //         sum = 0;
    //     }
    // }
    /*gcd*/
    // int n, m;
    // cin >> n >> m;
    // int g = __gcd(n, m);
    // cout << g << " " << (n / g) * (m / g) * g;
    // return 0;
    /*
        洛谷笨猴子
    */
    // int a[27] = {0}, maxx = MIN, minn = MAX;
    // string s;
    // cin >> s;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     a[s[i] - 'a']++;
    // }
    // for (int i = 0; i < 27; i++)
    // {
    //     if (a[i] != 0)
    //     {
    //         maxx = max(a[i], maxx);
    //         minn = min(a[i], minn);
    //     }
    // }
    // if (isprime(maxx - minn))
    // {
    //     cout << "Lucky Word" << endl;
    //     cout << maxx - minn;
    // }
    // else
    // {
    //     cout << "No Answer" << endl;
    //     cout << 0;
    // }
    /*
        去年蓝桥杯真题
    */
    // 编程题第一题
    // ll a, b, c;
    // cin >> a >> b >> c;
    // ll sum = c, cnt = 0;
    // while (sum > 0)
    // {
    //     for (int i = 1; i <= 7; i++)
    //     {
    //         if (sum <= 0)
    //             break;
    //         if (i <= 5)
    //         {
    //             sum -= a;
    //             cnt++;
    //         }
    //         else
    //         {
    //             sum -= b;
    //             cnt++;
    //         }
    //     }
    //     if (sum <= 0)
    //         break;
    // }
    // ll a, b, c;
    // cin >> a >> b >> c;
    // ll sum = a * 5 + b * 2;
    // ll cnt = c / sum * 7; // 这一步是算直接干
    // c %= sum;             // 看mod掉一周，剩下的多少天干完。
    // while (c > 0)
    // {
    //     for (int i = 1; i <= 7; i++)
    //     {
    //         if (c <= 0)
    //             break;
    //         if (i <= 5)
    //         {
    //             c -= a;
    //             cnt++;
    //         }
    //         else
    //         {
    //             c -= b;
    //             cnt++;
    //         }
    //     }
    // }
    // cout << cnt;

    // cout << cnt;
    // 第二题 修树
    // int n;
    // cin >> n;
    // if (n == 1)
    // {
    //     cout << 1;
    //     return 0;
    // }
    // if (n == 2)
    // {
    //     cout << 1 << endl;
    //     cout << 2;
    //     return 0;
    // }
    // if (n % 2 == 0)
    // {
    //     for (int i = n; i > n / 2; i--)
    //     {
    //         cout << 2 * i - 2 << endl;
    //     }
    //     for (int i = n / 2; i < n; i++)
    //     {
    //         cout << 2 * i << endl;
    //     }
    // }
    // else if (n % 2 == 1)
    // {
    //     for (int i = n; i > n / 2; i--)
    //     {
    //         cout << 2 * i - 2 << endl;
    //     }
    //     for (int i = n / 2; i < n - 1; i++)
    //     {
    //         cout << 2 * i + 2 << endl;
    //     }
    // }
    /*
        蓝桥杯算年份那道 y总解法
    */
    /*月份的题可以整一个辅助数组 */
    // int year = 2022, month = 1, day = 1;
    // int cnt = 0;
    // for (int i = 0; i < 365; i++)
    // {
    //     char str[10];
    //     sprintf(str, "%04d%02d%02d", year, month, day);
    //     if (check(str))
    //     {
    //         cnt++;
    //         cout << str << endl;
    //     }
    //     ++day;
    //     if (day > months[month])
    //     {
    //         day = 1;
    //         month++;
    //     }
    // }
    // cout << cnt;
    // return 0;
    /*进制转换，这题是一个进制转换的基础加一个贪心*/
    // const int range = 1e6 + 10;
    // const int mod = 1000000007;
    // int n, ma, mb, a, b;
    // vector<int> num1(range);
    // vector<int> num2(range);
    // vector<int> num3(range);
    // vector<int> k(range);
    // cin >> n;
    // cin >> ma;
    // 倒着来输入
    // for (int i = 0; i < ma; i++)
    // {
    //     cin >> num1[i];
    // }
    // cin >> mb;
    // int len = max(ma, mb);
    // for (int i = 0; i < mb; i++)
    // {
    //     cin >> num2[i];
    //     // num3[i] = abs(num1[i] - num2[i]); // 9 2 0
    // }
    // reverse(num1.begin(), num1.end());
    // reverse(num2.begin(), num2.end());
    // while (num1.size() != num2.size())
    // {
    //     if (num1.size() < num2.size())
    //     {
    //         num1.push_back(0);
    //     }
    // }
    // ll ans = 0;
    // for (int i = 0; i < len; i++)
    // {
    //     if (num3[i] <= 0)
    //         k[i] = 2;
    //     else
    //         k[i] = max(num1[i], num2[i]) + 1; // 11 5 2
    // }
    // //   cout << endl;
    // k[num1.size()] = 1;
    // k[num2.size()] = 1;
    // for (int i = 0; i < len; i++)
    // {
    //     ans = (ans + num3[i]) * k[i + 1] % mod;
    //     // cout << ans << " ";
    // }
    // cout << ans % mod;
    // 逆向输入可以避免位数不齐的问题
    // for (int i = ma - 1; i >= 0; i--)
    // {
    //     cin >> num1[i]; // 10 4 0
    // }
    // cin >> mb;
    // for (int i = mb - 1; i >= 0; i--)
    //     cin >> num2[i];
    // int len = max(ma, mb);
    // ll ans = 0;
    // for (int i = len - 1; i >= 0; i--)
    // {
    //     ll temp = num1[i] - num2[i];
    //     ll muti = max({2, num1[i] + 1, num2[i] + 1}); // 如果为0的话，那就是变成2进制
    //     ans = (ans * muti + temp) % mod;              // 秦九昭算法
    // }
    // cout << ans % mod;
    // return 0;
    /*
        一维前缀和

        sum[i] = sum[i-1]+a[i];
        sum(l,r) = sum[r]-sum[l-1];

    int n, m, l, r;
    int a[100005], sum[100005];
    sum[0] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    while (m--)
    {
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl; //
    }
    */
    /*二维前缀和*/
    // int n, m, p, x1, y1, x2, y2;

    // sum[0][1] = 0;
    // sum[1][0] = 0;
    // cin >> n >> m >> p;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         cin >> a[i][j];
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //         sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + a[i][j] - sum[i - 1][j - 1];
    // }
    // while (p--)
    // {
    //     cin >> x1 >> y1 >> x2 >> y2;
    //     cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << endl;
    // }
    // int n, m, x1, x2, y1, y2;
    // cin >> n >> m;
    // while (m--)
    // {
    //     cin >> x1 >> y1 >> x2 >> y2;
    //     for (int i = x1; i <= x2; i++)
    //         for (int j = y1; j <= y2; j++)
    //         {
    //             ++a[i][j];
    //         }
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    /*差分*/
    // b[i][j] = a[i][j]-a[i-1][j]-a[i][j-1]+a[i-1][j-1];
    // 一维差分
    ll n;
    cin >> n;
    c[0] = c[1] = 1;
    for (int i = 2; i <= n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            c[i] += c[j] * c[i - j - 1];
        }
    }
    cout << c[n];
}