#include <bits/stdc++.h>
using namespace std;
int ans,k,n,m,sum,i,j;
int a[100000];
bool isprime(int n)
{
    for(i = 2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            return false;
        }
        return true;
}
void dfs(int m,int sum,int star)
{
    if(m==k)
    {
        if(isprime(sum))
            ans++;
        cout<<"zhongzhi: "<<sum<<" "<<" m: "<<m<<" "<<star<<endl;
        return;//�����ݹ�
    }
    for(i = star;i<n;i++)
    {   //�ݹ���Ҫ�ڵݹ�ǰ�͵ݹ���Ѿ���ֹ����ǰ,�������ݼ��.
        cout<<"shang: "<<sum<<" "<<" m: "<<m<<" "<<star<<endl;
        dfs(m+1,sum+a[i], star+1);
        cout<<"xia: "<<sum<<" "<<" m: "<<m<<" "<<star<<endl;
    }
    return;//������ѭ����Ž����ݹ�
}
int main()
{
    cin>>n>>k;
    for(i = 0;i<n;i++)
        cin>>a[i];
    dfs(0,0,0);
    cout<<ans;
}
