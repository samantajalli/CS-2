/*
   Filename: ifixpfix.cpp
   This program converts infix notation (fully parenthesized) to postfix notation.  
*/
   
#include "Stack.cpp"   
#include <iostream>
#include <string>
using namespace std;

int main(){
	cout << "This program will convert an infix expression into the\n";
	cout << "equivalent postfix expression.  The numbers involved must\n";
	cout << "be positive integers.  Note that the infix expression\n";
	cout << "must have full parenthesis.  \n";

	Stack<char> ops;			// Use a stack of characters for the operators.
	string expr, pexpr="";	// One string for the original expression and one
// for the postfix equivalent.
	cout << "Enter a infix expression (use ; as delimiter): ";
	getline(cin,  expr, ';');
	cout << "You entered: " << expr << endl;
	int i;
	for( i=0; i<expr.length(); i++){

		if (expr[i]==')')
			pexpr = pexpr + ops.pop() + " ";

		if ((expr[i]=='+')||(expr[i]=='*'))
			ops.push(expr[i]);

		if ((expr[i]>='0' && expr[i]<='9')){
			pexpr = pexpr + expr[i];

		if (!(i<expr.length()-1 && expr[i+1]>='0' && expr[i+1]<='9')){
				pexpr = pexpr + " ";
			}
		}
	}
	cout << "Here is the equivalent postfix expression: " << pexpr << endl;
	cout << endl;
	return 0;
}

