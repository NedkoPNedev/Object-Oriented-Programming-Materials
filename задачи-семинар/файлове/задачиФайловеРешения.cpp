/*/// Задача 1
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream iFile("letters.txt");
    iFile.seekg(0, ios::end);
    iFile.seekg(6, ios::beg);
    char ch;
    iFile.get(ch);
    cout << ch << endl;
    iFile.seekg(-6, ios::end);
    iFile.get(ch);
    cout << ch << endl;
    iFile.seekg(3, ios::cur);
    iFile.get(ch);
    cout << ch << endl;
    iFile.seekg(0, ios::end);
    cout << iFile.tellg() << endl;
    iFile.close();
    return 0;
}
*/
/// Задача 2
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int facNum;
    char firstName[50];
    char lastName[50];
    double score;

    bool operator>(const Student&);
};

bool Student::operator>(const Student& other) {
    return score > other.score;
}

ostream& operator<<(ostream& os, Student& student) {
    os << student.facNum << " " << student.firstName << " " << student.lastName << " " << student.score;
    return os;
}

void fillData() {
    Student students[3] = {{1234, "Иван", "Петров", 5.25},
                            {1001, "Мария", "Иванова", 6.00},
                            {2345, "Стефан", "Стефанов", 4.30}};
    ofstream oFile("students.bin", ios::out|ios::binary);
    for (int i = 0; i < 3; i++) {
        oFile.write((char*)&students[i], sizeof(Student));
    }
    oFile.close();
}

void sortStudents(Student* students, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (students[i] > students[j]) {
                swap(students[i], students[j]);
            }
        }
    }
}

int main() {
    fillData();
    Student students[100];
    int num = 0;
    ifstream iFile("students.bin", ios::binary);
    while (!iFile.eof()) {
        iFile.read((char*)&students[num], sizeof(Student));
        num++;
    }
    num--;
    iFile.close();
    sortStudents(students, num);
    ofstream oFile("sortedStudents.txt");
    for (int i = 0; i < num; i++) {
        cout << students[i] << endl;
        oFile << students[i] << endl;
    }
    oFile.close();
    return 0;
}
