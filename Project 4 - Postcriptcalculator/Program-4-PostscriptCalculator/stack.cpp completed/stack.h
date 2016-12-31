
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template<class T>
struct node {
    T item;
    node<T>* next;
    node(const T& it, node<T>* p){
    // Inline function definition.  
        item = it; 
        next = p;
   }
};

template<class T>
class Stack {
public:
    Stack();
    ~Stack();
    Stack(const Stack<T>& s);
    Stack<T>& operator=(const Stack<T>& rhs);
    bool empty() const;
    void push(const T&);
    T pop();
	T top();
private:
    node<T>* head;
    void copy(const Stack<T>& s);
};


#endif // STACK_H