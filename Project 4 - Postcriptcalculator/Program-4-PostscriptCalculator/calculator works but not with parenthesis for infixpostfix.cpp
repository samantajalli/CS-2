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

#include "stack.cpp"	// Note: we need to include the .cpp file since we are using
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

bool IsWellFormed(char, char);

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

	double doubType;
	int    intType;
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
				
				isbal = checkParentheses(iexpr);
				//	First check for balanced parentheses.
			

				if (!isbal){
					cout << "Expression does not have balanced parentheses.\n";
					cout << "Try again.\n";
				}
			}while(!isbal);
			pexpr = infixToPostfix(iexpr);
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
				

//				isbal = checkParentheses(iexpr);
				isbal = checkParentheses(iexpr);
				//	First check for balanced parentheses.
				if (!isbal){
					cout << "Expression does not have balanced parentheses.\n";
					cout << "Try again.\n";
				}
			}while(!isbal);
			pexpr = infixToPostfix(iexpr);
			//	Convert to postfix first.
			cout << "Here is the equivalent postfix expression.\n " << pexpr << endl;
			if (type=='i'||type=='I'){
				int number;
				
				success = evaluatePostfix<int>(pexpr, number);
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
				double floatnum;


				success = evaluatePostfix<double>(pexpr, floatnum);
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
				evaluatePostfix(pexpr, intType);
				/*	FILL-IN #3: See FILL-IN #1.  */
				/*
				 *
				 *
				 *
				 */
			}
			else if(type=='f'||type=='F'){
				evaluatePostfix(pexpr, doubType);
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

bool checkParentheses(const string& text) // add a top function to stack class
{
	bool balanced = true;
	Stack<char> stack;
	int index = 0;
	char openSymbol;

	while (text[index] != '\0' && balanced)
	{
		if (text[index] == '(')
		{
			stack.push(text[index]);
			openSymbol = '(';
		}

		else if (text[index] == ')')
		{
			if (stack.empty())
			{
				balanced = false;
			}
			else
			{
				openSymbol = stack.pop();
				
				balanced = IsWellFormed(text[index], openSymbol);
			}

		}
		
		
		index++;
	}
	if (balanced)
	{
		" is well formed\n";
	}
	return balanced;
}

bool IsWellFormed(char symbol, char openSymbol)
{
	return (openSymbol == '(' && symbol == ')') ;
}

template<class T>
bool evaluatePostfix(const string& a, T& answer)
{
	
	Stack<T> stack;
	int index = -1;
	while (++index < a.length())
	{
		if (a[index] == ' ')
		continue;

		if (a[index] == '+')
		{
			T a = stack.pop();;
			
			T b = stack.pop();
			
			
			stack.push(a + b);
			
		}
		else if (a[index] == '-')
		{
			T temp = stack.pop();
			T sub = stack.pop() - temp;
			stack.push(sub);
		}
		else if (a[index] == '*')
		{
			T mult = stack.pop() * stack.pop();
			stack.push(mult);
			
		}
		else if (a[index] == '/')
		{
			T temp = stack.pop();
			

			T temp1 = stack.pop();
			

			if (temp == 0)
			{ 
				cout <<"Division by zero error";
				return false;
			}
			T div = temp1 / temp;
			stack.push(div); 
		}
		else if (a[index] >= '0' && a[index] <= '999')
		{
			stack.push(0);	
		}
		while (a[index] >= '0' && a[index] <= '999')
			{
				stack.push(10 * stack.pop() + a[index++] - '0');
				
			}
	}
	cout << stack.top();
	return true;
}


string infixToPostfix(const string& a)
{
	Stack<char> ops;
	string pexpr="";

	for(int index = 0; index < a.length(); index++)
	{
		if (a[index] == ' ')
			continue;
		if (a[index] == '(')
			ops.push(a[index]);
		
		if (a[index]==')')
		{
			while (!ops.empty())
			{ if (ops.top() == '(')
				break;
			pexpr = pexpr + ops.pop() + " ";
			}
		}

		if ((a[index]=='+')||(a[index]=='-'))
		{
				if (ops.empty() )
					ops.push(a[index]);
				else
				{
					if (ops.top() == '*' || ops.top() == '/')
					ops.pop();
					else if(ops.top() == '+' || ops.top() == '-')
					{
					pexpr = pexpr + ops.pop();
					 ops.push(a[index]);	
				
					}

				}
					
		}

		if ((a[index] == '*' || a[index] == '/'))
		{
				if (ops.empty())
					ops.push(a[index]);
				else
				{
					if (ops.top() == '+' || ops.top() == '-')
						ops.push(a[index]);
					else if (ops.top() == '*' || ops.top() == '/')
					{
						pexpr = pexpr + ops.pop(); 
						ops.push(a[index]);
					}

				}
		}

		if ((a[index]>='0' && a[index]<='999'))
		{
			pexpr = pexpr + a[index];

			if (!(index<a.length()-1 && a[index+1]>='0' && a[index+1]<='9'))
			{
				pexpr = pexpr + " ";
			}
		}
	
	}
	while (!ops.empty())
	{
		pexpr = pexpr + ops.pop();
	}
	return pexpr;
}
/*	The rest of the function definitions omitted.  */

