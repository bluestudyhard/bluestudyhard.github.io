#include<stdio.h>
int main()
{  //本题要求编写程序，计算序列 2/1+3/2+5/3+8/5+... 
//的前N项之和。注意该序列从第2项起，每一项的分子是前一项分子与分母的和，分母是前一项的分子。
//输入20 输出30.66 
// 这题的难点在于，前一项的分子和分母要怎么保存。以后这种类型的题，看到有前项，用一个变量记录就好了。
    int n;
    double  fenzi = 2.0,fenmu = 1.0,sum = 0.0,cnt;
    scanf("%d",&n);
    for (int i = 1;i<=n;i++)
    {   
        sum+= fenzi/fenmu;
        cnt = fenzi;//用于记录前一项的分子
        fenzi = fenzi+fenmu;
        fenmu = cnt;//让前一项的分子等于分母。
    }
    
    printf("%.2lf",sum);
}