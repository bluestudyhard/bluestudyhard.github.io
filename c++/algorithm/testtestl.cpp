#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 将一个数拆分成n个数的和 dfs经典了
void split_add(int n, int m, int a[], int k)
{
    if (n == 0)
    {
        for (int i = 0; i < k; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    for (int i = m; i > 0; i--)
    {
        if (i <= n)
        {
            a[k] = i;
            split_add(n - i, i, a, k + 1);
        }
    }
}
void spilt(int n,int a[],int k)
{
    
}
int main()
{
    /*打印沙漏*/
    // int m, n = 0;
    // char c;
    // cin >> m >> c;
    // // Sn上半部分 a1 = 3,a2 = 5 a(n-1) = 2n+1  sn = n(n+2) Sn = 2s(n-1)+1 = 2n*n-1
    // for (int i = 1; 2 * n * n - 1 < m;)
    // {
    //     n++;
    // }
    // n--;
    // int an1 = 2 * n - 1, x = 0, an2 = 1; // 先求最大层的数目
    // while (an1 > 0)
    // {
    //     for (int i = 0; i < x; i++)
    //     {
    //         cout << " ";
    //     }
    //     x++;
    //     for (int i = an1; i > 0; i--)
    //     {
    //         cout << c;
    //     }
    //     cout << endl;
    //     m -= an1;
    //     an1 -= 2;
    // }
    // // 下半部分
    // x--;
    // while (x > 0)
    // {
    //     x--;
    //     an2 += 2;
    //     m -= an2;
    //     for (int i = 0; i < x; i++)
    //     {
    //         cout << " ";
    //     }
    //     for (int i = 0; i < an2; i++)
    //         cout << c;
    //     cout << endl;
    // }
    // if (m == 0)
    //     return 0;
    // cout << m;

    /**/
    // 前面为1 多减
    /*个位数统计*/
    // int a[10] = {0}; // 桶
    // int b[10], cnt = 0;
    // string s;
    // cin >> s;
    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (isdigit(s[i]))
    //     {
    //         a[s[i] - '0']++;
    //     }
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     if (a[i] > 0)
    //     {
    //         b[i] = i;
    //     }
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     if (a[i] > 0)
    //     {
    //         cout << b[i] << ":" << a[i] << endl;
    //     }
    // }
    // return 0;
    /*dp*/
    int a[5];
    split_add(4, 4, a, 0);
}