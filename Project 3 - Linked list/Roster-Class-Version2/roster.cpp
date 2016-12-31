#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

// Constructor for the structure RosterNode
RosterNode::RosterNode(const string& id, const string& nm)  {
	idnum = id;
	name = nm;
	next = NULL;
}

//Default Constructor for Roster
Roster::Roster()  {
	head = NULL;
	num = 0;
}


Roster::~Roster()  {
	// Must delete each node.  We must ensure that we can access the successor of a
	// node before deleting that node.
	RosterNode* p;
	while (head != NULL)  {
		p = head;
		head = head->next;
		delete p;
	}
	num = 0;
	// This last statement is not always necessary in a destructor, but it may be 
	// helpful in the Clear() function of homework 3
}

// Copy Constructor
Roster::Roster(const Roster& other)  {
	//  make a deep copy
		num = other.num;
		if (other.IsEmpty() ) {
			head = NULL;
		} else {
			head = new RosterNode(other.head->idnum, other.head->name);
			RosterNode* q = head;
			RosterNode* p = other.head->next;
			while ( p != NULL ) {
				q->next = new RosterNode(p->idnum, p->name);
				p=p->next;
			    q=q->next;
			}
		}


Roster& Roster::operator=(const Roster& other)   {
	if (this != &other) {
		// Clear out the memory on the left side
		RosterNode* p;  // temporary variable to move down list
		// loop to deallocate dynamic memory
	    while (head != NULL)  {   
		    p = head;
			head = head->next;
			delete p;
		}
		num = 0; //  num isn't dynamic memory, but we set it equal to 0 since we just cleared out the dynamic memory

		//  make a deep copy
		num = other.num;
		if (other.IsEmpty() ) {
			head = NULL;
		} else {
			head = new RosterNode(other->idnum, other->name);
			RosterNode* q = head;
			RosterNode* p = other.head->next;
			while ( p != NULL ) {
				q->next = new RosterNode(p->idnum, p->name);
				p=p->next;
			    q=q->next;
			}
		}
		return *this;
	}








//  Enroll member function accepts two C++ strings as input:  the student id number (id),
//  and the student name (nm).  It returns ture if the given student was successfully 
//  enrolled in the list; false if the student id number already is in the list.
bool Roster::Enroll (const string& id, const string& nm)  {
	// Set ans to true if enrollment was successful; false otherwise
	bool ans;

	if (head == NULL)  {
		// The current roster is empty, so make the student the head of the list
		// and set the list length to 1
		head = new RosterNode(id, nm);
		num = 1;
		ans = true;
	} else if ( id < head->idnum )  {
		// The id number given comes before the smallest id number of any student
		// currently enrolled in the course.  So make the given student the head
		// of the head of the list
		RosterNode* p = new RosterNode(id, nm);
		p->next = head;
		head = p;
		num++;
	    ans = true;
	} else if (id == head->idnum)  {
		// Duplicate id number - enrollment fails
		ans = false;
	} else {
		// Remaining case: search through the list until you find two successive
		// nodes between which the new student should be placed.

		// First set p and q to point to the first two nodes of the list.
		RosterNode* p = head;
		RosterNode* q = head->next;

		// Keep moving down while the given id number is larger than q's id number.
		// Notice that the first condition protects us from dereferencing the NULL
		// pointer in the second condition.
		while (q != NULL  &&  id > q->idnum)  {
			p = q;
			q = q->next;
		}

		// Check to make sure we have not found a duplicate record.
		// If we haven't, then add the new student to the list between 
		// p and q.  (This works even if q is NULL)
		if (q != NULL && id == q->idnum)  {
			ans = false;
		}  else  {
			RosterNode* r = new RosterNode(id, nm);
			p->next = r;
			r->next = q;
			num++;
			ans = true;
		}
	}
	return ans;
}

// Drop member function accepts one C++ string as input: the student id number (id).
// It returns true if the given student number was deleted from the list successfully;
// false if the student id number is not in the list.
// *** NOTE: some blocks of code have been omitted here - try to fill them in since 
//     they are similar to what you need for homework #4
bool Roster::Drop(const string& id)  {
	bool ans;

	if (head == NULL) {
		// you can't delete from an empty list
		ans = false;
	} else if (id== head->idnum)  {
		// the first node has to be deleted.
		// *** code omitted
	} else {
		// Scan the list as in Enroll.  Keep moving p and q down the list until 
		// either you've scanned the entire lsit, or you have gone past the point 
		// where the given id should be.  So we use the fact that the list is
		// sorted by id number.
		RosterNode* p = head;
		RosterNode* q = head->next;
		while (q != NULL && id > q->idnum)  {
			p = q;
			q = q->next;
		}
		// Now if q points to the right place, delete it.
		if (q != NULL  && id == q->idnum  {
			// delete the node pointed to by q from the list.
			// *** code omitted
		} else {
			// Otherwise, p->idnum and either q is NULL or id < q->idnum.
			// In any case, the id number in question is NOT in the list
			ans = false;
		}
	}
	return ans;
}

// *** Definitions of other functions omitted
