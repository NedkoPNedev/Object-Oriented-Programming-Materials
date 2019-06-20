/// Задача 6
/*#include<iostream>
#include <string.h>
using namespace std;

enum color { brown, green, orange, red, yellow };
enum yn { yes, no };

struct Fruit {
    char name[32];
    color cl;
    yn annual;
    yn perennial;
    yn tropical;
};

void printFruits(Fruit* fruits, int num) {
     for (int i = 0; i < num; i++) {
        cout << fruits[i].name << " " << fruits[i].cl << " " <<
        fruits[i].annual << " " << fruits[i].perennial << " " << fruits[i].tropical << endl;
    }
    cout << endl;
}

void printSortedAnnualFruitsOfColor(Fruit* fruits, int num, color cl) {
    Fruit* annuals = new Fruit[num];
    int numAnnuals = 0;

    for (int i = 0; i < num; i++) {
        if (fruits[i].annual == yes && fruits[i].cl == cl) {
            annuals[numAnnuals++] = fruits[i];
        }
    }

    for (int i = 0; i < numAnnuals; i++) {
        for (int j = i + 1; j < numAnnuals; j++) {
            if (strcmp(annuals[i].name, annuals[j].name) > 0) {
                swap(annuals[i], annuals[j]);
            }
        }
    }

    printFruits(annuals, numAnnuals);

    delete[] annuals;
}

void printSortedPerenialTropicalFruitsOfColor(Fruit* fruits, int num, color cl) {
    Fruit* annuals = new Fruit[num];
    int numAnnuals = 0;

    for (int i = 0; i < num; i++) {
        if (fruits[i].perennial == yes && fruits[i].tropical == yes && fruits[i].cl == cl) {
            annuals[numAnnuals++] = fruits[i];
        }
    }

    for (int i = 0; i < numAnnuals; i++) {
        for (int j = i + 1; j < numAnnuals; j++) {
            if (strcmp(annuals[i].name, annuals[j].name) > 0) {
                swap(annuals[i], annuals[j]);
            }
        }
    }

    printFruits(annuals, numAnnuals);

    delete[] annuals;
}

int main() {
    Fruit fruits[6] = {{"banana", yellow, no, yes, no},
                    {"mango", red, yes, no, yes},
                    {"papaya", orange, no, yes, yes},
                    {"apple", green, yes, no, no},
                    {"kiwi", green, yes, no, no},
                    {"orange", orange, no, yes, yes}};

    printFruits(fruits, 6);

    printSortedAnnualFruitsOfColor(fruits, 6, green);

    printSortedPerenialTropicalFruitsOfColor(fruits, 6, orange);

    return 0;
}*/
/// Задача 7
/*
#include <iostream>
#include <string.h>
using namespace std;

struct Planet {
    char name[32];
    double distance;
    double diameter;
    double weight;
};

void sortPlanetsByDistanceAndDiameter(Planet** planetsPtrArray, int num) {
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (planetsPtrArray[i]->distance < planetsPtrArray[j]->distance ||
                (planetsPtrArray[i]->distance == planetsPtrArray[j]->distance &&
                 planetsPtrArray[i]->diameter < planetsPtrArray[j]->diameter)) {
                    swap(planetsPtrArray[i], planetsPtrArray[j]);
                 }
        }
    }
}

void printPlanetsInfo(Planet** planetsPtrArray, int num) {
    for (int i = 0; i < num; i++) {
        cout << planetsPtrArray[i]->name << " " << planetsPtrArray[i]->distance << " "
            << planetsPtrArray[i]->diameter << " " << planetsPtrArray[i]->weight << endl;
    }
}

int main() {
    Planet mercury = {"mercury", 57910000, 4880, 3.285};
    Planet venus = {"venus", 108200000, 12104, 48.67};
    Planet earth = {"earth", 149600000, 12742, 59.72};

    Planet* planetsPtrArray[3] = {&mercury, &venus, &earth};

    sortPlanetsByDistanceAndDiameter(planetsPtrArray, 3);

    printPlanetsInfo(planetsPtrArray, 3);

    return 0;
}*/
/// Задача 8
#include <iostream>
using namespace std;

struct Vector {
private:
    int x1, x2, x3;

public:
    void createVector(int, int, int);
    void showVector() const;
    Vector getSumOfVectors(const Vector&);
    Vector getDiffOfVectors(const Vector&);
    Vector getProductWithScalar(const int);
    int getDotProduct(const Vector&);
};

void Vector::createVector(int a, int b, int c) {
    x1 = a;
    x2 = b;
    x3 = c;
}

void Vector::showVector() const {
    cout << x1 << " " << x2 << " " << x3 << endl;
}

Vector Vector::getSumOfVectors(const Vector& other) {
    Vector newVector;
    newVector.createVector(x1 + other.x1, x2 + other.x2, x3 + other.x3);
    return newVector;
}

Vector Vector::getDiffOfVectors(const Vector& other) {
    Vector newVector;
    newVector.createVector(x1 - other.x1, x2 - other.x2, x3 - other.x3);
    return newVector;
}

Vector Vector::getProductWithScalar(const int num) {
    Vector newVector;
    newVector.createVector(x1 * num, x2 * num, x3 * num);
    return newVector;
}

int Vector::getDotProduct(const Vector& other) {
    return x1 * other.x1 + x2 * other.x2 + x3 * other.x3;
}

int main() {
    Vector vec1, vec2;
    vec1.createVector(3, 4, 5);
    vec2.createVector(1, 8, 4);

    vec1.getSumOfVectors(vec2).showVector();
    vec1.getDiffOfVectors(vec2).showVector();
    vec1.getProductWithScalar(3).showVector();
    cout << vec1.getDotProduct(vec2) << endl;
    return 0;
}
