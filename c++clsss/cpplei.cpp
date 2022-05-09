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
class student
{
private:
    int num;

public:
    static double total;
    int getvalue(int n)
    {   total+=n;
        return n;
    }
} ;
double student ::total = 0;
int main()
{

    student s;
    student a[5];
    int n;
    for(int i = 0;i<5;i++)
    {   cin>>n;
        a[i].getvalue(n);
    }
    cout<<s.total<<" "<<s.total/5.;
}