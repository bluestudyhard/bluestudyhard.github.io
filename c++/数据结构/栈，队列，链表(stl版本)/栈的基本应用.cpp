#include <bits/stdc++.h>
using namespace std;
stack<int> k;
int main()
{   //题目简介，输入一串数列入栈，q是问题数目，n是入栈的数据长度，问，入
    //栈是否等于出栈 例：1 2 3 4 5   5 4 3 2 1 => Yes; 12345 53421 No;
    //这题给我们的思路是，要想到用另一个数组来做检验数组，而且，学了一个判断
    //数组数据是否=的办法。
    int q, n;
    stack<int> k;
    cin >> q;
    while (q--)
    {
        cin >> n;
        int a[n + 1], b[n + 1], i, j = 1;
        for (i = 1; i <= n; i++)
            cin >> a[i]; // 12345
        for (i = 1; i <= n; i++)
            cin >> b[i]; //用b数组来校验 54321
        for (i = 1; i <= n; i++)
        {
            k.push(a[i]); //将a数组的数据入栈
            while (k.top() == b[j])
            {
                k.pop(), j++;//如果每个元素相同，就让j的指针指向下一个并且让上一个元素出栈。
                if (k.empty())//只有符号正确序列才会提前清栈。这里表示，序列元素一直相同到最后一位。
                    break;
            }
        }
        if (k.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        while (!k.empty())
            k.pop();
    }
}