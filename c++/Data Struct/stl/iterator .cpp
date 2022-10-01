/*
迭代器的命名方式
例：vector <int>::iterator it = xx.begin();
c++11以后，迭代器可以直接用auto来
可以使用迭代器的容器：
vector 随机访问，
 deque 随机访问， stack 不支持，
 queue 不支持， priority_queue 不支持
list 双向，set 双向， multiset 双向 ， map 双向， multimap 双向
/*/
#include <bits/stdc++.h>
using namespace std;
int main()
{   
    vector<int>k={1,2,3,4,5};
    auto it= k.begin();// == vector<int>::iterator it = k.begin()
    //for(it;it!=k.end();it++)
        //cout<<*it<<" ";
    for(auto it : k)
        cout<<it<<" ";
}
