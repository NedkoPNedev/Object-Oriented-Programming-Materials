/// Задача 1
/*#include <iostream>
using namespace std;

class Expr {

private:
    int n, x;
public:
    Expr(int = 0, int = 0);
    double getEx1() const;
    double getEx2() const;
};

Expr::Expr(int a, int b) : n(a), x(b) {
}

double Expr::getEx1() const {
    double s = 1.0, x1 = 1.0;
    for (int i = 1; i <= n; i++) {
        x1 = x1*(x/i);
        s += x1;
    }
    return x1;
}

double Expr::getEx2() const {
    double s = 1.0, x1 = 1.0;
    for (int i = 1; i <= 2*n; i += 2) {
        x1 = (-x1)*x*x/(i*(i + 1));
        s += x1;
    }
    return s;
}
*/
/// Задача 2
/*
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NAME = 24;
const int MAX_NUM = 16;

class BankAccount {
private:
    char name[MAX_NAME];
    char accountNum[MAX_NUM];
    double balance;
public:
    BankAccount(const char* = "", const char* = "", double = 0.0);
    void showBankAccount() const;
    void putCash(double);
    void withdraw(double);
};

BankAccount::BankAccount(const char* name, const char* accountNum, double balance) {
    strcpy(this->name, name);
    strcpy(this->accountNum, accountNum);
    this->balance = balance;
}

void BankAccount::showBankAccount() const {
    cout << name << " " << accountNum << " " << balance << endl;
}

void BankAccount::putCash(double cash) {
    if (cash > 0) {
        balance += cash;
    } else {
        cout << "Cash should be positive number!\n";
    }
}

void BankAccount::withdraw(double cash) {
    if (cash > 0 && balance >= cash) {
        balance -= cash;
    } else {
        cout << "Invalid attempt to withdraw money!\n";
    }
}

int main() {
    BankAccount bankAccount("Pesho", "1234", 1200.0);
    bankAccount.showBankAccount();
    bankAccount.putCash(450.2);
    bankAccount.withdraw(1350.5);
    bankAccount.showBankAccount();
    return 0;
}
*/


/// Задача 3
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_NAME_LEN = 50;
const int MAX_NUM_PATIENTS = 100;

class Date {
private:
    int day;
    int month;
    int year;
public:
    Date(int = 1, int = 1, int = 2000);

    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void print() const;
};

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

void Date::print() const {
    cout << day << " " << month << " " << year << endl;
}

class Patient {
private:
    char name[MAX_NAME_LEN];
    Date DOB;
    int numVisits;
public:
    Patient();
    Patient(const char*, Date, int);

    const char* getName() const { return name; }
    Date getDOB() const { return DOB; }
    int getNumVisits() const { return numVisits; }

    void print() const;
};

Patient::Patient() {
    numVisits = 0;
}

Patient::Patient(const char* name, Date d, int visits) : DOB(d), numVisits(visits) {
    strcpy(this->name, name);
}

void Patient::print() const {
    cout << name << endl;
    DOB.print();
    cout << numVisits << endl;
}

class Doctor {
private:
    char name[MAX_NAME_LEN];
    Patient patients[MAX_NUM_PATIENTS];
    int numRegistered;
public:
    Doctor(const char*);
    void registerPatient(const Patient&);
    double getAverage() const;
    void printUpper(int) const;
};

Doctor::Doctor(const char* name) {
    strcpy(this->name, name);
    numRegistered = 0;
}

void Doctor::registerPatient(const Patient& patient) {
    if (numRegistered >= MAX_NUM_PATIENTS - 1) {
        cout << "Registered list is full!\n";
        return;
    }
    patients[numRegistered++] = patient;
}

double Doctor::getAverage() const {
    double sum = 0.0;
    for (int i = 0; i < numRegistered; i++) {
        sum += patients[i].getNumVisits();
    }
    return (numRegistered > 0) ? sum / numRegistered : sum;
}

void Doctor::printUpper(int minNum) const {
    for (int i = 0; i < numRegistered; i++) {
        if (patients[i].getNumVisits() > minNum) {
            patients[i].print();
        }
    }
}

int main() {
    Doctor doc("Petrov");
    int n;
    do {
        cin >> n;
    } while (n < 0 || n > MAX_NUM_PATIENTS);

    char patientName[MAX_NAME_LEN];
    int d, m, y, visits;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin.getline(patientName, MAX_NAME_LEN);
        cin >> d >> m >> y;
        Date date(d, m, y);
        cin >> visits;
        Patient patient(patientName, date, visits);
        doc.registerPatient(patient);
    }
    cout << doc.getAverage() << endl;
    doc.printUpper(3);
    return 0;
}
