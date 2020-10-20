#include "StaffRepository.h"
#include <fstream>

StaffRepository::StaffRepository(bool sync) :Repository(sync) {
	Read();
};

StaffRepository::~StaffRepository() {
	Write();
};

void StaffRepository::PrintAll() {
	for (int i = 0; i < n; i++) {
		Staff* s = (Staff*)mass[i];
		s->Print();
	}
}

int StaffRepository::Size() {
	return n;
}

Staff* StaffRepository::operator[](int i) {
	return (Staff*)mass[i];
}

bool StaffRepository::Add(Staff& sf) {
	return Repository::Add((Entity*)&sf);
};

void StaffRepository::Read() {
	ifstream fin4("Staff.txt");
	if (fin4.is_open()) {
		while (!fin4.eof()) {
			string name; string lastname; string subject;
			fin4 >> name >> lastname >> subject;
			Staff* temp = new Staff(name, lastname, subject);
			Add(*temp);
		}
	}
	fin4.close();
};

void StaffRepository::Write() {
	ofstream fout2("Staff.txt");
	for (int i = 0; i < n; i++) {
		Staff* stf = (Staff*)mass[i];
		string r = stf->GetName();
		fout2 << r << " ";
		fout2 << stf->GetLastname() << " ";
		fout2 << stf->GetSubject();
		if (i != (n - 1)) { fout2 << endl; }
	}
	fout2.close();
};
