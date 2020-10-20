#ifndef COMMAND_H
#define COMMAND_H

#include "Student.h"
#include "Staff.h"
#include "StaffAcademics.h"
#include "StudentEM.h"
#include "StudentRepository.h"
#include "StaffRepository.h"
#include <string>
using namespace std;

class Command {
private:
	StudentRepository StsRepository = StudentRepository(true);
	StaffRepository StfRepository = StaffRepository(true);
	string* bachelor;
	string* master;
	StaffAcademics** list;
	static int b;
	static int m;
public:
	Command();
	void AddStaff(Staff&);
	void AddStudent(Student&);
	void AddStudentEM(StudentEM&);
	void AllStaff();
	void AllStudents();
	void Courators();
	void GetBach();
	void GetMast();
	void ChangeCour(int = -1, int = -1);
	int PopYear();
	int GetSfNum();
	string PopLang();
	template <typename T>
	static int File(istream&, T*, int);
	~Command();
};

#endif 


