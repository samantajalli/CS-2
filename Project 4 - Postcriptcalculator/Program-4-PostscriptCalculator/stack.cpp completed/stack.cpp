#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

template <class T>
Stack<T>::Stack() // default constructor
{
	 head = NULL;
}

template <class T>
Stack<T>::~Stack() // destructor
{
	while (!empty())
		pop();
}

template <class T>
bool Stack<T>::empty() const // empty function
{
	return head == NULL;
}

template <class T>
Stack<T>::Stack(const Stack<T>& s){ // Copy constructor
	head = NULL;
	copy(s);
}

template <class T>
void Stack<T>::push(const T& x)
{
	node<T>* p;
	p = new node<T>(x, NULL);
	
	p->next = head;
	head = p;
}

template <class T>
T Stack<T>::pop()
{
	T topofStack = head->item;
	if (empty())
	{
		cout << "Stack Empty error";
		exit(1);
	}
	else
	{
		node<T>* p;
		p = head;
		head = head->next;
		delete p;
	}

	return topofStack;

	
}

template <class T>
T Stack<T>::top()
{
	if (empty())
	{
		cout << "Stack empty!";
		exit(1);
	}
	else 
		return head->item;
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs){ // Assignment operator
	if (!(this==&rhs))
	{
		while (!empty()) 
		{
			pop();
		}
		copy(rhs);
	}
	return *this;
}

template <class T>
void Stack<T>::copy(const Stack<T>& s)
{ // make a deep copy
	if (s.empty()) // stack must be empty 
		head = NULL;
	
	else 
	{
		head = new node<T>(s.head->item, NULL);
		node<T>* q = head; // points to current list, assign head info from other to current(q)
		node<T>* p = s.head->next; // points to other list

		while (p!= NULL)
		{
			q->next = new node<T>(p->item, NULL); //copies items into node after q
			p = p->next; // assign next node to p
			q = q->next; // assign next node to q
		}

	}

}