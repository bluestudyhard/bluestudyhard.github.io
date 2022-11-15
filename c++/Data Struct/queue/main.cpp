#include <iostream>
#include "deque.hpp"
using namespace std;
int main()
{
    // int a[5] = {1, 2, 4, 5, 6};
    // dequeue<int> k(a, 5);
    // k.show_queue();
    // k.push(100);
    // k.push(99);
    // k.show_queue();
    // k.pop();
    // k.show_queue();
    // k.get_front();
    // k.get_rear();
    // k.pop();
    // k.show_queue();
    // k.get_front();
    // k.isempty();
    // 超出原本队列的情况
    int a1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    dequeue<int> k1(a1, 16);
    k1.show_queue();
    k1.push(17);
    k1.push(18);
    k1.show_queue();
    k1.clear();
    k1.show_queue();
    k1.push(100);
    k1.show_queue();
}