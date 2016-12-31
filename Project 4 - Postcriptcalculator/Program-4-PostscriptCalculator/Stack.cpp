

#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack(){ // Default constructor
	head = NULL;
}

template <class T>
bool Stack<T>::empty() const{ // empty function
	return head==NULL;
}

template<class T>
Stack<T>::~Stack() {  // Destructor
    while (!empty()) pop();
}

template <class T>
Stack<T>::Stack(const Stack<T>& s){ // Copy constructor
	head = NULL;
	copy(s);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs){ // Assignment operator
	if (!(this==&rhs)){
		while (!empty()) pop();
		copy(rhs);
	}
	return *this;
}

/*  The rest of the member function definitions omitted.  */
