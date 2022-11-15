#include <iostream>
#include "stack.hpp"
using namespace std;
int main()
{
    Stack<int> s(5);
    s.push(10);
    s.push(1);
    s.push(12);
    s.show_stack();
    s.pop();
    s.show_stack();
    s.top();
    s.show_stack();
    // 超出容量的情况
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(5);
    s.push(10);
    s.show_stack();
    s.isempty();
    
}