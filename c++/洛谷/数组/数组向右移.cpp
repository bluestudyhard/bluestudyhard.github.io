方法A，纯模拟，用temp标记第一个移动的数，再让他和0交换
#include <stdio.h>
#define MAXN 10
void ArrayShift( int a[], int n, int m )
{
    int i,j,temp;
    for (i = 1;i<=m;i++)
    {
        temp = a[n-1];
        for (j = n;j>0;j--)
            a[j] = a[j-1];
            a[0] = temp;
    }
}
//利用循环数组来做，创建一个2*n的数组
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int n,m,i,a[202];
    scanf("%d %d ",&n,&m);
    for(i = 1;i<=n;i++)
    {    
        scanf("%d",&a[i]);
        a[i+n] = a[i];
    }
    m%=n;//取模很重要，不取模，在m>n时就寄了。而小数对大数取模=小数 例 6%100=6.
    for(i = n-m+1;i<=2*n-m;i++)
        {
            printf("%d",a[i]);
            putchar(' ');
        }
}