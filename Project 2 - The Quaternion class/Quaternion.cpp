// Quaternion.cpp
	/*
	+---------------------------------+
	+Programmer: Saman Tajalli
	Course: Computer Science 2
	Lab Section: 0112 (Monday and Wednesday)
	Grader: Professor Fry
	Project 2: The Quaternion Class
	Due Date: September 19, 2013
	+---------------------------------+
		Program Statement
	This program will implement an abstract data type for
	the set of numbers called quaternions.
	
	*********Analysis**********
	
	1.) Data needed
	4 variables a, b, c, and d, the 4 components of the
	quaternion, as private member variables of the Quaternion class.
	
	2.)Constants given
	A default constructor will set all members, a,b,c,d(double
	variables), to zero.
	two more default constructors will be used to store one variable
	in the a component, and 4 user defined variables(components), 
	respectively. 
	
	3.)Calculations
	overloading the + operator
	overloading the - operator
	overloading the * operator
	overloading the / operator
	overloading the += operator
	overloading the -= operator
	overloading the *= operator
	overloading the /= operator
	overloading the >> operator
	overloading the << operator
	overloading the = operator
	
	4.)Print results
	The quaternion will be printed to the monitor by overloading
	the output stream(<<) operator and the input stream(>>) operator.
	
	***************Algorithm***************

	Step 1: Input
	Program will begin by showing the user what the quaternions
	are initialized as, by dint of the constructors. Then it will 
	ask user to input a new quaternion. User must do so by overloading
	the input stream(>>) operator & output stream operator to do so,
	inputting the parenthesis and commas between the a,b,c,d components.
	
	Step 2: Process
	The rest of the test driver program checks to see if the program compiles
	correctly, with the question of run-time errors left to the programmer.
	For the rest of this algorithm I will explain the member and non-member
	functions of the Quaternion.cpp file. 
	
	First, there are 3 constructors, all of which
	are member functions. The first quaternion constructor is the
	default constructor which will begin by setting a quaternion object defined
	with no preset variables to 0,0,0,0 respectively(a,b,c,d), that is, the
	zero quaternion. The second constructor has one variable defined, which will
	go into the a component. The third constructor is set up such that the user will
	input his quaternion and they will be set to the a,b,c,d components.
	
	Next, there is a length member function which will set the length of the
	quaternion. It is basically the magnitude of the vector, squaring each component,
	adding them together and taking their square root. The length variable will be returned
	
	Then, there is a conjugate member function which will set the quaternion's components
	to their conjugate by creating an object called instance
	to take on its value. That is, (a,b,c,d) becomes (a,-b,-c,-d). Then
	instance is returned.

	Then there is an overloaded += operator member function. it takes the a value
	on the right hand side(passed by reference)
	, adds it to the a variable on the left, etc for b,
	c, and d. Then the this pointer is returned. 

	Then the -= operator member function is defined. It does the same thing as the +=
	operator, except it subtracts the value on the right hand side of each respective
	component from the left hand side. Then the this pointer is returned.

	Right under that, there is a *- overloaded member function. This one is different
	than the others. an r value will be passed by reference, and declared const
	so its value can't be changed. Then 4 temporary variables will be declared, each
	holding a,b,c,d respectively. Then a will equal the formula for multiplying
	quaternions for the first component. then b will equal formula for multiplying
	quaternions for the 2nd component. then c will equal formula for multiplying
	quaternions for 3rd component. then d will equal formula for multiplying formulas 
	by 4th component. Then the this pointer will be returned.

	Then there is the /= operator. This member function will take an r variable
	by reference and first check to make sure that all four components of the 
	r variable(quaternion) are not zero. If they are zero, an error message will be displayed
	and the program will exit using an exit code of 1. If the program does not encounter this,
	then 4 temporary variables will be created each holding the value of a,b,c,d.
	Then a will equal the formula outlined in the *= operator, but this time divided by the
	square of the quaternion's length. Likewise for b,c, and d.
	The this pointer will be returned, returning a,b,c,d.

	
	Then a + operator nonmember function is underneath. It takes two quaternion
	parameters, one q and one r, each declared as const, passed by reference. 
	a Quaternion object called instance is declared, and initialized with q by assignment.
	Then instance will += r, activating the += operator and sending r, the right hand value,
	to the += member function to resolve. Then instance is returned.

	The -, *, / operators(nonmember functions)
	 react exactly the same as the + operator described above, each
	creating a temporary instance object of type Quaternion, initialized with q, and activating
	with its key compound assignment operator, respectively. Then instance is returned.

	Next the >>(input stream) operator, a member function, is defined.

	5 character variables are created, two for holding paranthesis characters,
	the other 3 for the commas. The in variable is used to start the input stream
	chaining of the 5 char variables with the q Quaternion object passed by reference,
	which will allow for all 4 components to be read into the input stream when typed by
	the user.

	Next the << output stream operator(member function) is defined.
	This will display the parenthesis and commas between the 4 components
	to the monitor as the program runs.

	Finally, an assignment operator overloaded(member function) assigns
	a quaternion to another quaternion, and makes sure it doesn't assign itself
	to itself. If the one being assigned to the other is the same, the this pointer
	is returned. Otherwise, the parameter quat, passed by reference, will assign itself 
	to a,b,c,d respectively.
	*/

