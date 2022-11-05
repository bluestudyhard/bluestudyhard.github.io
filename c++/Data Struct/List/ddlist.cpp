#include <iostream>
#include "double_circle_list.hpp"
using namespace std;

int main()
{
    double_circle_list<int> l;
    l.create_list(5);     // 创建链表
    l.show_list();        // 打印链表
    l.insert_ele(100, 2); // 在2的位置插入100
    l.show_list();
    l.push_tail(11); // 尾插
    l.show_list();
    l.delete_ele(1); // 删除位置1的节点
    l.show_list();
    l.find_Node(4);    // 找第四个节点
    l.find_ele(10000); // 查找元素10000
    l.find_ele(2);
    l.replace_ele(1000, 4); // 讲第4个节点元素替换为1000
    l.show_list();
    l.show_reverse(); // 翻转输出
    l.get_len();      // 获取当前链表长度
    l.clear();        //情况链表
    l.isempty();      // 判断为空
}