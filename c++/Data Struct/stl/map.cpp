#include <bits/stdc++.h>
using namespace std;
// map 会自动排序，然后map要调用两个类型的话要像模板那样声明<类型1，类型2>
// 初始化就 ={{value},{value1}}
int main()
{   
    map<int, string> ma = {{1, "lll"}, {3, "222"}, {2, "333"}};
    for(map<int,string>::iterator iter = ma.begin();iter!=ma.end();iter++)
        {
            cout<<iter->first<<" "<<iter->second<<endl;
        }
    map<int,string> mm;
    mm.insert(pair<int,string>(1,"one"));
    mm.insert(map<int,string>::value_type(2,"two"));
    cout<<mm[1];
    mm[1] = mm[2];
    cout<<mm[1];
}