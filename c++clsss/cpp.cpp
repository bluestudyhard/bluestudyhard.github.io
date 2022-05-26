#include <bits/stdc++.h>
using namespace std;
//请编写你的代砄1�7
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
    f1->show_name();//不能通过指针来访问被子类覆盖的函敄1�7
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
/*
class Time
{
private:
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0);
    Time operator+(Time &);
    void DispTime();
};
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
Time Time::operator+(Time &t)
{
    int s = (t.seconds + this->seconds) % 60;
    int m = ((t.seconds + this->seconds) / 60 + t.minutes + this->minutes) % 60;
    int h = ((t.seconds + this->seconds) / 60 + t.minutes + this->minutes) / 60 + t.hours + this->hours;
    t.hours = h;
    t.minutes = m;
    t.seconds = s;
    return t;
}
void Time::DispTime()
{
    cout << this->hours << "h:" << this->minutes << "m:" << this->seconds << "s";
}
int main()
{
    Time tm1(8, 75, 50), tm2(0, 6, 16), tm3;
    tm3 = tm1 + tm2;
    tm3.DispTime();
    return 0;
}
*/
/*
class Date
{
protected:
    int year;
    int month;
    int day;
public:
    Date(int year, int month, int day) : year(year), month(month), day(day){};

public:
    int totalData()
    {
        return year * 1000 + month * 100 + day;
    }
    void showdate() { cout << " " << year << "/" << month << "/" << day; }
};
class Time
{
protected:
    int hour;
    int minute;
    int second;
public:
    Time(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

public:
    int totaltime()
    {
        return hour * 1000 + minute * 100 + second;
    }
    void showtime()
    {
        cout << " " << hour << ":" << minute << ":" << second;
    }
};
class Schedule : public Date, Time
{
protected:
    int id;

public:
    Schedule(int id, int year, int month, int day, int hour, int minute, int second)
        : Date(year, month, day),
          Time(hour, minute, second),
          id(id) {}

public:
    bool operator<(Schedule s2)
    {
        if (this->totalData() != s2.totalData())
        {
            return totalData() < s2.totalData();
        }
        else
        {
            return totaltime() < s2.totaltime();
        }
    }
    void show()
    {
        cout << "No." << id << ":";
        Date::showdate();
        Time::showtime();
    }
};
int main()
{
    int n, a, b, c, d, e, f;
    Schedule s2(0, 9999, 9999, 9999, 999, 999, 99);
    while (cin >> n, n != 0)
    {
        scanf("%d/%d/%d", &a, &b, &c);
        scanf("%d:%d:%d", &d, &e, &f);
        Schedule s1(n, a, b, c, d, e, f);
        if (s1 < s2)
        {
            s2 = s1;
        }
    }
    cout << "The urgent schedule is ";
    s2.show();
}
*/
/*
class person
{
public:
    int a, b;
    person() : a(10), b(20) {}
    person operator+(person &p)
    {
        person temp;
        temp.a = p.a + p.a;
        temp.b = p.b + p.b;
        return temp;
    }
    // person operator>>()
    // person operator <<()
    // person operator>()
    person &operator++()
    {
        a++;
        b++;
        return *this;
    }
    person operator++(int)
    {
        person tmp(*this); // temp = *this;
        a++;
        b++;
        return tmp;
        // return ++*this;
    }
    friend ostream &operator<<(ostream &out, person &p1)
    {
    }
    // person operator!=()
};
int main()
{
    person a;
    person b;
    person c = a + b; //实现扢�有成员函数的相加
    person *p;
    a++;
    cout << a.a << " " << a.b << endl;
    cout << c.a << " " << c.b << endl;
}
*/
/*
class MyTime
{
    int h;
    int m;
    int s;

public:
    MyTime()
    {
        h = 0, m = 0, s = 0;
    };
    MyTime(int a, int b, int c) : h(a), m(b), s(c) {}
    MyTime operator++()
    {
        this->h++;
        this->m++;
        this->s++;
        if (this->h > 24)
            h = 0;
        else if (this->m >= 60)
            m = 0;
        else
            s = 0;
    }
    friend istream &operator>>(istream &in, MyTime &t)
    {
        in >> t.h >> t.m >> t.s;
        return in;
    }
    friend ostream &operator<<(ostream &out, MyTime &t)
    {
        out << t.h << ":" << t.m << ":" << t.s;
        return out;
    }
};

int main()
{
    MyTime t1, t2(23, 59, 59), t3;
    cin >> t3;
    ++t1;
    cout << t1 << endl;
    ++t2;
    cout << t2 << endl;
    ++t3;
    cout << t3 << endl;
    return 0;
}
*/
/*
class shape
{
public:
    virtual float area() const = 0;
};
class circle : public shape
{
public:
    float r;
    circle(float r) : r(r) {}
    virtual float area(float r)const
    {
        return r * r * 3.14159f;
    }
};
class square : public shape
{
public:
    float a;
    square(float a) : a(a) {}
    virtual float area(float a)const
    {
        return a * a;
    }
};
class ret : public shape
{
public:
    float b, c;
    ret(float b, float c) : b(b), c(c) {}
    virtual float area(float b, float c)const
    {
        return b * c;
    }
};
class ts : public shape
{
public:
    float d, e, f;
    ts(float d, float e, float f) : d(d), e(e), f(f) {}
    virtual float area(float d, float e, float f)const
    {
        return (d + e) * f * 0.5;
    }
};
class tri : public shape
{
public:
    float g, h;
    tri(float g, float h) : g(g), h(h) {}
    virtual float area(float g, float h)const
    {
        return g * h * 0.5;
    }
};

int main()
{
    float a, b, c, d, e, f, g, h, r;
    cin >> r >> a >> b >> c >> d >> e >> f >> g >> h;

    circle c1(r);
    square s(a);
    ret r1(b, c);
    ts t(d, e, f);
    tri tr(g, h);
    shape *pt[5] = {&c1, &s, &r1, &t, &tr};
    double areas = 0.0;
    for (int i = 0; i < 5; i++)
    {
        areas = areas + pt[i]->area();
    }
    cout << areas << endl;
    return 0;
}*/
/*
class shape
{
public:
    virtual void getarea() = 0; //纯虚构函敄1�7
};
class circle : public shape
{
public:
    double r;
    circle(double r) : r(r){};
    void getarea()
    {
        cout << r * r * 3.1415;
    }
};
int main()
{
    circle c1(5.5);
    c1.getarea();
}

*/

template <typename T>
void swap(T &a,T&b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;

}
int main()
{   int a = 1,b = 2;

   void swap<int>(a,b);
}