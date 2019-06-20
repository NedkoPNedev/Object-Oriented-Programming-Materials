#include <iostream>
using namespace std;

class A {
private:
    int a;
public:
    A(int _a) : a(_a) {
        cout << "constructor - A()\n";
    }
    A(const A& other) : a(other.a) {
        cout << "copy constructor - A()\n";
    }
    A& operator=(const A& other) {
        if (this != &other) {
            a = other.a;
            cout << "operator = A()\n";
        }
        return *this;
    }
};

class B : virtual public A {
private:
   char b;
public:
    B(char _b, int _a) : A(_a), b(_b) {
        cout << "constructor - B()\n";
    }
    B(const B& other) : A(other), b(other.b) {
        cout << "copy constructor - B()\n";
    }
    B& operator=(const B& other) {
        if (this != &other) {
           A::operator=(other);
           b = other.b;
           cout << "operator = B()\n";
        }
        return *this;
    }
};

class C : virtual public A {
private:
   double c;
public:
    C(double _c, int _a) : A(_a), c(_c) {
        cout << "constructor - C()\n";
    }
    C(const C& other) : A(other), c(other.c) {
        cout << "copy constructor - C()\n";
    }
    C& operator=(const C& other) {
        if (this != &other) {
           A::operator=(other);
           c = other.c;
           cout << "operator = C()\n";
        }
        return *this;
    }
};

class D : public B, public C {
public:
    D(int _a, char _b, double _c) : A(_a), B(_b, _a), C(_c, _a) {
        cout << "constructor - D()\n";
    }
    D(const D& other) : A(other), B(other), C(other) {
        cout << "copy constuctor - D()\n";
    }
    D& operator=(const D& other) {
        if (this != &other) {
            B::operator=(other);
            C::operator=(other);
            cout << "operator= D()\n";
        }
        return *this;
    }
};

int main() {
    int a = 5;
    char b = 'b';
    double c = 3.14;
    D d(a, b, c);
    cout << endl;
    D d1 = d;
    cout << endl;
    d1 = d;
}
