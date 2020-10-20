#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include<string>
using namespace std;

class Staff : public Person {
protected:
	string subject;
	int yearcourse;
public:
	Staff(string = "", string = "", string = "");
	Staff(Person& p, string = "");
	void Print() override;
	string GetSubject();
};


#endif