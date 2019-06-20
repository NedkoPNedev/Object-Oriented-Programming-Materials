#include <iostream>
#include <string.h>

using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int = 1, int = 1, int = 1990);
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void print() const { cout << "Day : " << day << " Month : " << month << " Year : " << year << endl; }

    bool operator==(const Date& other) const{
        return day == other.day && month == other.month && year == other.year;
    }
};

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

const Date DATE;

class Person {
private:
    char* name;
    Date date;
    void copyPerson(const Person&);
public:
    Person(const char* = "", const Date = DATE);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    const char* getName() const { return name; }
    const Date getDate() const { return date; }
};

void Person::copyPerson(const Person& other) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    date = other.date;
}

Person::Person(const char* name, const Date date) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->date = date;
}

Person::Person(const Person& other) {
    copyPerson(other);
}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        delete[] name;
        copyPerson(other);
    }
    return *this;
}

Person::~Person() {
    delete[] name;
}

class Patient : public Person {
private:
    int visits;
public:
    Patient(const char* name = "", const Date& date = DATE, int visits = 0) :
        Person(name, date), visits(visits) {}

    bool operator==(const Patient&) const;
};

bool Patient::operator==(const Patient& other) const{
    return !strcmp(this->getName(), other.getName()) && this->getDate() == other.getDate();
}


class Doctor : public Person {
private:
    Patient* patients;
    int capacity;
    int position;

    void copyDoctor(const Doctor&);
public:
    Doctor(const char* name, const Date date, int capacity);
    Doctor(const Doctor&);
    Doctor& operator=(const Doctor&);
    ~Doctor();

    bool addPatient(const Patient&);
};

void Doctor::copyDoctor(const Doctor& other) {
    patients = new Patient[other.capacity];
    capacity = other.capacity;
    position = other.position;
    for (int i = 0; i < position; i++) {
        patients[i] = other.patients[i];
    }
}

Doctor::Doctor(const char* name, const Date date, int capacity) :
    Person(name, date), capacity(capacity) {
        patients = new Patient[capacity];
        position = 0;
}

Doctor:: Doctor(const Doctor& other) : Person(other) {
    copyDoctor(other);
}

Doctor& Doctor::operator=(const Doctor& other) {
    if (this != &other) {
        Person::operator=(other);
        delete[] patients;
        copyDoctor(other);
    }
    return *this;
}

Doctor::~Doctor() {
    delete[] patients;
}

bool Doctor::addPatient(const Patient& patient) {
    for (int i = 0; i < position; i++) {
        if (patients[i] == patient) {
            cout << "Patient " << patient.getName() << " is already in the list!\n";
            return false;
        }
    }
    if (position >= capacity) {
        cout << "Doctor's list is full!\n";
        return 0;
    }
    patients[position] = patient;
    position++;
    return true;
}



