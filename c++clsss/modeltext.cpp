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
#include <bits/stdc++.h>
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
int main()
{
    cin >> n >> q;
    for (i = 0; i < n; i++)
        cin >> a[i];
    while (q--)
    {
        
    }
}