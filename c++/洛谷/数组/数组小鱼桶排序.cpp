#include <iostream> //memset(a,0,sizeof(a)); menset初始化
using namespace std;
int main()
{
    int n, i = 1, j, a[100] = {0}, b[100] = {0}, s;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];//输入数，存入数组
    for (i = 1; i <= n; i++)//给i赋值
        for (j = i; j >= 1; j--)//从最后一位往前排。
        {
            if (a[j] < a[i])
                b[i]++;//i对应b数组里面的数，加一表示出现次数加一
        }
    for (i = 1; i <= n; i++)//把出现次数输出
        printf("%d ", b[i]);
}


#include <iostream>
using namespace std;
int main()
{
    int a[100] = {1}, i = 0, j;
    for (i = 0;; i++)//当只输入一串字符时，就用这种方法。
    {
        cin >> a[i];
        if (a[i] == 0)//判断当输入数据为0时，终止程序
            break;
    }
    for (j = i; j >= 0; j--)//定义另一个变量来读入输入的数组，再反向输出
    {
        if (a[j] == 0)//跳过0.
            continue;
        printf("%d ", a[j]);
    }
}