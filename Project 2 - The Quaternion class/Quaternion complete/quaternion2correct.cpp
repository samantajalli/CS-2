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
	d = ((temp_a * r.d) + (temp_b * r.c) - (temp_c * r.b) + (temp_d * r.a));
	return *this;
}

Quaternion& Quaternion::operator/=(const Quaternion& r)
{
	if (r.a == 0 && r.b == 0 && r.c == 0 && r.d == 0)
	{
		cout <<"Error, the denominator has all zero components, division by zero\n";
		exit(1);
	}
	//double temp_a = a;
	//double temp_b = b;
	//double temp_c = c;
	//double temp_d = d;
	
	Quaternion temp_left = *this;
	temp_left*= r.conjugate();
	a = temp_left.a / (r.length() * r.length());
	b = temp_left.b / (r.length() * r.length());
	c = temp_left.c / (r.length() * r.length());
	d = temp_left.d / (r.length() * r.length());
	
	//a = ((r.a*temp_a) + (r.b*temp_b) + (r.c*temp_c) + (r.d*temp_d)) / (pow(r.a, 2) + pow(r.b, 2) + pow(r.c, 2) + pow(r.d, 2));
	//b = ((r.a*temp_b) - (r.b*temp_a) - (r.c*temp_d) + (r.d*temp_c)) / (pow(r.a, 2) + pow(r.b, 2) + pow(r.c, 2) + pow(r.d, 2));
	//c = ((r.a*temp_c) + (r.b*temp_d) - (r.c*temp_a) - (r.d*temp_b)) / (pow(r.a, 2) + pow(r.b, 2) + pow(r.c, 2) + pow(r.d, 2));
	//d = ((r.a*temp_d) - (r.b*temp_c) + (r.c*temp_b) - (r.d*temp_a)) / (pow(r.a, 2) + pow(r.b, 2) + pow(r.c, 2) + pow(r.d, 2));
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
