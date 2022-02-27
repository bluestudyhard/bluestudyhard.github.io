#include<bits/stdc++.h>
using namespace std;
int main()
{ //这题考的还是入栈出栈的基本运用，但是不同的是，这题要考虑转换字符为数字
  //而且一直很让我迷糊的点是，为什么，答案的没有push，容器里就有东西。然后
  //我发现了本题的核心，就是那个非字符，进栈。这样，就可以在读到+-*的时候
  //进行出栈操作，将这两个加起来，再入栈，然后以此类推，下一次-的时候，也是
  //只对-号的两个数字进行处理，然后再与原本处理好的，在栈底的数据运算。
  //最后在栈顶的，只有最终运算的结果
  //例 s: 1 2 + 3 4 - *  1 2 + 3 4 - 4 5 * + => -3  19
    char s; int a, b;
    stack<int> S;
    while ((s = getchar())!='\n')
    {
        if (s == '+'||s == '-' || s == '*')
        {
            b = S.top();S.pop();
            a = S.top();S.pop();
            if (s == '+')
            S.push(a + b);
            else if (s == '-')
            S.push(a - b);
           else  if (s == '*')
            S.push(a * b);
        }
        else if (isdigit(s))//核心
            S.push(s-'0');
    }
    printf("%d\n", S.top());
}
}