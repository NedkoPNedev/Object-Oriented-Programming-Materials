#include "student.h"
#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)

Student::Student(const char * name, const char * uni) : Human(name) {
	university = new char[strlen(uni) + 1];
	strcpy(university, uni);
}

Student::Student(const Student & other) : Human(other) {
	university = new char[strlen(other.university) + 1];
	strcpy(university, other.university);
}

Student & Student::operator=(const Student & other) {
	if (this != &other) {
		Human::operator=(other);
		delete[] university;
		university = new char[strlen(other.university) + 1];
		strcpy(university, other.university);
	}
	return *this;
}

Student::~Student() {
	std::cout << "Destuctor of student " << name << " studying at " << university << std::endl;
	delete[] university;
}
