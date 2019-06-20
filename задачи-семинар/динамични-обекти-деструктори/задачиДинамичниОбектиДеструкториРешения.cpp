/// Задача 1

#include <iostream>
#include <math.h>
using namespace std;

class Point3 {
private:
    int x, y, z;
public:
    Point3(int = 0, int = 0, int = 0);
    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }
};

Point3::Point3(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double getDistance(const Point3& point) {
    return sqrt((double)(point.getX() * point.getX() +
                         point.getY() * point.getY() +
                         point.getZ() * point.getZ()));
}

int main() {
    Point3** points = new Point3*[10];
    int x, y, z;
    for (int i = 0; i < 10; i++) {
        cin >> x >> y >> z;
        points[i] = new Point3(x, y, z);
    }
    double minPointDistance = getDistance(*points[0]);
    double maxPointDistance = getDistance(*points[0]);
    Point3* maxPointPtr;
    Point3* minPointPtr;
    double currDistance;
    for (int i = 1; i < 10; i++) {
        currDistance = getDistance(*points[i]);
        if (currDistance < minPointDistance) {
            minPointDistance = currDistance;
            minPointPtr = points[i];
        }
        if (currDistance > maxPointDistance) {
            maxPointDistance = currDistance;
            maxPointPtr = points[i];
        }
    }
    cout << minPointPtr->getX() << " " << minPointPtr->getY() << " " << minPointPtr->getZ() << endl;
    cout << maxPointPtr->getX() << " " << maxPointPtr->getY() << " " << maxPointPtr->getZ() << endl;

    for (int i = 0; i < 10; i++) {
        delete points[i];
    }
    delete[] points;
    return 0;
}
/*
1 1 2
2 2 3
3 2 1
-1 -1 0
4 5 6
2 3 3
6 7 8
3 4 5
9 8 0
1 4 14
*/
/// Задача 2
/*
#include <iostream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    char* name;
    char* accountNum;
    double balance;
public:
    BankAccount(const char* = "", const char* = "", double = 0.0);
    BankAccount(const BankAccount&);
    BankAccount& operator=(const BankAccount&);
    ~BankAccount();

    void showBankAccount() const;
    void putCash(double);
    void withdraw(double);
};

BankAccount::BankAccount(const char* name, const char* accountNum, double balance) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->accountNum = new char[strlen(accountNum) + 1];
    strcpy(this->accountNum, accountNum);
    this->balance = balance;
}

BankAccount::BankAccount(const BankAccount& bankAccount) {
    this->name = new char[strlen(bankAccount.name) + 1];
    strcpy(this->name, bankAccount.name);
    this->accountNum = new char[strlen(bankAccount.accountNum) + 1];
    strcpy(this->accountNum, bankAccount.accountNum);
    this->balance = bankAccount.balance;
}

BankAccount& BankAccount::operator=(const BankAccount& other) {
    if (this != &other) {
        delete[] name;
        delete[] accountNum;

        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->accountNum = new char[strlen(other.accountNum) + 1];
        strcpy(this->accountNum, other.accountNum);
        this->balance = other.balance;
    }
}

BankAccount::~BankAccount() {
    delete[] name;
    delete[] accountNum;
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

    BankAccount otherAcccount;
    otherAcccount = bankAccount;
    otherAcccount.putCash(345.8);
    otherAcccount.showBankAccount();
    return 0;
}*/
/// Задачата от часа
/*#include <iostream>
using namespace std;

class IntArray {
private:
    int* arr;
    int num;
    bool isValid(int);
public:
    IntArray(int = 10);
    IntArray(const IntArray&);
    IntArray& operator=(const IntArray&);
    ~IntArray();

    bool set(int, int);
    bool get(int, int&);

    int linearSearch(int);
    void sort();
};

IntArray::IntArray(int size) {
    if (size <= 0) {
        return;
    }
    num = size;
    arr = new int[num];
    for (int i = 0; i < num; i++) {
        arr[i] = 0;
    }
}

IntArray::IntArray(const IntArray& other) {
    num = other.num;
    arr = new int[num];
    for (int i = 0; i < num; i++) {
        arr[i] = other.arr[i];
    }
}

IntArray& IntArray::operator=(const IntArray& other) {
    if (this != &other) {
        delete[] arr;
        num = other.num;
        arr = new int[num];
        for (int i = 0; i < num; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

IntArray::~IntArray() {
    delete[] arr;
}

bool IntArray::isValid(int position) {
    return position >= 0 && position < num;
}

bool IntArray::set(int position, int value) {
    if (isValid(position)) {
        arr[position] = value;
        return true;
    }
    return false;
}

bool IntArray::get(int position, int& value) {
    if (isValid(position)) {
        value = arr[position];
        return true;
    }
    return false;
}

int IntArray::linearSearch(int elem) {
    for (int i = 0; i < num; i++) {
        if (arr[i] == elem) {
            return i;
        }
    }
    return num;
}

void IntArray::sort() {
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    IntArray arr(20);
    for (int i = 0; i < 20; i++) {
        arr.set(i, i);
    }
    IntArray otherArr;
    otherArr = arr;
    otherArr.set(10, 150);
    for (int i = -5; i < 15; i++) {
        cout << otherArr.linearSearch(i) << endl;
    }
    cout << endl;
    for (int i = -5; i < 15; i++) {
        cout << arr.linearSearch(i) << endl;
    }
    cout << endl;
    return 0;
}*/
