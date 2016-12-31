#include <iostream>
#include <string>
#include "phonee.h"

using namespace std;


PhoneBookItem::PhoneBookItem(const string& l, const string& f, const string& ph) { 
	lastname = l; // default constructor for struct
	firstname = f;
	phone = ph;
    next = NULL;
}

PhoneBook::PhoneBook() { // default constructor
	head = NULL;
	num = 0;
}

PhoneBook::PhoneBook( const PhoneBook& pb) { // copy constructor
	head = NULL;
	num = 0;
	Copy(pb);
}

PhoneBook::~PhoneBook() { // destructor calls clear function to empty list
	Clear();
}

PhoneBook& PhoneBook::operator=(const PhoneBook& pb) {
	if (this != &pb) {
		Clear(); // clears out memory on left side
		Copy(pb); // performs the assignment from right side to left
	}
	return *this;
}

bool PhoneBook::IsEmpty() const
{
	if (head == NULL) // list is empty, return true
		return true;
	else              // list is not empty, return false;
		return false;
}

int PhoneBook::Size() const
{
	return num; // return the length of the list
}

bool PhoneBook::Insert(const string& last, const string& first, const string& ph)
{
	bool answer; // is answer true or false

	if (head == NULL) // the current list is empty, so make person the head of the list and make the length of list 1
	{
		head = new PhoneBookItem(last, first, ph);
		num = 1;
		answer = true;
	}

	else if(last < head->lastname)
	{ // the last name given comes before the last name alphabetically, so make the person the head of the list
		PhoneBookItem* p = new PhoneBookItem(last, first, ph);
		p->next = head;
		head = p;
		num++;
		answer = true;
	}

	else if(last == head->lastname && first == head->firstname)
	{
		// duplicate name, insertion fails
		answer = false;
	}
	else {
		// remaining case: search through the list until you find 2 successive 
		//nodes between which the new person should be placed

		//first set p and q to point to first two nodes of the list
		PhoneBookItem* p = head;
		PhoneBookItem* q = head->next;

		//keep moving down while the given last name is larger than q's last name
		while (q != NULL && last > q->lastname)
		{
			p = q;
			q = q->next;
		}

		//check to see we don't have a duplicate record
		//if not, then add new person to the list between p and q
		//this works even if q is NULL

		if (q != NULL && last == q->lastname)
			answer = false;

		else {
			PhoneBookItem* r = new PhoneBookItem(last, first, ph);
			p->next = r;
			r->next = q;
			num++;
			answer = true;
		}
	}
	return answer;
}

bool PhoneBook::Lookup(const string& last, const string& first, string& ph) const
{
	bool moreToSearch, found = false;
	PhoneBookItem* location;
	location = head;
	moreToSearch = (location != NULL);

	while (moreToSearch && !found)
	{
		if (location->lastname < last)
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else if (location->lastname == last && location->firstname == first)
		{
			found = true;
			ph = location->phone;
		}
		else 
			moreToSearch = false;
	}
	return found;

}
ostream& operator<<(ostream& out, const PhoneBook& P)
{
	PhoneBookItem* p = head;
	PhoneBookItem* q = head->next;
	if (P.head == NULL)
		return;
	//else { use a while loop to read the whole loop and pring out the names+phone numbers
		

	//}
	out << P.head->lastname <<", "<<  P.head->firstname <<" "<< P.head->phone;
	return out;
}
void PhoneBook::Clear() // deletes every item from the list
{
	PhoneBookItem* p; // declare a pointer p to a phonebookitem
	while (head != NULL) // while the head is not the last node
	{
		p = head; // assign head pointer to p
		head = head->next; // assign next node to head
		delete p; // delete the previous pointer to head, as the new head is the next node
	}
	num = 0;
}


void PhoneBook::Copy(const PhoneBook& pb) // pb is the other list
{ // make a deep copy
	
	if (num != 0)  // current phone book must be empty to copy list
	{
		cout <<"Error,internal error in private member function Copy\n";
		exit(1);
	}
	num = pb.num; // copies the number of items from pb to num, the current number of items in list
	if (pb.IsEmpty()) 
		head = NULL;
	else
	{
		head = new PhoneBookItem(pb.head->lastname, pb.head->firstname, pb.head->phone);
		PhoneBookItem* q = head; // points to current list, assign head info from other to current(q)
		PhoneBookItem* p = pb.head->next; // points to other list
		while (p!= NULL)
		{
			q ->next = new PhoneBookItem(p-> lastname, p-> firstname, p-> phone);//copies into next node after q
			p = p->next; // assign next node to p
			q = q->next; // assign next node to q
		}
	}

}


