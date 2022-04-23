#include<bits/stdc++.h>
using namespace std;
class box{
    
    public:
    static int count;
    box(int n,string s):num(n),name(s){cout<<num<<name;};//初始化列表
    box(int n){num = n;}
    void calculate()
    {
        count++;
    }
    void count1()
    {
        count++;
    }
    void display()
    {
        cout<<count;
    }
    private:
    int num;
    string name;
};
int box::count = 0;
int main()
{
    box(3,"sb");
}