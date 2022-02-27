#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> k(10, 1);//双端队列，不同于queue那样只能对队伍的一端进行操作，deque可以对前面和后面的元素进行增删.
    //cout << k.front(); //==k.at(0);
    //auto i = k.begin();
    deque<int>:: iterator i = k.begin();//用迭代器遍历输出
    for (i;i!=k.end(); i++)
        cout << *i <<" ";
}