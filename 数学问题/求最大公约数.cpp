#include <stdio.h>
int gcd(int x, int y)
{
    int c;
    while (y!=0)//32 28
    {   c=x%y;
        x=y;
        y=c;
    }
    return x;
}
int bei (int x,y)// 最小公倍数 等于两个数相乘 / 这两个数的最大公约数
 { int temp,i;
    if (x<y)
    {
        temp = x;
        x = y;
        y = temp;
    }
    for (i = y;i>0;i++)
            if(i%x==0&&i%y==0)
                break;
    return i;
}

#include <stdio.h>
int gcd(int x,int y)
{
    int c;
    while (y!=0)
    {
        c = x%y;
        x = y;//辗转来相除
        y = c;
    }//原理，以12 4 为例 c = 0，表明，4可以被整除，那么4就是最大公约数。
    // 以 6 4 为例 6%4 = 2；
}
int gb(int x ,int y)
{   int temp;
    if (x<y)
    {
        x = t;
        x = y;
        y = t;
    }
    for (int i = x;i>=0;i++)
        {
            if (i%x==0&&i%y==0)
                break;
        }
        return i;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()//不用函数的方法
{   
    int a,b,c,m,n,y;
    scanf("%d %d",&a,&b);
    m = a;
    n = b;
    while(b!=0)
    {
        c = a%b;
        a = b;//记得返回a值，因为a才是最后记录b的值
        b = c;
    }
    y = m*n/a;
    printf("%d %d",a,y);
}