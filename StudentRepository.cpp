#include "StudentRepository.h"
#include "Entity.h"
#include <iostream>
#include <fstream>

StudentRepository::StudentRepository(bool sync) :Repository(sync) {
	Read();
};

StudentRepository::~StudentRepository() {
	Write();
};

int StudentRepository::Size() {
	return n;
}

void StudentRepository::PrintAll() {
	for (int i = 0; i < n; i++) {
		Student* s = (Student*)mass[i];
		s->Print();
	}
}

Student* StudentRepository::operator[](int i) {
	return (Student*)mass[i];
}

bool StudentRepository::Add(Student& st) {
	return Repository::Add((Entity*)&st);
};

bool StudentRepository::Add(StudentEM& stem) {
	return Repository::Add((Entity*)&stem);
}

void StudentRepository::Read() {
	ifstream fin3("Students.txt");
	if (fin3.is_open()) {
		while (!fin3.eof()) {
			string name; string lastname; int year; char s[50];
			fin3 >> name >> lastname >> year;
			fin3.get(s, 50);
			string course(s);
			Student* temp = new Student(name, lastname, year, course);
			Add(*temp);
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
			Add(*temp);
		}
	}
	fin5.close();
};

void StudentRepository::Write() {
	ofstream fout("Students.txt");
	for (int i = 0; i < n; i++) {
		Student* sts = (Student*)mass[i];
		if (sts->ti() == "Student") {
			if (i != 0) fout << endl;
			fout << sts->GetName() << " " << sts->GetLastname() << " " << sts->GetYear() << sts->GetCourse();
		}
	}
	fout.close();

	ofstream fout3("StudentsEM.txt"); int j = 1;
	for (int i = 0; i < n; i++) {
		StudentEM* sts = (StudentEM*)mass[i];
		if (sts->ti() == "StudentEM") {
			if (j == 0) { fout3 << endl; }
			else { j--; }
			fout3 << sts->GetName() << " " << sts->GetLastname() << " " << sts->GetYear() << sts->GetCourse();
		}
	}
	fout3.close();
};