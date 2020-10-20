#pragma once

#include "Entity.h"

class Repository {
protected:
	Entity** mass;
	int size;
	int n;
	bool sync;

	bool Add(Entity*);
	virtual void Read() {};
	virtual void Write() {};
	virtual void PrintAll() {};
public:
	Repository(bool sync = false);
	~Repository();
};