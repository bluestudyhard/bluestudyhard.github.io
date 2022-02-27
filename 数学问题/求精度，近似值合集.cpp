#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main()
{   //本题要求编写程序，计算序列部分和 1 - 1/4 + 1/7 - 1/10 + ...
    // 直到最后一项的绝对值不大于给定精度eps。
    //s: 4E-2 这是科学计数法，表示，4*10-2次方 p：sum = 0.854457
    double eps;
    double sum = 0, i = 1, cnt = 1, sum1 = 1;
    scanf("%lf", &eps);
    sum1 = cnt * 1.0 / i;//先计算第一项，不知道为啥
    sum = sum + sum1;
    while (fabs(sum1) > eps)
    {
        i += 3;//分母
        cnt = -cnt;//变号
        sum1 = cnt * 1.0 / i;//代表每一项
        sum = sum+sum1;
    }
    printf("sum = %.6lf", sum);
}