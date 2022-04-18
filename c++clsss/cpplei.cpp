#include <bits/stdc++.h>
using namespace std;
/*
class Sport
{
public:
    int get()
    {
        return rank;
    }
    string get1()
    {
        return num;
    }
    double get2()
    {
        return grade;
    }
    void set_value()
    {
        cin>>rank>>num>>grade;
    }
private:
    string num;
    double grade;
    int rank;
};
int main()
{   
    Sport a[12];
    for (int i = 0; i < 12; i++)
        a[i].set_value();
    for (int i = 0; i < 12; i++)
        cout<<setw(6)<<a[i].get()<<setw(6)<<a[i].get1()<<setw(6)<<a[i].get2()<<endl;
}*/
int kk(int a,int b)
{
    return a+b;
}
double kk(double a,double b)
{
    return a+b;
}
int main()
{
    int a,b;
    double a1,b1;
    cin>>a>>b>>a1>>b1;
    cout<<kk(a,b)<<" "<<kk(a1,b1);
}
