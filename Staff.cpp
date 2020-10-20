#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff(string name, string lastname, string subject) :Person(name, lastname) {
	this->subject = subject;
}

Staff::Staff(Person& p, string subject) : Person(p) {
	this->subject = subject;
}

void Staff::Print() {
	cout << name << " " << lastname << ", " << subject << endl;
}

string Staff::GetSubject() {
	return subject;
}