#include <iostream>
using namespace std;

// vector<int> kk;

// int main()
// {
//     for(int i = 0;i<10;i++)
//     {
//         kk.push_back(i);
//         cout<<kk[i]<<endl;
//         cout<<kk.at(i)<<endl;
//     }
//     kk.back();
//     kk.pop_back();

// }
template <typename Object> //相当于T
class Vector
{
private:
    int thesize;
    int theCapacity;
    Object *objects; // 相当于int *p
    static const int spare_capacity = 16;

public:
    // explicit 单个
    explicit Vector(int intsize = 0) : thesize{intsize},
                                       theCapacity{intsize + spare_capacity}
    {
        objects = new Object[theCapacity];
    }
    // nullptr 值为0，是指针，用来解决和NUll在重载函数中的二义性问题。
    Vector(const &v) : thesize{v.thesize}, theCapacity{v.theCapacity}, objects{nullptr}
    {
        objects = new Object[theCapacity];
        for (int k = 0; k < thesize; ++k)
        {
            objects[k] = v.objects[k];
        }
    }
    Vector &operator=(const Vector &v)
    {
        Vector copy = v;
        swap(*this, copy);
        return *this;
    }
    ~Vector()
    {
        delete[] objects;
    }
    Vector(Vector &v) : thesize(v.thesize), theCapacity(v.theCapacity), objects(v.objects)
    {
        v.objects = nullptr;
        v.thesize = 0;
        v.theCapacity = 0;
    }
    Vector &operator=(Vector &v)
    {
        swap(thesize, v.thesize);
        swap(theCapacity, v.theCapacity);
        std::swap(objects, v.objects) return *this;
    }
    void resize(int newsize)
    {
        if (newsize > theCapacity)
            reserve(newsize * 2);
        thesize = newthesize;
    }
    void reserve(int newCapacity)
    {
        if (newCapacity < thesize)
            return;
        Object *newarry = new Object[newCapacity];
        for (int k = 0; k < thesize; k++)
        {
            newarry[k] = objects[k];
        }
        theCapacity = newCapacity;
        swap(objects, newarry);
        delete[] newarry;
    }
    Object &operator[](int index)
    {
        return objects[index];
    }
    const Object &operator[](int index) const
    {
        return objects[index];
    }
    bool empty()
    {
        return size() == 0;
    }
    int size() const
    {
        return thesize;
    }
    int theCapacity() const
    {
        return theCapacity;
    }
    void push_back(const Object &x)
    {
        if (thesize == theCapacity)
            reverse(2 * theCapacity + 1);
        objects[thesize++] = x;
    }
    void push_back(Object &x)
    {
        if (thesize == theCapacity)
            reverse(2 * theCapacity + 1);
        objects[thesize++] = x;
    }

    void pop_back()
    {
        --thesize;
    }

    const Object &back() const
    {
        return objects[thesize - 1];
    }

    typedef Object *iterator;
    typedef const Object *const_iterator;

    iterator begin()
    {
        return &objects[0];
    }
    const_iterator begin() const
    {
        return &objects[0];
    }
    iterator end()
    {
        return &objects[size()];
    }
    const_iterator end() const
    {
        return &objects[size()];
    }
};
int main()
{
    int a;
}