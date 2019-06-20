#ifndef _HUMAN_H
#define _HUMAN_H

class Human {
protected:
	char* name;
public:
	Human(const char*);
	Human(const Human&);
	Human& operator=(const Human&);
	~Human();
};


#endif // !_HUMAN_H

