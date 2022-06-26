#include <bits/stdc++.h>
using namespace std;
bool da(int x,int y)//sort 从大到小排序
{
    return x>y;
}
int pai(int n)
{   //1: 321 - 123 = 198 b c b-c
    //2: 981 - 189 = 792
    int a[3];
    a[0] = n/100;//1 1 9
    a[1] = n/10%10;//2 9 8
    a[2] = n%10;//3 8 1
    sort(a,a+3,da);
    int b = a[0]*100 + a[1]*10 + a[2];
    int c = a[2]*100 + a[1]*10 + a[0];
    printf("%d - %d = %d\n",b,c,b-c);
    return b-c;
}
int main()
{  
    int n,cnt = 0;
    cin>>n;
    while(n!=495||cnt == 0)
    {
        printf("%d: ",++cnt);//++cnt 表示先加了再输出cnt
        n = pai(n);
    }
}