/*#include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000], j, n, k, sum, m;
bool v[1000];
void dfs(int u)
{ /*终止条件*/
/*    int i;
    if (u > m)
    {
        for (i = 1; i <= m; i++)
            cout<<setw(3)<<a[i];//c++中打间隔的方式
        cout << endl;
        return;
    }
    for (i = a[u - 1] + 1; i <= n; i++)
    {
        a[u] = i; // 1 25
        dfs(u + 1);
    }
}
int main()
{
    cin >> n >> m;
    dfs(1);
}*/
#include <bits/stdc++.h>
using namespace std;
int a[100056];
int num(int n)
{
    int ans;
    while (n)
    {
        ans += n % 10;
        n/=10;
    }
    return ans;
}
int main()
{
    int n;
    char s[100];
    cin>>n;
    for(int i = 1e4;i<1e6;i++)
        {
            if(num(i)==n)
                
            
        }
}