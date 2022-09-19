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
/*
class point
{
private:
    double x, y;

public:
    point();
    point(double x, double y);
    double distance();
    double distance(const point &p);
    double getx()
    {
        return x; //返回的是我point类的x，和y
    }
    double gety()
    {
        return y;
    }
    void ctr(double x, double y);
};
double point::distance()
{
    return sqrt(getx() * getx() + gety() * gety());
}
point::point(double x_, double y_)
{
    x = x_, y = y_;
}
class circle
{
private:
    double X, Y, R;

public:
    circle(point ctr, double r) //是指，引用了点对象里面的ctr成员
    {
        X = ctr.getx(), Y = ctr.gety();
        R = r;
    }
    string judge(point p)
    {
        double dis = sqrt(X - p.getx() * X - p.getx() + (Y - p.gety() * Y - p.gety()));
        if (dis > R)
            return "outside";
        else if (dis < R)
            return "inside";
        else
            return "ON";
    }
};
int main()
{
    double x1, y1, x2, y2, r;
    cin >> x1 >> y1 >> x2 >> y2 >> r;
    point p(x1, y1);
    point ctr(x2, y2);
    circle c(ctr, r);
    cout << setprecision(3) << p.distance() << " " << c.judge(p) << endl;
}*/
/*
class box
{
private:
    int length;

public:
    void set_length(int l);
    friend void printt(box b); //友元函数
};
void box::set_length(int l) { length = l; }
void printt(box b) { cout << b.length << endl; }
int main()
{
    box b;
    b.set_length(10);
    printt(b);
}*/
/*
class box
{
private:
    int w;

public:
    friend class bbox;
    void set_lwh(int w1);
};
void box::set_lwh(int w1)
{
    w = w1;
}
class bbox
{
public:
    void print(int width, box &box)
    {
        box.set_lwh(width);
        cout<<width;
    }
};
int main()
{
    box b;
    bbox b1;
    b.set_lwh(20);
    b1.print(20, b);
}*/
//什么是operator 首先，重载运算符，他的作用就是把，像+-*这样的运算符，重载
/*
class person
{
    private:
    int age;
    public:
    bool operator==(const person &ps) const;
    person(int a)
    {
        this->age = a;
    }

};
int main()
{
    person p1(10);
    person p2(10);
    if(p1==p2)
    cout<<"yes";
}*/
/*#include <bits/stdc++.h>
using namespace std;
#define pi 3.1415
class shape
{
public:
    double s;
    void settotal();
};
class circle : public shape
{
private:
    double R;
public:
    circle(double r1):R(r1)
    {
        s = R * R * pi;
    }
};
class rectangle : public shape
{
private:
    double l, w;
public:
    rectangle(double l1, double w1):l(l1),w(w1)
    {
        s = l * w;
    }
};
class triangle : public shape
{private:
    double h, d;
public:
    triangle(double h1, double d1):h(h1),d(d1)
    {
        s = h * d / 2.0;
    }
};
void shape::settotal()
{
    cout << fixed << setprecision(2) << s << endl;
}
int main()
{
    double r, l, w, h, d;
    cin >> r >> l >> w >> h >> d;
    circle c1(r);
    rectangle r1(l, w);
    triangle t1(h, d);
    c1.settotal();
    r1.settotal();
    t1.settotal();

}*/

class Vehicle
{
protected:
    string NO;

public:
    Vehicle();
    Vehicle(string no) : NO(no) {}
    virtual void display() = 0;
};
class Car : public Vehicle
{
private:
    int number, weight;

public:
    Car();
    Car(string no, int number, int weight) : Vehicle(no), number(number), weight(weight)
    {
    }
    void display()
    {
        cout << NO << " " << number * 8 + weight * 2 << endl;
    }
};
class Truck : public Vehicle
{
private:
    int weight;

public:
    Truck();
    Truck(string no, int weight) : Vehicle(no), weight(weight)
    {
    }
    void display()
    {
        cout << NO << " " << weight * 5 << endl;
    }
};
class Bus : public Vehicle
{
private:
    int number;

public:
    Bus();
    Bus(string no, int number) : Vehicle(no), number(number)
    {
    }
    void display()
    {
        cout << NO << " " << number * 3 << endl;
    }
};
int x, y;
int f(int x = 0)
{
    x++;
    y++;
    ::x++;
    cout << "y=" << y << "\t";
    return x + y + ::x;
}
class Point
{
private:
    double x, y;

public:
    Point() { x = 0, y = 0; }
    Point(double x, double y) : x(x), y(y) {}
    friend double area(Point p1, Point p2);
    ~Point()
    {
        cout << "1" << endl;
    }
};
class Rec
{
private:
    Point p1, p2;

public:
    Rec(Point &p1, Point &p2) : p1(x, y), p2(x, y) {}
    ~Rec()
    {
        cout << "2" << endl;
    }
};
double area(Point p1, Point p2)
{
    double sum = abs(p2.x - p1.x) * abs(p2.y - p1.y);
    return sum;
}
// class Base
// {
// private:
//     char msg[30];
//     int n;

// public:
//     Base(char s[], int m = 0)
//     {
//         n = m;
//         strcpy(msg, s);
//     }
//     void output(void) { cout << n << "\t" << msg << endl; }
// };
// class Derived : public Base
// {
// private:
//     int n;

