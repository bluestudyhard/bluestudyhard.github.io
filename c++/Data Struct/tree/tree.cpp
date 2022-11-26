#include <iostream>
#include <vector>
#include "tree.hpp"
using namespace std;

int main()
{
    vector<int> pre = {11, 10, 3, 2, 5, 14, 13, 12, 15, 19};
    vector<int> in = {2, 3, 5, 10, 11, 12, 13, 14, 15, 19};
    vector<int> post = {2, 5, 3, 10, 12, 13, 19, 15, 14, 11};
    binarytree<int> k;
    /*前中序创建二叉树*/
     k.pre_increate(pre, in);k.midpostcreate(in, post);
    /*中后序创建二叉树*/
    // vector<string> in1 = {"C", "D", "B", "A", "E"};
    // vector<string> post1 = {"D", "C", "B", "E", "A"};
    // binarytree<string>kk;
    // kk.midpostcreate(in1,post1);
    // kk.preorder();
    // kk.in_order();
    // kk.post_order();
    //cout << k.get_root() << endl;
    /*遍历s'*/
    k.preorder();
    k.inorder();
     k.postorder();
    // k.level_order();
    // k.pre_order();
    // k.in_order();
    // k.post_order();
    // /*各种查找数据*/
    // k.find_node(3);
    // k.find_node(100);
    // k.find_node(12);
    // k.find_parent(3);
    // k.find_parent(10);
    // k.find_parent(12);
    // k.find_parent(11);
    // /*销毁*/
    // // k.Destroy();
    // /*插入操作*/
    // k.Insert(14, 18, true);
    // k.Insert(19, 100, true);
    // k.preorder();
    // k.get_height();
}