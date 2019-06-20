#ifndef _FEELINGS_H
#define _FEELINGS_H
#include<iostream>

class Feeling {
private:
	char name[101];
	char emoticon[5];
	double rate;
public:
	Feeling(const char*, const char*);
	void setRate(const double);
	const double getRate()const;
	void print()const;
};

Feeling::Feeling(const char* _name, const char* _emoticon) {
	strcpy(name, _name);
	strcpy(emoticon, _emoticon);
	rate = 0;
}

void Feeling::setRate(const double _rate) {
	rate = (_rate < 1 ? _rate : 1);
}

const double Feeling::getRate()const {
	return rate;
}

void Feeling::print() const {
	std::cout << "Feeling: " << name << " " << emoticon << "\nRate: " << rate << std::endl;
}

class Happiness :public Feeling {
public:
	Happiness() :Feeling("Happiness", ":)") {}
};

class Sadness :public Feeling {
public:
	Sadness() :Feeling("Sadness", ":(") {}
};

class Love :public Feeling {
public:
	Love() :Feeling("Love", "<3") {}
};


#endif // _FEELINGS_H

