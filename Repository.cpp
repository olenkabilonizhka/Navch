#include "Repository.h"
#include <iostream>
using namespace std;

Repository::Repository(bool sync) {
	this->sync = sync;
	size = 100;
	mass = new Entity*[size];
	n = 0;
	Read();
}

Repository::~Repository() {
	delete[] mass;
}

bool Repository::Add(Entity* entity) {
	try {
		if (n >= 100)
			throw "No memory!";
		mass[n++] = entity;
	}
	catch (char* a) { cout << a << endl; }
	return true;
}