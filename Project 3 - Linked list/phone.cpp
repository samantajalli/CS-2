#include <iostream>
#include <string>
#include "phone.h"

using namespace std;


PhoneBookItem::PhoneBookItem(const string& l, const string& f, const string& ph) {
	lastname = l;
	firstname = f;
	phone = ph;
    next = NULL;
}

PhoneBook::PhoneBook() {
	head = NULL;
	num = 0;
}

PhoneBook::PhoneBook( const PhoneBook& pb) {
	head = NULL;
	num = 0;
	Copy(pb);
}

PhoneBook::~PhoneBook() {
	Clear();
}

PhoneBook& PhoneBook::operator=(const PhoneBook& pb) {
	if (this != &pb) {
		Clear();
		Copy(pb);
	}
	return *this;
}








