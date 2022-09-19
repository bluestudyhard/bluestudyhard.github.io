#include<iostream>
using namespace std;
typedef long long ll;

template<typename T>
class Node{
    public:
    T_value;
    Node* _next;

    Node() = default;
    Node(T_value,Node_*next):_value(value),_next(next){};
};


template<typename T>
class Singlelink{
    public:
    typedef Node<T>* pointer;
    Singlelink();
    ~Singlelink();
    
    
    int size();
    bool isEmpty();
    pointer insert(int index,T t);
    Node<T>* insert_head(T t);
    
};

