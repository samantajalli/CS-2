// QuaternionTest.cpp - Program # 2
// Do NOT change this code - use this file as is
#include <iostream>
#include "Quaternion.h"

int main()
{
	Quaternion q1, q2(1, 2, 3, -4), q3(2, 4, 6, 8);
	cout << "Initially, the quaternions are\n"
		 << " q1 = " << q1 << "\n"
		 << " q2 = " << q2 << "\n"
	     << " q3 = " << q3 << "\n\n";

	cout << "Enter a new quaternion for q1 "
		<< "in the form (a, b, c, d): \n";
	cin >> q1;
	cout << "Enter a new quaternion for q2:\n";
	cin >> q2;
	cout << "\nNow the quaternions are\n"
		 << " q1 = " << q1 << "\n"
		 << " q2 = " << q2 << "\n\n";

	cout << "Arithmetic: \n"
		 << " q1 + q2 = " << (q1 + q2) << "\n"
	     << " q1 - q2 = " << (q1 - q2) << "\n"
         << " q1 * q2 = " << (q1 * q2) << "\n"
         << " q2 * q1 = " << (q2 * q1) << "\n\n";

	cout << "The length of q1 is " << q1.length() << "\n";
	cout << "The conjugate of q2 is " << q2.conjugate() << "\n";

	cout << "\nNow the values of the quaternions are\n"
		 << " q1 = " << q1 << "\n"
		 << " q2 = " << q2 << "\n\n";
	 
	cout << " Now for division: \n"
		 << " q1 / q2 = " << q1/q2 << "\n"
		 << " q2 / q1 = " << q2/q1 << "\n\n";

   // To test cascading using +=
	q1 += q2 += q3;
	cout << " After cascading +=: " << "\n";
	cout << "The value of q1 is now " << q1 << "\n";
    cout << "The value of q2 is now " << q2 << "\n";
    cout << "The value of q3 is now " << q3 << "\n\n";

	// To test = 
    q1 = q2 = q3;
	cout << " After cascading =: " << "\n";
	cout << "The value of q1 is now " << q1 << "\n";
    cout << "The value of q2 is now " << q2 << "\n";
    cout << "The value of q3 is now " << q3 << "\n\n";

    // To test *=
    q1 *= q2 *= q3;
	cout << " After cascading *=: " << "\n";
	cout << "The value of q1 is now " << q1 << "\n";
    cout << "The value of q2 is now " << q2 << "\n";
    cout << "The value of q3 is now " << q3 << "\n\n";

		// To test change of associativity
    (q1 = q2) += q3;
	cout << " After cascading change of associativity: " << "\n";
	cout << "The value of q1 is now " << q1 << "\n";
    cout << "The value of q2 is now " << q2 << "\n";
    cout << "The value of q3 is now " << q3 << "\n\n";

	    // To test automatic type conversion/anonymous types
	Quaternion q4(1,2,3,4), q5(10,20,30,40), q6, q7;
	q6=5+q4;
	q7=q5+5;
	cout << "The value of q6 is " << q6 << "\n";
	cout << "The value of q7 is " << q7 << "\n";
	cout << "This creates an anonymous type:" << (q6+q7) << "\n";
	cout << "This creates an anonymous type that calls a function:" << (q6+q7).conjugate() << "\n";

	return 0;
}

	     
