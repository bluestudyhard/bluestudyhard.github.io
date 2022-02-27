#include <bits/stdc++.h>
using namespace std;
long long  a[2000001],b[2000001];//当数组范围不够时，开在外面
int main()
{ 

    long long n,m,i,j;
    cin>>n>>m;
    for(i = 1;i<=n;i++)
        cin>>a[i];
    for(j = 1;j<=m;j++)
     {
         cin>>b[j];
         cout<<a[b[j]]<<endl;
     }   

}