#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
int st(int a,int b,int c)
{   int kk[10] = {0};
    while(a)
    {
        kk[a%10]++;
        a/=10;
    }
    while(b)
    {
        kk[b%10]++;
        b/=10;
    }
    while(c)
    {
        kk[c%10]++;
        c/=10;
    }
    for(int i = 1;i<=9;i++)
    {
        if(kk[i]!=1)
        return 0;
    }
    return 1;
}
int main()
{
    for(int i = 1000;i<=9999;i++)
        for(int j = 1;j<=100;j++)
            {
                int k = i/j;
                if(st(i,j,k)&&i%k==0)
                {
                    printf("%d = %d x %d",i,j,k);
                    cout<<endl;
                }
            }
}
*/
/*ll fpow(ll a, ll b)
{
  ll sum = 1;
  while(b)
  {
      if(b&1)
      {
          sum*=a;
      }
      a*=a;
      b>>=1;
  }
  return sum;
}
int main()
{
  cout<<fpow(2,3);
}*/

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// bool v[10000];
// int n, m, i, j, sum = 0, k;
// bool isprime(int n)
// {
//     for (i = 2; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//             return false;
//     }
//     return true;
// }
// int a[25];
// long long ans;
// void dfs(int m, int sum, int startx)
// { /* 递归深度*/
//     if (m == k)
//     {
//         if (isprime(sum))
//             ans++;
//         return;
//     }
//     for (int i = startx; i < n; i++)
//     { /*操作*/
//         sum += a[i];
//         cout << "m = " << m << " sum = " << sum << " i = " << i << endl;
//         dfs(m + 1, sum, i + 1);
//         sum -= a[i];
//         cout << "m = " << m << " sum = " << sum << " i = " << i << endl;
//     }
//     return;
// }
// int main()
// {
//     scanf("%d%d", &n, &k);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &a[i]);
//     dfs(0, 0, 0);
//     printf("%d\n", ans);
//     return 0;
// }

// int main()
// {
//     int a,i,j;
//     char c;
//     cin>>a>>c;
//     j = a/2;
//     for(i = 1;i<=a/2;i++)
//     {
//         cout<<c;
//         j--;
//         if(i-2==j)
//         {
//             cout<<endl;
//         }

//     }
// }

// int isprime(int n)
// {
//     if(n==1||n==2)
//     return 1;
//     for(int i = 2;i<=sqrt(n);i++)
//     {
//             if(n%i==0)
//                 return 0;
//     }
//     return 1;
// }
// stringstream ss;
// int ispp(ll n,ll m)
// {   int a[10] = {0};
//     int b[10] = {0};
//     while(n)
//     {
//         a[n%10]++;
//         n/=10;
//     }
//     while(m)
//     {
//         b[m%10]++;
//         m/=10;
//     }
//     for(int i = 1;i<=9;i++)
//     {
//         if(a[i]!=b[i])
//             return 0;
//     }
//     return 1;
// }

// int main()
// {
//     // string n;
//     // cin>>n;
//     string n;
//     int flag = 1;
//     cin >> n;
//     int a[22], b[22], a1[10] = {0}, b1[10] = {0};
//     for (int i = 0; i < n.length(); i++)
//     {
//         a[i + 1] = n[i] - '0';
//         b[i + 1] = a[i + 1] * 2;
//     }
//     for (int i = n.length(); i>=1; i--)
//     {
//         if (b[i] > 9)
//         {
//             b[i] -= 10;
//             b[i - 1] += 1;
//         }
//     }
//     for (int i = 1; i <= n.length(); i++)
//     {
//         a1[a[i]]++;
//         b1[b[i]]++;
//     }
//     for (int i = 1; i < n.length(); i++)
//     {
//         if (a1[i] != b1[i])
//         {
//             flag = 0;
//             break;
//         }
//     }
//     if (flag == 1)
//     {
//         cout << "Yes" << endl;
//     }
//     else
//         cout << "No" << endl;
//     for (int i = 1; i <= n.length(); i++)
//     {
//         cout << b[i];
//     }
// }

// void text(int a,int b = 9,char c = '*')
// {
//     cout<<"cuf";
// }
// int main()
// {
//     text(0,'*');
// }
int path[10];
bool s[10];
void dfs(int u)
{
    if (u > 8)
    {
        for (int i = 1; i <= 8; i++)
        {
            if (i < 8)
                cout << path[i] << ' ';
            else
                cout << path[i];
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= 8; i++)
    {
        if (!s[i])
        {
            path[u] = i;
            s[i] = true;
            dfs(u + 1);
            s[i] = false;
        }
    }
    return;
}
ll fpow(ll a, ll b, ll p)
{
    ll sum = 1;
    while (b)
    {
        if (b & 1)
        {
            sum = sum * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return sum % p;
}

int main()
{
    // vector<int> kk{1, 2, 3};
    // reverse(kk.begin(), kk.end());
    // for (auto i = kk.begin(); i != kk.end(); i++)
    // {
    //     cout << *i;
    // }
    // dfs(1);
    //     char p[5] = {'S', 'H', 'C', 'D', 'J'};
    //     int card[55];
    //     int number[55];
    //     int k;
    //     cin >> k;
    //     for (int i = 1; i <= 54; i++)
    //     {
    //         cin >> number[i];
    //     }
    //     for (int i = 1; i <= 54; i++)
    //     {
    //         int temp = i;
    //         for (int j = 0; j < k; j++)
    //         {
    //             temp = number[temp];

    //         }
    //         card[temp] = i;
    //     }
    //     cout << p[(card[1] - 1) / 13] << (card[1] - 1) % 13 + 1;// 考虑到p的第一位s是p[0]
    //     for (int i = 2; i <= 54; ++i)
    //         cout << ' ' << p[(card[i] - 1) / 13] << (card[i] - 1) % 13 + 1;
    // }

    int n, m, i = 1, j, cnt = 0;
    char c;
    cin >> n >> c;
    m = sqrt((n + 1) / 2.0);// sn = n^2;      
    for (i = m; i >= 1; i--)
    {
        for (j = 1; j <= m - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << c;
            cnt++;
        }
        cout << endl;
    }
    for (i = 2; i <= m; i++)
    {
        for (j = 1; j <= m - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << c;
            cnt++;
        }
        cout << endl;
    }
    cout << n - cnt;
}