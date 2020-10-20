#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
	string name;
	string lastname;
public:
	Person(string = "", string = "");
	virtual void Print();
	string GetLastname();
	string GetName();
};

#endif
