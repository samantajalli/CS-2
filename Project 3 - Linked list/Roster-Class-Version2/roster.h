#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
using namespace std;

struct RosterNode {
	string idnum;   // Student id number (e.g., 123-45-6789)
	string name;    // Student name (e.g., Greg Fry)
	RosterNode* next;
	// Constructor:
	RosterNode (const string& id, const string& nm);
};

class Roster {
public:
	Roster();                // Default constructor
	Roster(const Roster&);   // Copy constructor
	~Roster();               // Destructor
	Roster& operator=(const Roster&);  // Assignment operator

	// Returns true if the roster has no students enrolled.
	bool IsEmpty();

	// Returns the number of students enrolled in the course
	int Size();

	// Enroll returns true if enrollment was successful, false otherwise.
	// It is unsuccessful only if the given student is already enrolled.
	bool Enroll(const string& id, cosnt string& nm);

	// Drop returns true if drop was successful, false otherwise.
	// It is unsuccessful oly if the given student was NOT enrolled.
	bool Drop(const string& id);

	// Print the entire roster
	friend ostream& operator<<(ostream&, const Roster&);

private:
	RosterNode* head;    // Pointer to first student in the course
	int num;  // Number of students enrolled in the course
	RosterNode dummy;
};
#endif