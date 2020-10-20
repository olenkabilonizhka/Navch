#include "Command.h"
#include <typeinfo>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int Command::b = 0;
int Command::m = 0;

Command::Command() {
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
		Staff* s = (Staff*)StfRepository[i];
		if (StfRepository.Size() < 6) { r = new StaffAcademics(*StfRepository[i % (StfRepository.Size())], i + 1); }
		else { r = new StaffAcademics(*StfRepository[i], i + 1); }
		list[i] = r;
	}
}

int Command::GetSfNum() {
	return StfRepository.Size();
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
	StsRepository.Add(stem);
}

void Command::AddStudent(Student& st) {
	StsRepository.Add(st);
}

void Command::AddStaff(Staff& sf) {
	StfRepository.Add(sf);
}

void Command::AllStudents() {
	StsRepository.PrintAll();
}

void Command::AllStaff() {
	StfRepository.PrintAll();
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
		list[year - 1] = new StaffAcademics(*StfRepository[prof - 1], year);
	}
}

string Command::PopLang() {
	int mx = 0; string mxst;
	for (int i = 0; i < b; i++) {
		int n = 0;
		for (int j = 0; j < StsRepository.Size(); j++) {
			if (bachelor[i] == StsRepository[j]->GetCourse())
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
	for (int i = 0; i < StsRepository.Size(); i++) {
		int n = 0;
		for (int j = i; j < StsRepository.Size(); j++) {
			if (StsRepository[i]->GetYear() == StsRepository[j]->GetYear())
				n++;
		}
		if (n > mx) {
			mx = n;
			maxyear = StsRepository[i]->GetYear();
		}
	}
	return maxyear;
}

Command::~Command() {
	delete[] bachelor;
	delete[] master;
	delete[] list;
}