// public:
//     Derived(int m = 1) : Base("Base", m)
//     {
//         n = m;
//     }
//     void output(void)
//     {
//         cout << n << endl;
//         Base ::output();
//     }
// };
// 下列哪一个说法是错误的?
// A.
// 当用一个对象去初始化同类的另一个对象时,要调用拷贝构造函数
// B.
// 如果某函数有一个参数是类A的对象,那么该函数被调用时,类A的拷贝构造函数将被调用
// C.
// 如果函数的返回值是类A的对象时，则函数返回时，类A的拷贝构造函数将被调用
// D.
// 拷贝构造函数必须自己编写
int sb = 25;
class da
{
private:
    int num;
    const int a = 2; //常成员
public:
    //   int f(int) const; 对常成员函数的正确声明
    static int quiet; //静态成员
    //静态数据成员可以成为成员函数的可选参数，而普通数据成员则不可以。
    //静态数据成员在类内声明，必须在类外定义，因为他相当于全局变量，全部成员都可以调用
    int m;
    int *p = &m;
    da(int n = 0) //缺省参数
    {
        num = n;
        quiet++;
        //  cout << "gouzao" << endl;
    }
    da(const da &d) //默认构造函数，系统会给你自己调用的，但是要知道他的原型。
    {
        num = d.num;
        cout << "copy gouzao" << endl;
    }
    void show()
    {
        cout << num << endl;
        // cout << "ss" << endl;
    }
    void display() const; // 不能修改值了，相当于上了保护
    //~da();//析构函数，创建一个对象后系统都会自动的调用，而new出来的，不会主动消亡。
};
/*函数重载*/
/*函数重载，函数名相同，参数列表和返回值都可以自己设定，调用时系统会根据你的参数列表和返回值自己判断调用*/
int remake(int n)
{
    return n * 2;
}
double remake(double n, double m)
{
    return m * n;
}
int da::quiet = 0;
class person
{
private:
    int m;

public:
    person();
    person(int m) : m(m){};
    person operator+(person &p1)
    {
        person temp;
        temp.m = p1.m + p1.m;
        return temp;
    }
    friend ostream &operator<<(ostream &out, person &p)
    {
        out << p.m << endl;
        return out;
    }
    person operator++()
    {
        m++;
        return *this;
    }
    person operator++(int) //指定返回值
    {
        person tmp(*this);
        m++;
        return tmp;
    }
    bool operator>(person &p)
    {
        return p.m > p.m;
    }
    bool operator!=(person &p)
    {
        return m != p.m;
    }
};
class aa
{
public:
    aa(int a) : a(a) {}
    int a;
    ~aa()
    {
        cout << "first?" << endl;
    }
};
class bb : public aa
{
public:
    bb(int a) : aa(a) {}
    ~bb()
    {
        cout << "second?" << endl;
    }
};
int main()
{
    // int sb;
    // ::sb = 10;
    //作用域运算符，对于全局变量或者函数，优先级最高，赋值或调用函数都直接在局部使用。
    // cout << ::sb;
    // Point p1(1.0, 2.0);
    // Point p2(4.0, 6.0);
    // Rec rec(p1, p2);
    // double sum = area(p1,p2);
    // cout<<sum;

    da d(2);
    //有构造函数创造对象的话，不用构造函数会报错，显示没有与参数列表匹配的构造函数
    //   da d1 = d; //用对象来直接赋值的话会调用拷贝构造函数来为这个新对象赋值。
    // da d2;
    //  d2 = d1;//先创建再赋值的话,并不会直接调用d的构造函数，他是做等号运算符,相当于=重载了

    // *d1.p = 2;
    // cout << d1.m;

    // da *pp; //对象指针
    // pp = &d;
    // pp->show();
    // (*pp).show(); //以上三个等价

    /*对象数组*/
    //  da *s[2];     //对象数组,里面的数表示会生成多少个对象,赋值的话可以用new 来调用构造函数
    // s[1] = new da(2);
    // s[1]->show();
    // da s1[2] = {da(1), da(2)};
    // s1[1].show(), s1[2].show();

    /*const 类 */
    //用const类保护的const类只能调用const函数    const da d1(2);
    // d1.show();报错
    // d1.display(); d1.m 正确

    /*静态成员*/
    // cout<<d.quiet;

    /*函数重载/
     double b = 10.21;
     int bb = 2;
     cout<<remake(bb)<<endl<<remake(b);*/

    /*new 和delete !!!!!*/
    /*new 运算符 new 的左值必须是个指针，本质就是开辟一个新的内存，如果用于类就是创造一个新的对象 将首地址赋给指针变量*/

    // int *ptr;
    // ptr = new int; //给ptr分配一个整形的存储空间，并将首地址给了ptr
    // *ptr = 10;
    // delete ptr;
    // int * pi = new int [10];//开辟数组空间
    // int *pp = new int(99);//()初始化的方法
    // int (*pi)[10] = new int [10][10];//创建多维数组的方法
    // person p1(2);
    // person p2(2);
    // person p3 = p1+p2;
    // cout<<p3;
    /*调用析构是先继承再构造类*/
    // aa a(1);
    //     int x = 10;
    //     int &y = x;
    //     cout<<y<<endl;
    //     int *p = &y;
    //     y++, x++;
    //   cout<<  *p + y;
}
