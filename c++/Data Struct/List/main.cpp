#include <iostream>
#include "List.hpp"
#include "double_head_list.hpp"
using namespace std;

int main()
{

    // List<int> l;
    // l.Create_list(5);              // 1 1 2 3 5
    // cout << l.get_len() << endl;   // 5
    // l.insert_index(3, 3);          // 1 1 3 2 3 5
    // cout << l.get_len() << endl;   // 6
    // cout << l.find_ele(1) << endl; // 1
    // l.delete_index(6);             // 1 3 2 3 5
    // cout << l.get_len() << endl;   // 5
    // // l.show_list();
    // l.Create_list(3);
    // l.insert_head(1);
    // l.insert_tail(4);
    // // l.show_list();

    // double_list<int> dl;
    // dl.create_list(5);
    // dl.insert(3, 4);
    // dl.showhead();
    // dl.delete_index(2);
    // dl.showhead();
    // dl.showtail();

    List<int> l1;
    l1.Create_list1(5);
    l1.show_list();
    l1.reverse_list();
    l1.show_list();
    l1.reverse_list1();
    l1.show_list();
}