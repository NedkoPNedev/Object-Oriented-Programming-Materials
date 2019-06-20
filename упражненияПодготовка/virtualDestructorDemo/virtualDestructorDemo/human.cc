#include "human.h"
#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)

Human::Human(const char * _name) {
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

Human::Human(const Human & other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
}

Human & Human::operator=(const Human & other) {
	if (this != &other) {
		delete[] name;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
	}
	return *this;
}

Human::~Human() {
	std::cout << "Destructor of human "  << name << std::endl;
	delete[] name;
}
