/*
	+------------------------+
	Programmer: Saman Tajalli
	Course: Computer Science 2
	Grader: Professor Fry
	Assignment 3
	Due Date: October 10, 2013
	+------------------------+
	Program Statement
	This program will create a linked list of names and their 
	corresponding phone numbers(a phonebook)
	*****Analysis*****
	1.)Data needed
	A struct variable called PhoneBookItem
	a lastname, firstname, phone number, a next pointer
	to a phonebookitem, and a constructor
	A PhoneBook class consisting of necessary functions,
	head pointer to PhoneBookItem, and variable to keep track of
	number of the items in the list.
	2.)Constants given
	none
	3.)Calculations
	functions to add, delete, copy constructor, print functions, etc
	4.)Print results
	the list will be printed as: last name, first name, phone number
	
	******Algorithm******
	First there is the default constructor for the struct
	When user enters first name, last name, and phone number, 
	they will be stored.

	Then there is another default constructor. This sets head pointer
	to null and the number of items, num to 0.
	Then there is the copy constructor. it sets head to null,
	num to 0, and calls the copy function to do the copying.
	
	The Copy function makes a deep copy of the class PhoneBook.
	If num is not equal to zero program will exit with an error message
	Then it will copy items to the current list.

	Then there is the destructor. This is called when the main function ends,
	and will destroy the linked list. It calls the Clear function.

	The Clear function deletes all the nodes and sets num to 0.
	First it creates a pointer p to a PhoneBookItem. While head is
	not equal to NULL, assign head to p, head will equal the next node after
	head, and p will be deleted. End while, and set num to 0.

	Next there is the assignment operator. If the this pointer
	is not the same as the class sent to it, it will clear the
	memory on the left side by calling Clear. Then Copy is called
	to perform the assignment. The this pointer is returned.

	Then there is the IsEmpty function. If the head pointer is equal
	to null, true is returned, otherwise false is returned.

	Size function, returns the number of items in the linked list.

	Then there is the Insert function, which receives 4 parameters,
	the lastname, last, the firstname, first, and the phone number,
	ph, all three passed by reference. It will create a boolean
	variable called answer. If head is equal to null, assign a 
	new PhoneBookItem to head, set num to 1, and set answer to true.
	Now the first item in the list is inserted.Else if last < head->lastname
	or last == head->lastname && first < head->firstname, assign
	a new PhoneBookItem to a pointer p. Then assign head to p arrow next.
	Then assign p to the head pointer, increment num by 1, and answer is
	true. Else the function will search through the rest of the list until
	it finds 2 successive nodes between which the new name should be placed.
	Create 2 PhoneBookItem pointers, p and q. Assign head to p, assign
	head ->next to q. While q is not equal to null and last is greater
	than q->lastname, assign q to p, assign q->next to q. It will check
	for a duplicate record, if not, the person will be added. If a duplicate
	record is found, set answer to false. return answer.

	Next is the Delete function of type bool.The last name and first name
	are passed as reference parameters, last, first. A bool variable, answer is created.
	
	Lookup function, of type bool. Last name, first name, and phone number
	are passed by reference. Create 2 bool variables, moreToSearch and found,
	set both to false. Pointer to a PhoneBookItem, location, is created.
	Set head to location. Whether location != null, set to MoreToSearch.
	While MoreToSearch and not found, if location arrow lastname is less than last,
	set location arrow next to location. Whether location is not equal to null,
	set to MoreToSearch.End if. Else if location arrow last name equals last
	AND location arrow firstname EQUALS first, set found to true, assign
	location arrow phone to ph. Else moreToSearch is false. Return found.

	Output stream operator overload. ostream variable out, PhoneBook variable
	P, both passed by reference. Assign P.head to find, a pointer to a 
	PhoneBookItem. If find equals null, return out. While find does not equal null,
	find arrow lastname, find arrow firstname, find arrow phone number is passed
	to out object. find equals find arrow next. End while, return out. 
	
	
*/
#include <iostream>
#include <string>
#include "phone.h"

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
	
	else if (last < head->lastname )
	{
		PhoneBookItem* p = new PhoneBookItem(last, first, ph);
		p->next = head;
		head = p;
		num++;
		answer = true;
	}

	else if (last == head->lastname && first < head->firstname)
	{
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
		while (q != NULL && last > q->lastname || 
			q!= NULL && last == q->lastname && first > q->firstname)	
		{
			p = q;
			q = q->next;
		}

		//check to see we don't have a duplicate record
		//if not, then add new person to the list between p and q
		//this works even if q is NULL

		if (q != NULL && last == q->lastname && first == q->firstname)
			answer = false;

		else 
		{
			PhoneBookItem* r = new PhoneBookItem(last, first, ph);
			p->next = r;
			r->next = q;
			num++;
			answer = true;
		}
	}
	return answer;
}

bool PhoneBook::Delete(const string& last, const string& first)
{
	bool answer;
	 // q
	PhoneBookItem* p = head; // p
	PhoneBookItem* q = head->next;

	if (head == NULL)// can't delete from empty list
	{
		answer = false;
	}

	else if (last == head->lastname && first == head->firstname)
	{
		 // first node
		head = head->next; // move by one node
		
		delete p; // delete first node
		
		num--;
		answer = true;
	}

	else 
	{
		
		while (q != NULL && last > q->lastname 
			|| q != NULL && last == q->lastname && first > q->firstname)
		{	
			p = p->next;
			q = q->next;
			 
		}
		// now if location points to the right place, delete it
		if (q != NULL && last == q->lastname && first == q->firstname)
		{ // delete the node pointed to by location from the list
			
			//p = q;
			//q = q->next;
			p->next = q->next;
			delete q;
			

			num--;
			 answer = true;
		}

		else 
		{ // otherwise, tempLocation->lastname and either location is null or 
			//last < location->lastname. So the last name is not in the list

			answer = false;
			
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
	
	PhoneBookItem* find = P.head;
	
	if (find == NULL)
		return out;
	//else { use a while loop to read the whole loop and print out the names+phone numbers
		while (find != NULL)
		{
		
		
		out << find->lastname <<", "<<  find->firstname <<" "<< find->phone <<endl;
		find = find->next;
		
		}
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
