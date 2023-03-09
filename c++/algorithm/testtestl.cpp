#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    /*打印沙漏*/
    int m, i = 1, n = 1;
    char c;
    cin >> m >> c;
    for (int i = 1; 2 * n * n + n - 1 < m;)
    {
        n++;
    }
    n--; // 前面为1 多减
    int temp = n, an1 = 2 * n - 1, an2 = 2 * temp + 1;
    for(int i = an1;i>=1;i++)
    {
        
    }
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
}