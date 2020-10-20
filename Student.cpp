#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(string name, string lastname, int year, string course) :Person(name, lastname) {
	this->year = year;
	this->course = course;
};

void Student::Print() {
	cout << name << " " << lastname << "," << course << endl;
}

string Student::GetCourse() {
	return course;
}

int Student::GetYear() {
	return year;
}

string Student::ti() {
	return "Student";
}