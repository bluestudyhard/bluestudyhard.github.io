#include <bits/stdc++.h>
using namespace std;
class student
{
private:
    /*属性*/
    int age;
    string number;
    int name;
public:
    void get_message()
    {   
        cin>>age;
        cout<<age;
        if(age>150)
        return;
    }
    void get_name(string number1,int age1)
    {
         age1 = age;
         number1 = number;
        cout<<age1<<endl<<number1;
    }
};
int main()
{
    
    student s1;
    s1.get_name("2114100314",18);
    s1.get_message();
}