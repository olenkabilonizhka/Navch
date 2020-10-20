#include "Command.h"
#include <typeinfo>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int Command::StNum = 0;
int Command::SfNum = 0;
int Command::StemNum = 0;
int Command::b = 0;
int Command::m = 0;

Command::Command() {
	sts = new Student*[100];
	ifstream fin3("Students.txt");
	if (fin3.is_open()) {
		while (!fin3.eof()) {
			string name; string lastname; int year; char s[50];
			fin3 >> name >> lastname >> year;
			fin3.get(s, 50);
			string course(s);
			Student* temp = new Student(name, lastname, year, course);
			sts[StNum++] = temp;
		}
	}
	fin3.close();

	ifstream fin5("StudentsEM.txt");
	if (fin5.is_open()) {
		while (!fin5.eof()) {
			string name; string lastname; int year; char s[50];
			fin5 >> name >> lastname >> year;
			fin5.get(s, 50);
			string course(s);
			StudentEM* temp = new StudentEM(name, lastname, year, course);
			AddStudentEM(*temp); StemNum++;
		}
	}
	fin5.close();

	stf = new Staff*[50];
	ifstream fin4("Staff.txt");
	if (fin4.is_open()) {
		while (!fin4.eof()) {
			string name; string lastname; string subject;
			fin4 >> name >> lastname >> subject;
			Staff* temp = new Staff(name, lastname, subject);
			stf[SfNum++] = temp;
		}
	}
	fin4.close();

	bachelor = new string[10];
	ifstream fin("Bachelor.txt");
	if (fin.is_open()) {
		b = Command::File(fin, bachelor, 10);
	}
	fin.close();

	master = new string[10];
	ifstream fin2("Master.txt");
	if (fin2.is_open()) {
		m = Command::File(fin2, master, 10);
	}
	fin2.close();

	list = new StaffAcademics*[6];
	StaffAcademics* r;
	for (int i = 0; i < 6; i++) {
		if (SfNum < 6) { r = new StaffAcademics(*stf[i%SfNum], i + 1); }
		else { r = new StaffAcademics(*stf[i], i + 1); }
		list[i] = r;
	}
}

template <typename T>
int Command::File(istream& fin, T* mass, int max) {
	char line[100]; int i = 0;
	while (!fin.eof()) {
		try {
			if (i >= max)
				throw "So many!";
			fin.getline(line, 100);
			mass[i++] = line;
		}
		catch (char* a) {
			cout << a << endl;
			break;
		}
	}
	return i;
}

void Command::AddStudentEM(StudentEM& stem) {
	AddStudent(stem);
}

void Command::AddStudent(Student& st) {
	try {
		if (StNum >= 100)
			throw "No memory!";
		sts[StNum++] = &st;
	}
	catch (string a) { cout << a << endl; }
}

void Command::AddStaff(Staff& sf) {
	try {
		if (StNum >= 100)
			throw "No memory!";
		stf[SfNum++] = &sf;
	}
	catch (string a) { cout << a << endl; }
}

void Command::AllStudents() {
	for (int i = 0; i < StNum; i++) {
		sts[i]->Print();
	}
}

void Command::AllStaff() {
	for (int i = 0; i < SfNum; i++) {
		stf[i]->Print();
	}
}

void Command::Courators() {
	for (int i = 0; i < 6; i++) {
		list[i]->Print();
	}
}

void Command::GetBach() {
	for (int i = 0; i < b; i++) {
		cout << bachelor[i] << endl;
	}
}

void Command::GetMast() {
	for (int i = 0; i < m; i++) {
		cout << master[i] << endl;
	}
}


void Command::ChangeCour(int year, int prof) {
	if (year == -1 || prof == -1) {
		cout << "Didn't add!" << endl;
	}
	else {
		list[year - 1] = new StaffAcademics(*stf[prof - 1], year);
	}
}

int Command::GetSfNum() {
	return SfNum;
}

string Command::PopLang() {
	int mx = 0; string mxst;
	for (int i = 0; i < b; i++) {
		int n = 0;
		for (int j = 0; j < StNum; j++) {
			if (bachelor[i] == sts[j]->GetCourse())
				n++;
		}
		if (n > mx) {
			mx = n;
			mxst = bachelor[i];
		}
	}
	return mxst;
}

int Command::PopYear() {
	int mx = 0; int maxyear = 0;
	for (int i = 0; i < StNum; i++) {
		int n = 0;
		for (int j = i; j < StNum; j++) {
			if (sts[i]->GetYear() == sts[j]->GetYear())
				n++;
		}
		if (n > mx) {
			mx = n;
			maxyear = sts[i]->GetYear();
		}
	}
	return maxyear;
}

Command::~Command() {
	ofstream fout("Students.txt");
	for (int i = 0; i < StNum; i++) {
		if (sts[i]->ti() == "Student") {
			if (i != 0) fout << endl;
			fout << sts[i]->GetName() << " " << sts[i]->GetLastname() << " " << sts[i]->GetYear() << sts[i]->GetCourse();
		}
	}
	fout.close();

	ofstream fout2("Staff.txt");
	for (int i = 0; i < SfNum; i++) {
		fout2 << stf[i]->GetName() << " " << stf[i]->GetLastname() << " " << stf[i]->GetSubject();
		if (i != (SfNum - 1)) { fout2 << endl; }
	}
	fout2.close();

	ofstream fout3("StudentsEM.txt"); int j = 1;
	for (int i = 0; i < StNum; i++) {
		if (sts[i]->ti() == "StudentEM") {
			if (j == 0) { fout3 << endl; }
			else { j--; }
			fout3 << sts[i]->GetName() << " " << sts[i]->GetLastname() << " " << sts[i]->GetYear() << sts[i]->GetCourse();
		}
	}
	fout3.close();

	//cout << "Added to file!" << endl;
	for (int i = 0; i < StNum; i++) {
		delete sts[i];
	}
	for (int i = 0; i < SfNum; i++) {
		delete stf[i];
	}
	for (int i = 0; i < 6; i++) {
		delete list[i];
	}
	delete[] sts;
	delete[] stf;
	delete[] bachelor;
	delete[] master;
	delete[] list;
}