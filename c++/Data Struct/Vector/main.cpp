#include <iostream>
#include "vector.hpp"
using namespace std;
int main()
{
    Vector<int> kk;
    cout << "��push_back()����˳���" << endl;
    for (int i = 1; i <= 10; i++)
        kk.push_back(i);
    cout << "��ӡ˳���" << endl;
    kk.display();
    cout << "��2��λ�ò���2" << endl;
    kk.insert_e(2, 2);
    kk.display();
    cout << "��2��λ���Ƴ�2" << endl;
    kk.remove_e(2, 2);
    kk.display();
    cout << "�����±�Ϊ2��Ԫ��" << endl;
    cout << kk.find_e(2) << endl;
    cout << "�Զ������鴴��˳���" << endl;
    Vector<int> k;
    int array[6] = {0}, len = 0;
    for (int i = 1; i <= 5; i++)
    {
        array[i] = i;
        len++;
    }
    k.create_array(array, len);
    cout << "ͨ��[]ֱ�ӷ���Ԫ��" << endl;
    cout << k[1] << endl;
    k.display();
}