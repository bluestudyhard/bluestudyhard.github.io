#include <bits/stdc++.h>
using namespace std;
int main()
{
    string name;
    int t, n, q;
    queue<pair<string, int>> k; // define an empty pair;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> t;
        k.push(make_pair(name, t)); //将空的pair赋值成为一个新的pair 然后再压入队列里。
    }
    pair<string, int> l;
    int sum = 0, t1;
    string name1;
    //开始模拟//
    while (!k.empty()) //操作完了之后，k是空的，都到l去了
    {
        l = k.front();
        k.pop(); //给l 赋值
        // if(k.first > q e = k.first k.first = q,q=e 交换可以用min()函数，返回小值)
        t1 = min(l.second, q);
        l.second -= t1;
        sum += t1;
        // t1计算完毕，现在队列要把第一个推到后面去，条件就是，l.second>0
        if (l.second > 0) //在所有的数字清空前，一直循环
        {
            k.push(l); //往原来的queue里代
        }
        else
            cout << l.first << " " << sum << endl; //其他的，清空了的就可以输出了
    }
}
/*input  
5 100
p1 150
p2 80
p3 200
p4 350
p5 20 

/*output
p2 180
p5 400
p1 450
p3 550
p4 800
//队列的另一例题，循环数组，循环队列类型
#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> k;
    int n, m, i, cnt = 1, t;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
        k.push(i);
    while (!k.empty())
    {
        if (cnt == m)
        {
            cout << k.front() << " ";
            k.pop();
            cnt = 1;
        }
        else
        {
            cnt++;
            t = k.front();
            k.pop();
            k.push(t);
        }
    }
}