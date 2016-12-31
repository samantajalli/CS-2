/* Your header comment goes here.*/

/*	Filename: PFCalculator.cpp
	A Postfix calculator with the following operations:
		a) Convert infix to postfix
		b) Convert postfix to infix
		c) Evaluate an infix expression
		d) Evaluate a postfix expression
	The program checks for balanced parentheses, but then assumes all other console
	input is valid.  (See assignment for what valid means.)

	You can compile this program anytime after you finish the Stack.cpp member 
	function definitions.  Of course, it won't work correctly until you finish the
	assignment!  You need to supply the function definitions.  You also need to do
	the four FILL-IN's.  See below.

    Tip: After you finish writing a function remove the comments where the function 
	is called and try it out!
*/

#include "Stack.cpp"	// Note: we need to include the .cpp file since we are using
						// templates.
#include <iostream>
#include <string>
using namespace std;

void Help();
//	Help menu.  Self-explanatory.

string postfixToInfix(const string& a);
//	Precondition: String a is a valid postfix expression.
//	Postcondition: Function returns an equivalent infix expression.
//	This function uses a stack of strings.

string infixToPostfix(const string& a);
//	Precondition: String a is a valid infix expression.
//	Postcondition: Function returns an equivalent postfix expression.
//	This function uses a stack of chars.

bool checkParentheses(const string& text);
//	Precondition: String text is an infix expression.
//	Postcondition: Function returns true if the parentheses are balanced and no 
//				  unmatched ')' are encountered.
//	This function is the only text error checking in this program.

template <class T>
bool evaluatePostfix(const string& a, T& answer);
//	Precondition: String a is a valid postfix expression and answer is of the 
//				  type double or int.  
//	Postcondition: If there is no division by 0 or square root of a negative 
//				   number, answer contains the evaluated quantity and the function
//				   returns true.  Otherwise the function returns false.

int main(){
	cout << "Welcome to the CS2 Postfix Calculator!\n";
	char type, choice;	// type is for float or int calculations.
						// choice is for menu choice.
	bool success;		// success is for return value of evaluatePostfix.
	bool isbal=true;	// isbal is for return value of checkParentheses.

	string pexpr="", iexpr="";	// pexpr is to hold the postfix expression.
								// iexpr is to hold the infix expression.

	Help();

	do{
		cout << "\nWhat would you like to do?\n";
		cout << ">> ";
		cin >> choice;

		switch(choice){
		case 'A':
		case 'a':
		//	Converting from infix to postfix (only)

			do{
				cout << "Enter an infix expression to be converted.\n";
				cout << "(Use ; as delimiter.)\n";
				cout << ">> >> ";
				getline(cin,  iexpr, ';');
			//	Chomp();

//				isbal = checkParentheses(iexpr);
				//	First check for balanced parentheses.
				if (!isbal){
					cout << "Expression does not have balanced parentheses.\n";
					cout << "Try again.\n";
				}
			}while(!isbal);
//			pexpr = infixToPostfix(iexpr);
			cout << "Here is your expression in postfix notation.\n " 
				<< pexpr << endl;
			break;
		case 'B':
		case 'b':
		//	Converting from postfix to infix (only)
			cout << "Enter a postfix expression to be converted.\n";
			cout << "(Use ; as delimiter.)\n";
			cout << ">> >> ";
			getline(cin,  pexpr, ';');
		//	Chomp();

//			iexpr = postfixToInfix(pexpr);
			cout << "Here is your expression in infix notation.\n " 
				<< iexpr << endl;
			break;
		case 'C':
		case 'c':
		//	Evaluating infix by converting to postfix first.
			do{
				cout << "Select (f)loating point or (i)nteger calculation: ";
				cin >> type;
				// Loop specifies double or int calculation.  See below.
				if((type!='F' && type!='f') && (type!='I' && type!='i')){
					cout << "Not a valid type.\n";
					cout << "Try again.\n";
				}
			}while((type!='F' && type!='f') && (type!='I' && type!='i'));

			do{
				cout << "Enter an infix expression using full parentheses.\n";
				cout << "(Use ; as delimiter.)\n";
				cout << ">> >> ";
				getline(cin,  iexpr, ';');
		//		Chomp();

//				isbal = checkParentheses(iexpr);
				//	First check for balanced parentheses.
				if (!isbal){
					cout << "Expression does not have balanced parentheses.\n";
					cout << "Try again.\n";
				}
			}while(!isbal);
//			pexpr = infixToPostfix(iexpr);
			//	Convert to postfix first.
			cout << "Here is the equivalent postfix expression.\n " << pexpr << endl;
			if (type=='i'||type=='I'){
				/*	FILL-IN #1:
					This is where you call the evalutePostfix function.
					You should first declare an int variable and use that
					as the reference variable (second argument) in the 
					function call.  This tells the compiler to make a version
					of the templated function with T=int.

					Also note that you should only print the result if the
					function call was successful.
				 *
				 *
				 */
			}
			else if(type=='f'||type=='F'){
				/*	FILL-IN #2:
					Simiar to FILL-IN #1.  But now declare a variable 
					of type double and use it for the reference variable.
					What does the compiler do with the templated function now?
				 *
				 *
				 */
			}
			break;
		case 'D':
		case 'd':
		//	Evaluate a postfix expression directly.
			do{
				cout << "Select (f)loating point or (i)nteger calculation: ";
				cin >> type;
				// Loop specifies double or int calculation.  See below.
				if((type!='F' && type!='f') && (type!='i'&& type!='i')){
					cout << "Not a valid type.\n"; 
					cout << "Try again.\n";
				}
			}while((type!='F' && type!='f') && (type!='i'&& type!='i'));

			cout << "Enter a postfix expression.\n";
			cout << "(Use ; as delimiter.)\n";
			cout << ">> >> ";
			getline(cin, pexpr, ';');
			
			if (type=='i'||type=='I'){
				/*	FILL-IN #3: See FILL-IN #1.  */
				/*
				 *
				 *
				 *
				 */
			}
			else if(type=='f'||type=='F'){
				/*	FILL-IN #4: See FILL-IN #2. */
				/*
				 *
				 *
				 *
				 */
			}

			break;
		case 'H':
		case 'h':
			Help();
			break;
		case 'Q':
		case 'q':
			cout << "\nExiting command portion.\n";
			break;
		default:
			cout << "Invalid command.\n";
		}
		pexpr = "";	//	Reset expression strings.
		iexpr = "";
	}while(choice!='q' && choice !='Q');

	// Test copy constructor, assignment operator, destuctor.
	Stack<int> test;
	test.push(1);
	{
		Stack<int> btest(test), ctest;
		// Test for copy construcor.
		ctest = btest;
		// Test for assignment operator.
	}
	// Test for destructor.

	cout << "Copy constructor, assignment operator, destructor tested.\n";
	
	return 0;
}


void Help(){
	cout << "\nHere are the available options.\n";
	cout << "(a) convert infix to postfix\n";
	cout << "(b) convert postfix to infix\n";
	cout << "(c) evaluate an infix expression\n";
	cout << "(d) evaluate a postfix expression\n";
	cout << "(h) print this menu\n";
	cout << "(q) quit\n";
	return;
}

/*	The rest of the function definitions omitted.  */

