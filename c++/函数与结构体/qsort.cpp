#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a > *(int *)b;
}
int main()
{
    int n,i,a[100];
    scanf("%d ",&n);
    for (i = 0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    for (i = 0;i<n;i++)
        printf("%d ",a[i]);
}

bool cmp(int x,int y)
{
    return x>y;
}
sort (a,a+n,cmp);//sort 从大到小排序的方法