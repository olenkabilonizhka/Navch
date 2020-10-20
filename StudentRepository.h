#pragma once

#include "Repository.h"
#include "Student.h"
#include "StudentEM.h"

class StudentRepository : public Repository {
public:
	StudentRepository(bool sync = false);
	~StudentRepository();
	bool Add(Student& st);
	bool Add(StudentEM& stem);
	void PrintAll();
	void Read();
	void Write();
	int Size();
	Student* operator[](int i);
};