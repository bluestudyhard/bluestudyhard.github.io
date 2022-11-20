#include <iostream>
#include "BSTtree.hpp"
using namespace std;

int main()
{
    BSTtree<int> k;
    int a[8] = {11, 10, 3, 2, 14, 5, 19, 21};
    k.bulid_tree(a, 8);
    k.pre_order();
    k.mid_order();
    k.after_order();
    k.find(3);
}