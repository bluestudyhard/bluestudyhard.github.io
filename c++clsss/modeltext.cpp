/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max  = 1e9;
bool check(int x)
{

}
/*分成 [l,mid] [mid+1,r]  */
/*int bs(int l,int r)
{
    while(l<r)
    {
        int mid = l+r>>1;//除2
        if(check(mid))
         r = mid;//如果找到这个mid的性质
         else
         l = mid+1;//找不到换区间
    }
    return l;
}
/*  [l,mid-1] [mid,r]*/
/*int bs(int l,int r)
{
    while(l<r)
    {
        int mid = l+r+1;
        if(check(mid))
            l = mid;
        else
            r = mid-1;
    }
    return l;
}
vector<int> add(vector<int>&a,vector<int>&b)
{
    if(a.size()<b.size())
    return add(b,a);
    vector<int>c;
    int t = 0;
    for(int i = 0;i<a.size()||t;i++)
    {
        if(i<a.size())
        t+=a[i];
        if(i<b.size())
    }
}*/
/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max  = 1e9;
int a[1005][1005] = {0};
int dp[1005][1005];
int maxx = 0;
int i,j,k,n,m;
int main()
{
    int n;
    cin>>n;
    for(i = 1;i<=n;i++)
        for(j = 1;j<=i;j++)
        cin>>a[i][j];
    for(i = 1;i<=n;i++)
        for(j = 1;j<=i;j++)
        {
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
            if(dp[i][j]>maxx)
                maxx = dp[i][j];
        }
    cout<<maxx;
}
*/
/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
int n, i, j;
ll fpow(ll a, ll b, ll c)
{
    ll sum = 0;
    while (b)
    {
        if (b & 1)
            sum = (sum + a) % c;
        a = a * 2 % c;
        b>>=1;
    }
    return sum;
}
int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << fpow(a, b, c);
}*/
/*#include <bits/stdc++.h>
using namespace std;
int a[10000];
int n, q, i, j, k, pos, pos1, m;
/*int bs(int a[], int mid, int k)
{
    int l = a[0];
    int r = a[n - 1];
    while (l < r)
    {
        mid = (l + r) / 2;
        if (a[mid] == k)
            return mid;
        else if (a[mid] < k)
            l = mid;
        else
            r = mid;
    }
}
*/
/*int main()
{
    cin >> n >> q;
    for (i = 0; i < n; i++)
        cin >> a[i];
    while (q--)
    {   int l = a[0];
        int r = a[n-1];
        cin>>k;
        while(l<r)
        {
            m = (l+r)>>1;
            if(k<=a[m])
                r = m;
            else
                l = m+1;
        }
        if(a[l]!=k)//说明如果是最大边界，l = r时，最小边界 l = a[0]时
        //都找不到
        cout<<"-1"<<" "<<"-1"<<endl;
        else{
            cout<<l<<" ";
             l = 0;
             r = n-1;
            while(l<r)
            {
                m = l+r+1>>1;//右区间
                if(k>=a[m])
                  l = m;
                else
                  r = m-1;
            }
                cout<<r<<endl;
        }
    }
}*/
/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max = 1e7;
ll n;
ll c(ll b,ll a)
{
    ll sum = 1;
    for(ll i = b,j = 1;j<=a;i--,j++)
    {
        sum = sum*i/j;
    }
}
int main()
{
    /*1
    11
    121 c21
    1331 c32 c33
    14641 c41 c42
    a[i][i-1] = a[i-1]+a[i-2]+a[i-1][i-1];
    a[4][1] = a[3][0]+a[3][1];
    a[4][2] = a[3][1]+a[3][2];
    a[4][3] = a[3][2]+a[3][3];*/
/* for (i = 1; i <= 100; i++)
 {
     for (j = 1; j <= i - 1; j++)
     {
         a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
         stntf("%d ", a[i][j]);
     }
     stntf("\n");
 }
}*/
/*#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max = 1e7;
int minn = Max;
pair<int, int> k[Max];
int n, m;
bool p[Max] = {false};
bool cmp1(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int i, j, a;
    cin >> n;
    while (n--)
    {
        int sum = 0, sum1 = 0;
        cin >> a;
        for (i = 0; i < a; i++)
            cin >> k[i].first;
        sort(k, k + a, cmp1);
        for (i = 0; i < a; i++)
            k[i].second = abs(k[i].first - k[i+1].first);
        sort(k, k + a, cmp);
        for (i = 0; i < a; i++)
        {
            sum += k[i].first;
            k[i].second = k[i].second + k[i - 1].second;
            sum1 += k[i].second;
             cout << sum << " " << sum1 << endl;
        }
        minn = min(sum, sum1);
        cout << minn << endl;
    }
}
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Max = 1e7 + 10;
int minn = Max;
int n, m;
bitset<Max> st; //用于判断素数，以及合数
int prime[Max], p = 1;
// 2 3  8 5 7 11
// 2 一开始是2的话,进入循环,将4筛掉,然后3 存入数组，2*3 把6筛掉
int main()
{
    int N = 1e7;
    int i, j, sum = 0, cnt = 0;
    for (i = 2; i <= N; ++i)
    {
        if (!st[i])             //如果st里面的是0的话
            prime[p++] = i, cnt++; // 2 3 目的是筛掉，2的倍数，2和其他素数的共用倍数
        for (j = 1; prime[j] * i <= N; ++j)
        {
            st[prime[j] * i] = 1; //先标记素数的合数，然后筛掉 4 6 9 8 10 15
            if (i % prime[j] == 0) //如果是素数就筛到本身为止跳出循环，如果不是素数第一轮或第二轮就出去了
                break;
        }
    }
    printf("%d", cnt);
}
