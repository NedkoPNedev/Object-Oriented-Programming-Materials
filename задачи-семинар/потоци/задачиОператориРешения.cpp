/// Задача 2
/*
#include <iostream>
using namespace std;

struct Gcd {
    int a, b;
    int getGcd();
};

int Gcd::getGcd() {
    int a1 = a, b1 = b, c;
    while (b1 > 0) {
        c = a1 % b1;
        a1 = b1;
        b1 = c;
    }
    return a1;
}

istream& operator>>(istream& is, Gcd& t) {
    do {
        is >> t.a >> t.b;
    } while(t.a < 0 || t.b < 0 || (t.a == 0 && t.b == 0));
    return is;
}

ostream& operator<<(ostream& os, Gcd& t) {
    os << "gcd of " << t.a << " and " << t.b << " is : " << t.getGcd();
    return os;
}

int main() {
    Gcd t;
    cin >> t;
    cout << t << endl;
    return 0;
}*/
