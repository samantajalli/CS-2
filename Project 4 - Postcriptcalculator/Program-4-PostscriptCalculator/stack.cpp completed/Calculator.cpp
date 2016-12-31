/*+-------------------------
Programmer: Saman Tajalli
Course: Computer Science 2
Grader: Professor Fry
Assignment: Postfix Calculator
Due Date: November 7 2013
+---------------------------
Program Statement:This program will use stacks
to convert from infix to postfix, the other way
around, evaluate infix and evaluate postfix for
calculations involving +,-,*, and /.

1.)Data Needed
Stack.cpp equipped with push, pop, top functions
with copy constructor, default constructor,
destructor, with every function templated.
String to read the expression before evaluation.

2.)Constants given
None

3.)Calculations
Postfix to Infix, evaluate postfix, evaluate infix,
infix to postfix

4.)Print results
 answers to calculations in step 3

************************Algorithm*************
Step 1: Stack.cpp file
Default constructor, templated, set head to NULL(linked nodes).

Destructor, templated, while stack is not empty(calls empty function),
pop function is called. End while.

Empty function, templated, returns a boolean variable. 
return (head == NULL). 

Copy constructor, templated,
reference variable of stack is sent, set head to NULL,
call copy function and send the reference parameter.

Push function, templated, type void, a variable of type T is sent
by reference as a argument. A node pointer of type T is created, p.
set p to new node of type T, send the parameter and NULL as arguments
to the struct constructor.
set p->next to head. head equals p.

Pop function, of type T, templated. a T variable, topofStack is set
to head->item. Call empty function, if true, error message displays,
exits with exit code of 1.Else, node pointer of type T is made, p, 
p equals head, head equals head arrow next, p is deleted. topofStack
variable is returned.

Top function of type T, templated. If empty() returns true, error
message displays and program ends. Else return head->item.

Assignment operator overloaded function is called, of type 
Stack<T>&, templated.Stack<T> is passed by reference as parameter, rhs.
If this pointer is not equal to rhs, then while Stack is not empty(),
pop() is called.End while. Copy function is called, sending rhs as parameter.
End if. Return star this.

Copy function, of type void, templated, has argument Stack passed by reference,
called s. If s is empty(), set head to NULL. Else, head equals new node<T>,
passes s.head->item, NULL as parameters to new node. A node pointer of 
type <T>, q is made and set to head. A node pointer of type T is made
, p and set to s.head->next. While p pointer is not NULL, q->next is set
to new node<T>(p->item, NULL). p is set to p arrow next. q is set to q->next.
End while. 
This concludes Stack.cpp file.

Next is the Calculator file, with the necessary functions.

First there is the checkParentheses function of type bool. It accepts a 
string, text sent by reference. A bool variable, balanced is made and set to
true. an instance of  Stack class of type char is made, named stack. 
An int variable, index is made and set to 0. A char variable, openSymbol is 
made. While text[index] is not '/0' and balanced is true, if text[index]
equals '(', push it on the stack. set openSymbol to '('. Else if text[index]
equals ')', if stack is empty, set balanced to false. Else set openSymbol to
value returned by pop(pop is called, and returns value). Call function IsWellFormed,
and set balanced to true or false if it is well formed, or false if it is not.
Increment index by 1. return balanced.

IsWellFormed function, of type bool, has char variable symbol and char variable openSymbol as
parameters. it will return true if open symbol equals '(' and symbol equals ')'
and false otherwise.

Evaluate postfix function, of type bool, templated. Accepts a string, a,
passed by reference as parameter and T type, integer or double depending
on if user wants to perform integer or double calculations. A Stack object
of type T, stack is made. set int index to -1. While (++index is less than
a.length(), if a[index] equals an empty character, continue. if a[index] equals '+',
set pop() to variable a of type T. set pop() to variable b of type T. 
Push a plus b onto the stack. Else if b[index] equals '-', set T temp to 
pop(). set T sub to pop() minus temp. Push sub onto the stack. Else if 
a[index] equals '*', set T mult to pop() times pop(). Push mult onto the
stack. Else if a[index] equals '/', set T temp to pop().set T temp1 to pop().
if temp equals 0, sent "division by 0 to monitor, return false. T div is equal
to temp1 divided by temp. Push div onto the stack. Else if a[index]
is greater or equal to '0' and a[index] is less than or equal to '999',
push 10 times pop() plus a[index++] - '0' onto the stack. cout top() to the monitor.
return true.

Infixtopostfix function, of type string, parameter passed string variable a, passed
by reference. Create Stack object ops of type char. Create string pexpr, set as "".
for int index = 0; index < a.length(); index++, if a[index] equals empty character
(' '), continue. if a[index] equals left parenthesis, push it on stack. if 
a[index] == right parenthesis, while stack is not empty, if top of stack equals left
parenthesis, break. pexpr equals pexpr + pop() + " ". End while. if a[index] equals '+'
or a[index] equals '-', while stack is not empty and top() equals '(', pop the stack.
End while. If stack is empty, push the token. Else, if top of stack equals '*' or a '/',
pop the stack. Else if top of stack equals a '+' or a '-', pexpr = pexpr + pop(). Push 
the token. If a[index] equals '*' or a '/', while stack is not empty or top() == '(',
pop the stack. End while. If stack is empty, push token(a[index]). Else if
top() == '*' or top equals '/', pexpr = pexpr + pop(). push a[index]. 
if a[index] is >= 0 and a[index] <= 999, pexpr = pexpr + a[index]. if
!(index < a.length() - 1 and a[index + 1] >= 0 && a[index + 1] <= 999), 
pexpr = pexpr + " ". While stack is not empty, pexpr equals pexpr + pop(). return
pexpr. 
*/
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
			T a = stack.pop();
			
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
			{ 
				if (ops.top() == '(')
				break;
			pexpr = pexpr + ops.pop() + " ";
			}
		}

		if ((a[index]=='+')||(a[index]=='-'))
		{
				while (!ops.empty() && ops.top() == '(') // first char in stack is (, remove it
				{
					ops.pop();
					
				}
				if (ops.empty())
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
		} // End if

		if ((a[index] == '*' || a[index] == '/'))
		{
			while (!ops.empty() && ops.top() == '(') // to remove ( 
			{
				ops.pop();
			}
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
		} // End if

		if ((a[index]>='0' && a[index]<='999'))
		{
			pexpr = pexpr + a[index];

			if (!(index<a.length()-1 && a[index+1]>='0' && a[index+1]<='999'))
			{
				pexpr = pexpr + " ";
			}
		}
	
	} // End for loop
		while (!ops.empty())
		{
			pexpr = pexpr + ops.pop();
		}
	return pexpr;
}
/*	The rest of the function definitions omitted.  */