#include "Quaternion.h"
#include <iostream>
#include <cmath>
using namespace std;

Quaternion::Quaternion()
{
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}

Quaternion::Quaternion(double x)
{
	a = x;
	b = 0;
	c = 0;
	d = 0;

}

Quaternion::Quaternion(double a1, double b2, double c3, double d4)
{
	a = a1;
	b = b2;
	c = c3;
	d = d4;
}

double Quaternion::length() const
{
	double length;
	length = sqrt(a*a + b*b + c*c + d*d);
	return length;
}

  Quaternion Quaternion::conjugate() const
{
	Quaternion instance(a,-b,-c,-d);
	return instance;
}

Quaternion& Quaternion::operator+=(const Quaternion& r)
{
	this->a += r.a;
	this->b += r.b;
	this->c += r.c;
	this->d += r.d;
	return *this;
}

Quaternion& Quaternion::operator-=(const Quaternion& r)
{
	a -= r.a;
	b -= r.b;
	c -= r.c;
	d -= r.d;
	return *this;
}

Quaternion& Quaternion::operator*=(const Quaternion& r)
{
	double temp_a = a;
	double temp_b = b;
	double temp_c = c;
	double temp_d = d;

	a = ((temp_a * r.a) - (temp_b * r.b) - (temp_c * r.c) - (temp_d * r.d));
	b = ((temp_a * r.b) + (temp_b * r.a) + (temp_c * r.d) - (temp_d * r.c));
	c = ((temp_a * r.c) - (temp_b * r.d) + (temp_c * r.a) + (temp_d * r.b));
	d = ((temp_a * r.d) + (temp_d * r.c) - (temp_c * r.b) + (temp_d * r.a));
	return *this;
}

Quaternion& Quaternion::operator/=(const Quaternion& r)
{
	if (r.a == 0 && r.b == 0 && r.c == 0 && r.d == 0)
	{
		cout <<"Error, the denominator has all zero components, division by zero\n";
		exit(1);
	}
	double temp_a = a;
	double temp_b = b;
	double temp_c = c;
	double temp_d = d;
	
	a = ((r.a*temp_a) + (r.b*temp_b) + (r.c*temp_c) + (r.d*temp_d)) / (pow(r.a, 2) + pow(r.b, 2) + pow(r.c, 2) + pow(r.d, 2));
	b = ((r.a*temp_b) - (r.b*temp_a) - (r.c*temp_d) + (r.d*temp_c)) / (pow(r.a, 2) + pow(r.b, 2) + pow(r.c, 2) + pow(r.d, 2));
	c = ((r.a*temp_c) + (r.b*temp_d) - (r.c*temp_a) - (r.d*temp_b)) / (pow(r.a, 2) + pow(r.b, 2) + pow(r.c, 2) + pow(r.d, 2));
	d = ((r.a*temp_d) - (r.b*temp_c) + (r.c*temp_b) - (r.d*temp_a)) / (pow(r.a, 2) + pow(r.b, 2) + pow(r.c, 2) + pow(r.d, 2));
	return *this;
}

const Quaternion operator+(const Quaternion& q, const Quaternion & r)
{
	Quaternion instance = q;
	instance += r;
	return instance;
}

const Quaternion operator-(const Quaternion& q, const Quaternion& r)
{
	Quaternion instance = q;
	instance -= r;
	return instance;

}

const Quaternion operator*(const Quaternion& q, const Quaternion& r)
{
	Quaternion instance = q;
	instance *= r;
	return instance;
}

const Quaternion operator/(const Quaternion& q, const Quaternion& r)
{
	Quaternion instance = q; 
	instance /= r;
    return instance;											
}

istream& operator>>(istream& in, Quaternion& q)
{
	char right, comma1, comma2, comma3, left;
	in >> left >> q.a >> comma1 >> q.b >> comma2 >> q.c >> comma3 >> q.d >> right;
	return in;

}

ostream& operator<<(ostream& out, const Quaternion& q)
{
	out << "(" << q.a << "," << q.b << "," << q.c << "," << q.d <<")";
	return out;
}

Quaternion& Quaternion::operator=(const Quaternion& quat) 
{
	if (this == &quat)
		return *this;
	a = quat.a;
	b = quat.b;
	c = quat.c;
	d = quat.d;
	return *this;

}
