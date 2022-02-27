#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{   //输入样例 输入在一行中首先给出一个正整数n，之后是n个整数，其间以空格分隔。
    //4 -2 -123 100 0 p : min = -123;
    //对于这种，一行输出一堆数据的，比小的，可以先输入一个数据，作为基值。
    int n,i,cnt = 0,a,minn;
    scanf("%d",&n);
    scanf("%d",&minn);
    for (i = 1;i<=n-1;i++)
       { 
           scanf("%d",&a);
           if(a<minn)
              minn = a;
       }
    printf("min = %d",minn);
}