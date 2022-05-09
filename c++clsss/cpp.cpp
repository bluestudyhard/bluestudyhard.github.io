#include <bits/stdc++.h>
using namespace std;
//请编写你的代码
/*
class Point
{
protected:
    float x, y;

public:
    Point();
    Point(float x1, float y1) : x(x1), y(y1)
    {
        cout << "Point constructor called" << endl;
    };
    ~Point()
    {
        cout << "Point destructor called" << endl;
    }
};
class Circle : public Point
{
private:
    float r;

public:
    Circle();
    Circle(float x1, float y1, float R) : Point(x1, y1), r(R)
    {
        cout << "Circle constructor called" << endl;
    };
    float getCircumference()
    {
        return r * 3.14 * 2;
    }
    ~Circle()
    {
        cout << "Circle destructor called" << endl;
    }
};
int main()
{
    float x, y, r;
    cin >> x >> y >> r;
    Circle c(x, y, r);
    cout << fixed << setprecision(2) << c.getCircumference() << endl;
    return 0;
}*/
/*class pp
{
public:
    pp();
    pp(string na) : name(na)
    {
        cout << "fish and sheep s'" << endl;
    };
    ~pp()
    {
        cout << "is true?" << endl;
        cout << "is true!!!!!" << endl;
    }

protected:
    string name;
};
class ass : public pp
{
private:
    string ass1, ass2;

public:
    ass();
    ass(string na, string a1, string a2) : pp(na), ass1(a1), ass2(a2)
    {
        cout << "ass are askew " << endl;
    };
    ~ass()
    {
        cout << "is true?" << endl;
    }
};
int main()
{
    ass a("zhengquede", "ass1", "ass2");
}*/
/*
class father
{
    public:
   virtual void show_name()
    {
        cout<<"father name"<<endl;
    }
};
class son:public father{
    public:
    void show_name()
    {
        cout<<"son name"<<endl;
    }

};
int main()
{
    father *f1;
    son s1;
    f1 = &s1;
    f1->show_name();//不能通过指针来访问被子类覆盖的函数
}*/
/*
class circle
{
protected:
    int r;
public:
    circle();
    circle(int R) : r(R) {}
    void display()
    {
        cout << 3.14 * r << endl;
    }
};
class desk : public circle
{
protected:
    int l, w;
public:
    desk();
    desk(int l1, int w1) : l(l1), w(w1) {}
};
class descircle : public desk
{
public:
    descircle();
    descircle(int R1, int l1, int w1) : r1(R1), desk(l1, w1)
    {
        cout << R1 * l1 * w1 << endl;
    }
private:
    int r1;
};
int main()
{
    descircle d(2, 3, 4);
}*/
/*
#include <iostream>
#include <string>
using namespace std;
class Teacher
{
public:
    Teacher();
    Teacher(string nam, int a, string t)
    {
        name = nam;
        age = a;
        title = t;
    }
    void display()
    {
        cout << "name:" << name << endl;
        cout << "age" << age << endl;
        cout << "title:" << title << endl;
    }

protected:
    string name;
    int age;
    string title;
};
class Student
{
public:
    Student();
    Student(string nam, char s, float sco)
    {
        name1 = nam;
        sex = s;
        score = sco;
    }
    void display1()
    {
        cout << "name:" << name1 << endl;
        cout << "sex:" << sex << endl;
        cout << "score:" << score << endl;
    }

protected:
    string name1;
    char sex;
    float score;
};


class Graduate : public Student, public Teacher
{
public:
    double wages;
    Graduate();
    Graduate(string name, int age, char sex, string title, float score, double wages) : wages(wages){Teacher(name, age, title), Student(name1, sex, score);}
    void show()
    {
        cout << "name:Wang-li" << endl;
        cout << "age:24" << endl;
        cout << "sex:f" << endl;
        cout << "score:89.5" << endl;
        cout << "title:assistant" << endl;
        cout << "wages:1234.5" << endl;
    }
};
int main()
{
    Graduate grad1("Wang-li", 24, 'f', "assistant", 89.5, 1234.5);
    grad1.show();
    return 0;
}
*/
/*
class A
{
public:
    int i;
    void display()
    {
        cout << "Call A:i=" << i << endl;
        cout << "Call A1:i=" << i << endl;
        cout << "Call A2:i=" << i << endl;
        cout << "Call A3:i=" << i << endl;
    }
};
class A1 : virtual public A
{
public:
    int j;

public:
};
class A2 : virtual public A
{
public:
    int k;

public:
};
class A3 : public A1, public A2
{
public:
    A3(int i1, int j1, int k1)
    {
        i = i1, j = j1, k = k1;
    }
    void disp()
    {
        display();
        cout << "i:" << i << endl;
        cout << "j:" << j << endl;
        cout << "k:" << k << endl;
    }
};
int main()
{
    int i, j, k;
    cin >> i >> j >> k;
    A3 a(i, j, k);
    a.disp();
}
*/

class Employee
{
private:
    string Name;
    int Employee_no;
    int Salary;
    double money;

public:
    Employee()
    {
        Employee_no = 1000;
        Name = "wenyitong";
        Salary = 5000;
    };
    Employee(string name, int employee_no, int salary)
    {
        Employee_no = employee_no;
        Name = name;
        Salary = salary;
        cout << "正在生成1个职员类对象，姓名：" << Name << endl;
    };
    Employee(string name)
    {
        Name = name;
        cout << "正在注销1个职员类对象，姓名：" << Name << endl;
    };
    ~Employee(){
        cout<<"111";
    }
    void Showme();
};
void Employee::Showme()
{
    if (Salary > 3000)
    {
        money = 0;
    }
    if (Salary >= 3000 && money <= 5000)
    {
        money = Salary * 0.05;
    }
    if (Salary > 5000)
    {
        money = Salary * 0.1;
    }
    cout << Employee_no << '\t' << Name << '\t' << Salary << '\t' << money << endl;
}
int main()
{
    Employee e1("wenyitong", 1000, 2000);
    return 0;
}
