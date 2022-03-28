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
#include<bits/stdc++.h>
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