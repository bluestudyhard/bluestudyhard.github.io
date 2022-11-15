#include <iostream>
#include "list_queue.hpp"
using namespace std;
int main()
{
    list_queue<int> k;
    k.push(1);
    k.push(2);
    k.push(100);
    k.push(1);
    k.push(2);
    k.push(100);
    k.show_list();
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
    k.show_list();
}