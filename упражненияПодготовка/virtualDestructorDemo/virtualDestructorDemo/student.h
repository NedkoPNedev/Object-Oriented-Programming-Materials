#ifndef _STUDENT_H
#define _STUDENT_H

#include "human.h"

class Student : public Human {
private:
	char* university;
public:
	Student(const char*, const char*);
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();
};

#endif // !_STUDENT_H

