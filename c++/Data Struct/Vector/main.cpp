#include <iostream>
#include "vector.hpp"
using namespace std;
int main()
{
    Vector<int> kk;
    cout << "用push_back()生成顺序表" << endl;
    for (int i = 1; i <= 10; i++)
        kk.push_back(i);
    cout << "打印顺序表" << endl;
    kk.display();
    cout << "在2的位置插入2" << endl;
    kk.insert_e(2, 2);
    kk.display();
    cout << "在2的位置移除2" << endl;
    kk.remove_e(2, 2);
    kk.display();
    cout << "查找下标为2的元素" << endl;
    cout << kk.find_e(2) << endl;
    cout << "自定义数组创建顺序表" << endl;
    Vector<int> k;
    int array[6] = {0}, len = 0;
    for (int i = 1; i <= 5; i++)
    {
        array[i] = i;
        len++;
    }
    k.create_array(array, len);
    cout << "通过[]直接访问元素" << endl;
    cout << k[1] << endl;
    k.display();
}