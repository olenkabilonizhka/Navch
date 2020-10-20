#ifndef COMMAND_H
#define COMMAND_H

#include "Student.h"
#include "Staff.h"
#include "StaffAcademics.h"
#include "StudentEM.h"
#include <string>
using namespace std;

class Command {
private:
	Student** sts;
	Staff** stf;
	string* bachelor;
	string* master;
	StaffAcademics** list;
	static int StNum;
	static int SfNum;
	static int StemNum;
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
	int GetSfNum();
	int PopYear();
	string PopLang();
	template <typename T>
	static int File(istream&, T*, int);
	~Command();
};

#endif 

