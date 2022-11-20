#include <iostream>
#include "list_queue.hpp"
using namespace std;
int main()
{
    list_queue<int> k;
    cout << "以下是手动插入*6" << endl;
    k.push(1);
    k.push(2);
    k.push(100);
    k.push(1);
    k.push(2);
    k.push(100);
    k.show_list();
    cout << "手动清空*3" << endl;
    k.pop();
    k.pop();
    k.pop();
    // k.pop();
    // k.pop();
    // k.pop();
    k.show_list();
    k.get_front();
    k.get_back();
    k.clear();
    k.isempty();
    k.show_list();
    k.push(2);
    k.show_list();
}