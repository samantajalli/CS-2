//    Quaternion.h

#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
using namespace std;

class Quaternion
{
	friend ostream& operator<< (ostream&, const Quaternion&);
	friend istream& operator>> (istream&, Quaternion&);

public:
	Quaternion();
	Quaternion(double);
	Quaternion(double, double, double, double);

	double length() const;
	Quaternion conjugate() const;

	Quaternion& operator=(const Quaternion&);

	Quaternion& operator+= (const Quaternion&);
	Quaternion& operator-= (const Quaternion&);
	Quaternion& operator*= (const Quaternion&);
	Quaternion& operator/= (const Quaternion&);

private:
	double a;
	double b;
	double c;
	double d;

};
const Quaternion operator+ (const Quaternion&, const Quaternion&);
const Quaternion operator- (const Quaternion&, const Quaternion&);
const Quaternion operator* (const Quaternion&, const Quaternion&);
const Quaternion operator/ (const Quaternion&, const Quaternion&);








#endif