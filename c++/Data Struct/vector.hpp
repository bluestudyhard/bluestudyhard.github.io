
#include <iostream>
using namespace std;
const int maxCapacity = 5;
template <typename T>
class Vector
{
private:
    int thesize;
    int thecapacity;
    T *v;

public:
    Vector(int thesize = 0) : thesize(thesize), thecapacity(maxCapacity + thesize)
    {
        v = new T[maxCapacity]; // 初始化一片空间
    }
    Vector(const Vector &L) : thesize(0), thecapacity(0), v(nullptr)
    {
        *this = L; // this 指向当前对象，那么就是说我创建一个拷贝构造函数会给他赋值默认构造函数的值。其实就是创了一个空的表。
    }
    void create_array(T *t, int len)
    {
        for (int i = 1; i <= len; i++)
        {
            v[i] = t[i];
        }
        this->thesize = len;
    }
    void resize(int newsize) //用于判断我们想要存进去的数据，会不会超过原本我们开辟的空间
    {
        if (newsize < thesize)
            return;
        else if (newsize > thecapacity) //如果超过了，就调用reserve函数，给空间扩容。
        {
            reserve(newsize * 2 + 1); //使原本的空间扩容2倍并，+1是表示在没有定义初始空间时，0size时，保证有1个元素的空间。
        }
        thesize = newsize; //扩完容以后就让这个超过的长度变成现在的数组长度。
    }
    void reserve(int newcapacity)
    {
        if (newcapacity < thecapacity)
            return;
        T *temp = v;            //先用一个数组来暂时存储我们原本的数据。
        v = new T[newcapacity]; //扩容

        for (int i = 1; i <= thesize; i++)
        {
            v[i] = temp[i]; //再把数据存回新的空间
        }
        delete temp; //删除临时交换数组。
    }
    bool insert_e(int index, T e)
    {
        if (index < 0 || index > thecapacity)
        {
            cout << "insert false" << endl;
        }
        for (int i = thesize + 1; i >= index; i--)
        {
            v[i] = v[i - 1]; //就是每个元素往后移动1位腾出空间，然后再把数据插入指定的位置就可以了。
            //比如 1 2 3 4 在2的位置插入1那么先变成 1 2 2 3 4 再在2的位置插入1 变成 1 1 2 3 4
        }
        v[index] = e;
        ++thesize; //插入以后长度+1;
        return 1;
    }
    bool remove_e(int index, T e)
    {
        if (index < 0 || index > thecapacity)
        {
            cout << "remove false" << endl;
            return 0;
        }
        for (int i = index; i <= thesize; i++)
        {
            v[i] = v[i + 1]; //和插入同理，就是往前挤掉元素就可以
        }
        --thesize;
        return 1;
    }
    int find_e(T e)
    {
        for (int i = 1; i <= thesize; i++)
            if (v[i] == e)
                return i;
        return 0;
    }
    void push_back(T e)
    {
        if (thesize == thecapacity)
        {
            reserve(thecapacity * 2 + 1);
        }
        v[++thesize] = e; // thesize 默认为0，所以要先自增才插入
    }
    void pop_back()
    {
        --thesize;
    }
    int Thesize()
    {
        return thesize;
    }
    void display()
    {
        for (int i = 1; i <= thesize; i++)
            cout << v[i] << " ";
        cout << endl;
    }
};
int main()
{
    Vector<int> kk;
    for (int i = 1; i <= 10; i++)
        kk.push_back(i);
    kk.display();
    kk.insert_e(2, 2);
    kk.display();
    kk.remove_e(2, 2);
    kk.display();
    cout << kk.find_e(2);

    Vector<int> k;
    int array[6] = {0}, len = 0;
    for (int i = 1; i <= 5; i++)
    {
        array[i] = i;
        len++;
    }
    k.create_array(array, len);
    k.display();
}
