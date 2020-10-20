#pragma once

#include "Repository.h"
#include "Staff.h"

class StaffRepository : public Repository {
public:
	StaffRepository(bool sync = false);
	~StaffRepository();
	bool Add(Staff& st);
	void PrintAll();
	void Read();
	void Write();
	int Size();
	Staff* operator[](int i);
};
