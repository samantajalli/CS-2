/*
   This program simply evaluates a postfix expression of integers.  Notice the use of a
	stack of integers to store the value.  
*/

#include "Stack.h" 
#include <iostream>
#include <string>
using namespace std;


int main(){
	cout << "This program will evaluate a postfix expression of integers.\n";
	Stack<int> save;	// Use a stack of ints to save the result.
	string expr;		// For the postfix expression.
	cout << "Enter a postfix expression (use ; as delimiter): ";
	getline(cin,  expr, ';');
	for(int i=0; i < expr.size(); i++) {	

		if (expr[i] == '+')
			save.push(save.pop() + save.pop());

		if (expr[i] == '-')
			// save.push(save.pop() - save.pop());   order of subtraction is wrong

		if (expr[i] == '/')
			// save.push(save.pop() / save.pop());    order of division is wrong
	
		if (expr[i] == '*')
			save.push(save.pop() * save.pop());
		
		if ((expr[i] >='0') && (expr[i] <='9'))
			save.push(0);
		
		while ((expr[i] >= '0') && (expr[i] <= '9')){
			save.push(10*save.pop() + expr[i++] -'0');
		}
	
	}
	cout << "The answer is : " << save.pop() << endl;

	return 0;
}



