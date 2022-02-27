#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n,b,i,sum = 0,a[20001],cnt = 0;
    cin>>n>>b;
    for(i = 0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    while(sum<b)
    {
        sum+=a[cnt];
        cnt++;
    }
    cout<<cnt;
}
//例2
#include <bits/stdc++.h>
using namespace std;
struct gold
{
    int m, v;
} a[1010];
bool cmp( gold a, gold b)
{
    return a.v * b.m > b.v * a.m;
}
int main()
{
    int n, t, m, v,i;
    double cnt = 0;
    cin >> n >> t;
    for( i = 0;i<n;i++)
        cin>>a[i].m>>a[i].v;
    sort(a,a+n,cmp);
    for(i = 0;i<n;i++)
    {
        if(t<=a[i].m)
        {
            cnt+=(double)a[i].v / (double)a[i].m * t;
            t = 0;
            break;
        }
        else
        {
            cnt+=a[i].v;
            t-=a[i].m;
        }
    }
    printf("%.2f",cnt);
}