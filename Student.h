#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

class Student : public Person {
protected:
	int year = 2020;
	string course = "";
public:
	Student(string = "", string = "", int = 2020, string = "");
	void Print() override;
	string GetCourse();
	int GetYear();
	virtual string ti();
};

#endif
