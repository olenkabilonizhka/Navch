#include "Command.h"
#include "Staff.h"
#include <string>
using namespace std;
#ifndef STAFFACADEMICS_H
#define STAFFACADEMICS_H

class StaffAcademics : public Staff {
public:
	StaffAcademics(Staff& = Staff(), int = 0);
	StaffAcademics(string name, string lastname, string subject, int);
	void Print();
};

#endif 