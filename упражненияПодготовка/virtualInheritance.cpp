#include <iostream>
using namespace std;

class Animal {
public:
    void show() {
        cout << "vse taq\n";
    }
	Animal() {
        cout << "constructor in Animal class\n";
	}
};

class Lion : virtual public Animal {
public:
	Lion() {
         cout << "constructor in Lion class\n";
	}
};

class Tiger : virtual public Animal {
public:
	Tiger() {
         cout << "constructor in Tiger class\n";
	}
};

class Liger : public Lion, public Tiger {
public:
	Liger() {
         cout << "constructor in Liger class\n";
	}
};

int main() {
	Liger lg;
    lg.show();
	return 0;
}
