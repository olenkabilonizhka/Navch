#include "Student.h"
#include "StudentEM.h"
#include "Command.h"
#include "Staff.h"
#include "StaffAcademics.h"
#include <fstream>
#include <iostream>
using namespace std;

int Additional(Command& cmd) {
	cout << endl << "Press 0 to Menu, other digits to Exit" << endl;
	int s; cin >> s;
	if (s == 0) { return 0; }
	else { return -1; }
}

void Menu(Command& cmd) {
	int user; string name; string lastname; int year; int prof; char s[50]; string j; string course; Student* d; StudentEM* e; Staff* r;
	system("cls");
	cout << "Menu:" << endl;
	cout << "1.Academics" << endl;
	cout << "2.For student" << endl;
	cout << "3.Profkom" << endl;
	cout << "4.Exit" << endl;
	bool bol = true;
	do {
		cin >> user;
		cout << endl;
		switch (user) {
		case 1:
			cout << "1.Bachelor" << endl;
			cout << "2.Master" << endl;
			cout << "3.Return" << endl;
			do {
				cin >> user;
				cout << endl;
				switch (user) {
				case 1:
					cmd.GetBach();
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 2:
					cmd.GetMast();
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 3:
					return Menu(cmd);
				default:
					cout << "Incorrect, input again:" << endl;
				}
			} while (bol);
			break;
		case 2:
			cout << "1.Courators" << endl;
			cout << "2.Add Student" << endl;
			cout << "3.Return" << endl;
			do {
				cin >> user;
				cout << endl;
				switch (user) {
				case 1:
					cmd.Courators();
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 2:
					cout << "Input 'FT' or 'EM':" << endl;
					try {
						cin >> j;
						if (j != "EM") {
							if (j != "FT") {
								throw "No option!";
							}
						}
					}
					catch (const char* a) {
						cout << a << " Input again: ";
						cin >> j;
					}
					cout << "Input:" << endl;
					cout << "Name: "; cin >> name;
					cout << "Last name: "; cin >> lastname;
					try {
						cout << "Year in: ";
						cin >> year;
						if (year > 2020 || year < 2014)
							throw "Can't be a student";
					}
					catch (char* a) { cout << a << "! Input again: "; cin >> year; }
					cout << "Course:"; cin.get();  cin.getline(s, sizeof(s));
					if (j[0] == 'E') {
						e = new StudentEM(name, lastname, year, s);
						cmd.AddStudentEM(*e);
					}
					else if (j[0] == 'F') {
						d = new Student(name, lastname, year, s);
						cmd.AddStudent(*d);
					}
					cout << "Added!" << endl;
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 3:
					return Menu(cmd);
					break;
				default:
					cout << "Incorrect, input again:" << endl;
				}
			} while (bol);
			break;
		case 3:
			cout << "1.Staff" << endl;
			cout << "2.Add professor" << endl;
			cout << "3.All Students" << endl;
			cout << "4.Change courator" << endl;
			cout << "5.The most popular course" << endl;
			cout << "6.The most popular year" << endl;
			cout << "7.Return" << endl;
			do {
				cin >> user;
				cout << endl;
				switch (user) {
				case 1:
					cmd.AllStaff();
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 2:
					cout << "Input:" << endl;
					cout << "Name: "; cin >> name;
					cout << "Last name: "; cin >> lastname;
					cout << "Language: "; cin >> course;
					r = new Staff(name, lastname, course);
					cmd.AddStaff(*r);
					cout << "Added!" << endl;
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 3:
					cmd.AllStudents();
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 4:
					try {
						cout << "Year: "; cin >> year;
						if (year < 1 || year>6)
							throw "Must be from 1 to 6!";
					}
					catch (char* a) { cout << a << " Input again: "; cin >> year; }
					try {
						cout << "Num of professor: "; cin >> prof;
						if (prof < 1 || prof> cmd.GetSfNum())
							throw "No professor!";
					}
					catch (char* a) { cout << a << " Input again: "; cin >> year; }
					cmd.ChangeCour(year, prof);
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 5:
					cout << "The most popular course among the students is" << cmd.PopLang() << endl;
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 6:
					cout << "The most popular year is " << cmd.PopYear() << endl;
					if (Additional(cmd) == 0) { return Menu(cmd); }
					else { bol = false; }
					break;
				case 7:
					return Menu(cmd);
					break;
				default:
					cout << "Incorrect, input again:" << endl;
				}
			} while (bol);
			break;
		case 4:
			bol = false;
			break;
		default:
			cout << "Incorrect, input again:" << endl;
		}
	} while (bol);
}

int main() {
	Command cmd;
	Menu(cmd);
	return 0;
}