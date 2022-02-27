/*
链表在数据结构里面会很复杂，但是我们拼算法竞赛的话，只需要学stl
里的list就可以了。
和别的容器差不多，list的特点就是，可以像deque那样，双头进出
也可以像vector那样通过下标或者迭代器访问。
ps：他不能执行出栈操作，只能通过下标访问
常用操作: list <int> k;
        k.push_front();
        k.push_back();
        erase();
        clear();
        insert(pos,x);






/*/
#include <bits/stdc++.h>//白书例题
using namespace std;
int main()
{
    list<int> k;
    int n, i, m;
    string a;
    scanf("%d", &n);
    while (n--)
    {
        cin >> a;
        if (a == "insert")
        {
            cin >> m;
            k.push_front(m);
        }
        else if (a == "deleteFirst")
            k.pop_front();
        else if (a == "deleteLast")
            k.pop_back();
        else if (a == "delete")
        {
            cin >> m;
            for (auto i = k.begin(); i != k.end(); i++)
                if (*i == m)
                {
                    k.erase(i);
                    break;
                }
        }
    }
    int it = 0;
    for (auto i : k)
    {   if(it++)
        cout <<" ";
        cout << i;
    }
    cout<<endl;
}