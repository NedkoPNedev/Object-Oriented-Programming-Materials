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

    bool operator==(const Date& other) {
        return day == other.day && month == other.month && year == other.year;
    }
};

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

const Date DATE;

class Person {
private:
    char* name;
    Date birthDate;
    void copyPerson(const Person&);
public:
    Person(const char* = "", Date = DATE);
    Person(const Person&);
    Person& operator=(const Person&);
    ~Person();

    const char* getName() const { return name; }
    Date getBirthDate() const { return birthDate; }
    void print() const { cout << "Name : " << name << endl; cout << "Birth date : "; birthDate.print(); }
};

void Person::copyPerson(const Person& other) {
    birthDate = other.birthDate;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
}

Person::Person(const char* name, Date date) : birthDate(date) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
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
    int numVisits;
public:
    Patient(const char* = "", Date = DATE, int = 0);
    int getNumVisits() const { return numVisits; }
    void print() const { Person::print(); cout << "Visits : " << numVisits << endl; }

    void setVisits(int newVisits) { numVisits = newVisits; }
    int getVisits() const { return numVisits; }

    bool operator==(const Patient&);
};

Patient::Patient(const char* name, Date date, int visits) :
    Person(name, date), numVisits(visits) {}

bool Patient::operator==(const Patient& other) {
    return (!strcmp(getName(), other.getName())) && getBirthDate() == other.getBirthDate();
}

class Doctor : public Person {
private:
    Patient* patients;
    int cap;
    int curr;
    void copyDoctor(const Doctor&);
public:
    Doctor(const char*, Date, int);
    Doctor(const Doctor&);
    Doctor& operator=(const Doctor&);
    ~Doctor();

    bool addPatientVisit(const Patient&);
    double getAverage() const;
    void printPatients(int visits) const;
};

Doctor::Doctor(const char* name, Date date, int cap) : Person(name, date), cap(cap) {
    patients = new Patient[cap];
    curr = 0;
}

Doctor::Doctor(const Doctor& other) : Person(other) {
    cap = other.cap;
    curr = other.curr;
    patients = new Patient[cap];
    for (int i = 0; i < curr; i++) {
        patients[i] = other.patients[i];
    }
}

Doctor& Doctor::operator=(const Doctor& other) {
    if (this != &other) {
        Person::operator=(other);
        delete[] patients;
        cap = other.cap;
        curr = other.curr;
        patients = new Patient[cap];
        for (int i = 0; i < curr; i++) {
            patients[i] = other.patients[i];
        }
    }
    return *this;
}

Doctor::~Doctor() {
    delete[] patients;
}

bool Doctor::addPatientVisit(const Patient& other) {
    int i;
    for (i = 0; i < curr; i++) {
        if (patients[i] == other) {
            patients[i].setVisits(patients[i].getVisits() + 1);
            return true;
        }
    }
    if (i == curr && curr < cap) {
        patients[curr++] = other;
        return false;
    }
    cout << "List of patients is full!\n";
    return false;
}

double Doctor::getAverage() const {
    int sum = 0;
    for (int i = 0; i < curr; i++) {
        sum += patients[i].getNumVisits();
    }
    if (curr == 0) return 0.0;
    return (double)(sum / curr);
}

void Doctor::printPatients(int numVisits) const {
    for (int i = 0; i < curr; i++) {
        if (patients[i].getNumVisits() > numVisits) {
            patients[i].print();
        }
    }
}

int main() {
    Patient gosho("Gosho", Date(6, 10, 1998), 5);
    Patient sasho("Sasho", Date(8, 2, 1995), 3);
    Patient pesho("Pesho", Date(10, 4, 1993), 6);

    Doctor Stavri("Stavrigor", Date(7, 01, 1975), 10);
    Stavri.addPatientVisit(gosho);
    Stavri.addPatientVisit(sasho);
    Stavri.addPatientVisit(pesho);

    Stavri.addPatientVisit(sasho);
    cout << Stavri.getAverage() << endl;
    Stavri.printPatients(5);

}
