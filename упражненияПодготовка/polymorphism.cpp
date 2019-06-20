#include <iostream>
using namespace std;

class Animal {
public:
    virtual void breathe() const = 0;
};


class Mammal : public Animal {
public:
    void breathe() const {
        cout << "I breathe as a Mammal\n";
    }
};

class Reptile : public Animal {
public:
    void breathe() const {
        cout << "I breathe as a Reptile\n";
    }
};

int main() {
    Reptile b;
    Animal* a = &b;
    a->breathe();
	return 0;
}
