#include <iostream>
#include "BSTtree.hpp"
using namespace std;

int main()
{
    BSTtree<int> k;
    int a[10] = {11, 10, 3, 2, 14, 13, 15, 12, 5, 19};
    k.bulid_tree(a, 10);
    k.pre_order();
    k.mid_order();
    k.after_order();
    k.find(3);
    k.find(100);
    cout << k.get_root()->data << endl;
    cout << k.find_min() << endl;
    cout << k.find_max() << endl;
    k.level_order();
    k.find_height();
    k.isBinarySearchTree();
    k.Remove(19);
    k.level_order();
    k.Remove(14);
    k.level_order();
}