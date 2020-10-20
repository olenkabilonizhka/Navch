#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string name, string lastname) {
	this->name = name;
	this->lastname = lastname;
}

void Person::Print() {
	cout << " Just a person!" << endl;
}

string Person::GetName() {
	return name;
}

string Person::GetLastname() {
	return lastname;
}