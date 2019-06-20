/// Задача 1
/*#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int cnt = 0;
    int sum = 0;
    int number;
    cin >> number;
    while (cin.good()) {
        sum += number;
        cnt++;
        cin >> number;
    }
    cout << cin.good() << " " << cin.eof() << " " << cin.fail() << " " << cin.bad() << endl;

    if (cnt > 0) {
        cout << fixed << setprecision(3) << (double)sum / cnt << endl;
    } else {
        cout << "There aren't any numbers!\n";
    }
    return 0;
}*/
///Задача 2
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    double s = 5.6;
    int a = 7;
    char str[10] = "sample";
    ofstream oFile("file.txt");
    oFile << s << " " << a << " " << str << endl;
    oFile.close();
    ifstream iFile("file.txt");
    iFile.seekg(0, ios::end);
    cout << "file size : " << iFile.tellg() << " bytes" << endl;
    iFile.seekg(0, ios::beg);
    double newS;
    int newA;
    char newStr[10];
    iFile >> newS >> newA >> newStr;
    cout << newS << " " << newA << " " << newStr << endl;
    iFile.close();
    return 0;
}*/
/// Задача 3
/*
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    int histogram[256] = {0};
    int total = 0;
    char ch;
    ifstream iFile;
    iFile.open("test.txt");
    while (!iFile.eof()) {
        iFile.get(ch);
        histogram[(int)ch]++;
        total++;
    }
    iFile.close();
    for (int i = 0; i <= 255; i++) {
        if (histogram[i] > 0) {
            cout << '\'' << (char) i << '\'' << " - " << fixed << setprecision(2) << (double)(histogram[i] * 100) / total << " % \n";
        }
    }
}*/
/// Задача 4
#include <iostream>
#include <iomanip>
using namespace std;

const int ERROR_CODE = 99;

int getIntFromChar(char ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'a' && ch <= 'f') return 10 + ch - 'a';
    if (ch >= 'A' && ch <= 'F') return 10 + ch - 'A';
    return ERROR_CODE;
}

int detectBase(istream& is) {
    char zero;
    is.get(zero);
    if (zero == '0') {
        char x;
        is.get(x);
        if (x == 'x') return 16;
        else {
            is.putback(x);
            return 8;
        }
    }
    is.putback(zero);
    return 10;
}

int getNumber(istream& is, int base) {
    int number = 0;
    char ch;
    is.get(ch);
    while (getIntFromChar(ch) != ERROR_CODE) {
        number *= base;
        number += getIntFromChar(ch);
        is.get(ch);
    }
    return number;
}

void printNumberOtherBases(int base, int number) {
    if (base != 8) {
        cout << "Octal : " << setiosflags(ios::showbase) << oct << number << endl;
    }
    if (base != 10) {
        cout << "Decimal : " << dec << number << endl;
    }
    if (base != 16) {
        cout << "Hexadecimal : " << setiosflags(ios::showbase) << hex << number << endl;
    }
}

int main() {
    int base = detectBase(cin);
    cout << "Base of input number is : " << base << endl;
    int number = getNumber(cin, base);
    printNumberOtherBases(base, number);
    return 0;
}
