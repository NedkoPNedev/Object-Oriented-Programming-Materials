#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Athlete {
private:
    char* name;
    int height;
    void copyAthlete(const char*, int);
public:
    Athlete(const char* = "", int = 0);
    Athlete(const Athlete&);
    Athlete& operator=(const Athlete&);
    ~Athlete();

    int getHeight() const { return height; }

    friend ostream& operator<<(ostream&, const Athlete&);
    bool operator==(const Athlete&);
};

Athlete::Athlete(const char* name, int height) :
    height(height){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Athlete::Athlete(const Athlete& other) :
    height(other.height) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}

Athlete& Athlete::operator=(const Athlete& other) {
    if (this != &other) {
        delete[] name;
        height = other.height;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
    }
    return *this;
}

Athlete::~Athlete() {
    delete[] name;
}

ostream& operator<<(ostream& os, const Athlete& ath) {
    os << "Name : " << ath.name << " height : " <<
        ath.height << endl;
    return os;
}

bool Athlete::operator==(const Athlete& other) {
    return (!strcmp(name, other.name)) &&
        height == other.height;
}

class AthletesList {
private:
    Athlete* arr;
    int cap;
    int curr;
public:
    AthletesList(int);
    AthletesList(const AthletesList&);
    AthletesList& operator=(const AthletesList&);
    ~AthletesList();

    bool addAthlete(const Athlete&);
    bool isPresent(const Athlete&);
    void print(const char* fileName);
};

AthletesList::AthletesList(int cap) : cap(cap) {
    curr = 0;
    arr = new Athlete[cap];
}

AthletesList::AthletesList(const AthletesList& other) :
    cap(other.cap), curr(other.curr){

    arr = new Athlete[cap];
    for (int i = 0; i < curr; i++) {
        arr[i] = other.arr[i];
    }
}

AthletesList& AthletesList::operator=
            (const AthletesList& other) {
    if (this != &other) {
        delete[] arr;
        cap = other.cap;
        curr = other.curr;
        arr = new Athlete[cap];
        for (int i = 0; i < curr; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

AthletesList::~AthletesList() {
    delete[] arr;
}

bool AthletesList::addAthlete(const Athlete& ath) {
    if (curr >= cap) {
        return false;
    }
    arr[curr] = ath;
    curr++;
    return true;
}

bool AthletesList::isPresent(const Athlete& ath) {
    for (int i = 0; i < curr; i++) {
        if (arr[i] == ath) {
            return true;
        }
    }
    return false;
}

void AthletesList::print(const char* fileName) {
    ofstream oFile(fileName);
    for (int i = 0; i < curr; i++) {
        for (int j = i + 1; j < curr; j++) {
            if (arr[i].getHeight() > arr[j].getHeight()) {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < curr; i++) {
        oFile << arr[i] << endl;
    }
    oFile.close();
}

int main() {
    Athlete gosho("Gosho", 192);
    Athlete pesho("Pesho", 196);
    Athlete sasho("Sasho", 188);

    AthletesList arr(5);
    arr.addAthlete(gosho);
    arr.addAthlete(pesho);
    arr.addAthlete(sasho);

    arr.print("athletes.txt");
    cout << arr.isPresent(sasho) << endl;
}



