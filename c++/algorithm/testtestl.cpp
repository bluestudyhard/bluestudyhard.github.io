#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 将一个数拆分成n个数的和 dfs经典了
// void split_add(int n, int m, int a[], int k)
// {
//     if (n == 0)
//     {
//         for (int i = 0; i < k; i++)
//             cout << a[i] << " ";
//         cout << endl;
//     }
//     for (int i = m; i > 0; i--)
//     {
//         if (i <= n)
//         {
//             a[k] = i;
//             split_add(n - i, i, a, k + 1);
//         }
//     }
// }
// vector<int> a;
// vector<int> st;
// // void dfs(int cur, int k, vector<int> &nums)
// // {
// //     if (cur == k)
// //     {
// //         for (int i = 0; i < cur; i++)
// //         {
// //             cout << a[i] << " ";
// //         }
// //         cout << endl;
// //         return;
// //     }
// //     for (int i = 0; i < k; i++)
// //     {
// //         if (st[nums[i]] == false)
// //         {
// //             a.push_back(nums[i]);
// //             st[nums[i]] = true;
// //             dfs(cur + 1, k, nums);
// //             st[nums[i]] = false;
// //             a.pop_back();
// //         }
// //     }
// // }
// void dfs(int cur, int b, int d, vector<int> &nums)
// {
//     if (cur == d)
//     {
//         for (int i = 1; i <= d; i++)
//             cout << a[i] << " ";
//         cout << endl;
//         return;
//     }
//     for(int i = cur;i<b;i++)
//     {

//     }
// }
// int main()
// {
//     // /*打印沙漏*/
//     // int m, n = 0;
//     // char c;
//     // cin >> m >> c;
//     // // Sn上半部分 a1 = 3,a2 = 5 a(n-1) = 2n+1  sn = n(n+2) Sn = 2s(n-1)+1 = 2n*n-1
//     // for (int i = 1; 2 * n * n - 1 <= m;)
//     // {
//     //     n++;
//     // }
//     // n--;
//     // int an1 = 2 * n - 1, x = 0, an2 = 1; // 先求最大层的数目
//     // while (an1 > 0)
//     // {
//     //     for (int i = 0; i < x; i++)
//     //     {
//     //         cout << " ";
//     //     }
//     //     x++;
//     //     for (int i = an1; i > 0; i--)
//     //     {
//     //         cout << c;
//     //     }
//     //     cout << endl;
//     //     m -= an1;
//     //     an1 -= 2;
//     // }
//     // // 下半部分
//     // x--;
//     // while (x > 0)
//     // {
//     //     x--;
//     //     an2 += 2;
//     //     m -= an2;
//     //     for (int i = 0; i < x; i++)
//     //     {
//     //         cout << " ";
//     //     }
//     //     for (int i = 0; i < an2; i++)
//     //         cout << c;
//     //     cout << endl;
//     // }
//     // cout << m;

//     /**/
//     // 前面为1 多减
//     /*个位数统计*/
//     // int a[10] = {0}; // 桶
//     // int b[10], cnt = 0;
//     // string s;
//     // cin >> s;
//     // for (int i = 0; i < s.length(); i++)
//     // {
//     //     if (isdigit(s[i]))
//     //     {
//     //         a[s[i] - '0']++;
//     //     }
//     // }
//     // for (int i = 0; i < 10; i++)
//     // {
//     //     if (a[i] > 0)
//     //     {
//     //         b[i] = i;
//     //     }
//     // }
//     // for (int i = 0; i < 10; i++)
//     // {
//     //     if (a[i] > 0)
//     //     {
//     //         cout << b[i] << ":" << a[i] << endl;
//     //     }
//     // }
//     // return 0;
//     /*dp*/
//     // int a[5];
//     // split_add(4, 4, a, 0);
//     int n;
//     cin >> n;

//     return 0;
// }
const int N = 50;
int n, r;
int a[N + 5];
int st[N + 5];
int p[N + 5];
bool isprime(int n)
{
    if (n == 0 || n == 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 1)
            return false;
    }
    return true;
}
void dfsmei(int k)
{
    if (k > n)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    // 用for循环是为了保证我每次能走完n个数
    for (int i = 1; i <= n; i++)
    {
        if (!st[i]) // st[i]==false
        {
            a[k] = i;
            st[i] = 1;
            dfsmei(k + 1);
            cout << "康康回溯后是不是直接走这里还是走I "
                 << "i = " << i << endl; // 是直接走这里，前一个递归栈
            st[i] = 0;
            a[k] = i;
        }
    }
}
int sum = 0, cnt = INT_MAX;

void dfs2(int k, int start)
{
    if (k > r)
    {
        sum = 0;
        for (int i = 1; i <= r; i++)
        {
            sum += st[i];
        }
        if (isprime(sum))
            cnt++;

        return;
    }
    for (int i = start; i <= n; i++)
    {
        st[k] = a[i];
        dfs2(k + 1, i + 1);
        st[k] = 0;
    }
    return;
}
void solve_kaoji(int k)
{
    if (k > 10)
    {
        if (sum == n)
        {
            ++cnt;
            for (int i = 1; i <= 10; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        if (sum + i > n)
            return;
        a[k] = i;
        sum += i;
        // cout << sum << endl;

        solve_kaoji(k + 1);
        sum -= i;
    }
}
int c, d;
void sovle_elvator(int k, int cntt)
{
    if (st[k])
        return;
    if (k == d)
    {
        cnt = min(cnt, cntt);
        return;
    }
    if (k - a[k] > 0)
    {
        st[k] = 1;
        sovle_elvator(k - a[k], cntt + 1);
        st[k] = 0;
    }

    st[k] = 1;
    sovle_elvator(k + a[k], cntt + 1);
    st[k] = 0;
}
int main()
{
    cin >> n >> c >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sovle_elvator(1, 0);
    if(cnt==INT_MAX)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout << cnt;
    return 0;
}