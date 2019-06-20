#include <iostream>
using namespace std;

class A {
public:
    static int counter;
};

int A::counter = 10;

class Base {
public:
    Base() {
        counter++;
    }
    ~Base() {
        counter--;
    }
    static int counter;
};

int Base::counter = 0;

class Der : public Base {
public:
    Der() {
        counter++;
    }
};

class TestClass {
private:
    int nonStat;
public:
    void test() const {
        stat++;
        nonStat++;
    }
    static int stat;
};

int TestClass::stat = 0;

class Broken {
private:
    int temp;
    static int staticTemp;
public:
    static int setTemp(int tempData) {
        cout << temp << endl;
        temp = tempData;
    }
    static int getTemp() const {
        return staticTemp;
    }
};

int Broken::staticTemp = 42;

class Fixed {
private:
    int temp;
public:
    static int setTemp(Fixed* obj, int val) {
        obj->temp = val;
    }
    int getTemp() const {
        return temp;
    }
};

class Vehicle {
public:
    static void show() {
        cout << "I'm a vehicle!\n";
    }
};

class Car : public Vehicle {
public:
    static void show() {
        Vehicle::show();
        cout << "I'm a vehicle and more specifically a car!\n";
    }
};

int main() {
    /// Example 1
    /*A a, b, c;
    cout << &a.counter << " " << &b.counter << endl;
    cout << a.counter << " " << b.counter << endl;
    a.counter++;
    b.counter++;
    cout << a.counter << " " << b.counter << endl;
    A::counter++;
    cout << a.counter << " " << b.counter << endl;*/


    /// Example 2
    /*Base a;
    cout << a.counter << endl;
    Der b;
    cout << a.counter << " " << b.counter << endl;*/


    /// Example 3
    /*TestClass foo;
    foo.test();
    cout << foo.stat << endl;*/

    /// Example 4
    /*Fixed fs;
    Fixed::setTemp(&fs, 5);
    cout << fs.getTemp() << endl;
    fs.setTemp(&fs, 6);
    cout << fs.getTemp() << endl;*/

    /// Example 5
    /*Vehicle::show();
    cout << endl;
    Car::show();*/
}
