#include <stdio.h>
int main()
{
    int l = 0, x, y, z, n;
    scanf("%d", &n);
    if (l != n)//不用套循环的输出方法
    {
        for (x = 1; x <= 20; x++)
        {
            for (y = 1; y <= 34; y++)

                for (z = 1; z <= 100; z++)
                    if (x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100 && z % 3 == 0)
                    {
                        printf("%d %d %d\n", x, y, z);
                        l++;//单独想输出几行的话，就这样做
                    }
            if (l == n)
                break;
        }
    }
    return 0;
}
//找零钱，同理
#include <stdio.h>
int main()
{
    int n, i, j, k, total = 0, count = 0;
    scanf("%d", &n);
    for (i = 100; i >=1; i--)
        for (j = 100; j >=1; j--)
            for (k = 100; k >= 1; k--)
            {
                if (5 * i + j * 2 + k == n)
                {
                    total=i+j+k;
                    count++;
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i, j, k, total);
                }
            }
            printf("count = %d",count);
}
//符号，？； 例 (a>b?a:b) == if (a>b) return a;else return b;
            (表达式1?表达式2:表达式3) 如果表达式1的结果为真，返回表达式2的值，否则返回表达式3的值
            例：(a>b?a:b)
                if (a>b==ture)            max = (a>b)?a:b;
                                                if ()
                    return a;
                    else 
                    return b;

                    a>b ? a : c>d ? c : d;====a>b?a: (c>d?c:d);