#include <iostream>
using namespace std;
template <typename T>
class doublelist
{
private:
    class Node
    {
        T data;
        Node *next; // 后继
        Node *pre;  // 前驱
    };
    Node *head;
    Node *tail;

public:
    doublelist()
    {     
        head = nullptr;
        tail = nullptr;
        head->data = tail->data = 0;
    }
    ~doublelist();
    void create_list()
    {
        Node *head = new Node;
        head->next = tail->pre = nullptr;
        head = pre;

    }
    void show_list();
    void insert(T e,int index);
    Node *find_node(int index);
    void delete_node(int index);
    void reverse();
    bool isempty();
    int list_length();
};