#include <bits/stdc++.h>
using namespace std;
#include<ctime>
int fi(int n)
{
    if(n==1||n==0)
    return 1;
    return fi(n-1)+fi(n-2);
}
int main()
{   int n;
    cin>>n;
    clock_t start,end;
    start = clock();
    fi(n);
    end = clock();
    cout<<fi(n)<<endl<<(double)(end - start)/CLOCKS_PER_SEC<<endl;
}