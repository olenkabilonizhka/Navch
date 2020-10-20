#include "StaffAcademics.h"
#include<iostream>
using namespace std;

StaffAcademics::StaffAcademics(Staff& profesor, int yearcourse) : Staff(profesor) {
	this->yearcourse = yearcourse;
}

StaffAcademics::StaffAcademics(string name, string lastname, string subject, int yearcourse) : Staff(name, lastname, subject) {
	this->yearcourse = yearcourse;
}

void StaffAcademics::Print() {
	cout << "Courator of " << yearcourse << "-year st.: ";
	Staff::Print();
}