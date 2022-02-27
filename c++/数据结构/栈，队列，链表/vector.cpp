#include <bits/stdc++.h>
using namespace std;
int main()
{ // vector 动态数组
    // vector <int> k;//通过数组赋值
    // for(vector<int>:: iterator it = k.begin();it<k.end();it++)//利用迭代器遍历
    // cout<<*it<<" ";
    // cout<<k.front();
    /*for (int i = 0;i<10;i++)//直接像数组那样赋值//cout<<k[3]; = 3 可以直接像数组那样访问下标
        {
            k.push_back(i);
        }
    //k.insert(k.begin()+1,2,3);// 插入元素 k.insert(xxbegin(),元素个数,插入的元素);
    //k.erase(k.begin()+1,k.end());
    /*while(!k.empty())//
        {
            cout<<k.back()<<" ";
            k.pop_back();
        }
/*/
    //排序直接用sort sort(k.begin(),k.end());

    int n = 5, m = 6;
    vector<vector<int>> k(n, vector<int>(m)); //定义二维vector,n行m列
    // cout<<k.size(); //= 5 行的大小
    // cout<<k[1].size();//列大小
    for (int i = 0; i < k.size(); ++i)
    {      
        for (int j = 0; j < k[i].size(); ++j)
        {   
            cout << k[i][j]<<" ";
        }
        cout <<endl;
    }
    /*v.capacity();  //容器容量

 v.size();      //容器大小

 v.at(int idx); //用法和[]运算符相同

 v.push_back(); //尾部插入

 v.pop_back();  //尾部删除

 v.front();     //获取头部元素

 v.back();      //获取尾部元素

 v.begin();     //头元素的迭代器

 v.end();       //尾部元素的迭代器

 v.insert(pos,elem); //pos是vector的插入元素的位置

 v.insert(pos, n, elem) //在位置pos上插入n个元素elem

 v.insert(pos, begin, end);

 v.erase(pos);   //移除pos位置上的元素，返回下一个数据的位置

 v.erase(begin, end); //移除[begin, end)区间的数据，返回下一个元素的位置

 

 reverse(pos1, pos2); //将vector中的pos1~pos2的元素逆序存储
}