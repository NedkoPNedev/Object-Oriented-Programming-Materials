#include <iostream>
using namespace std;

const double PI = 3.14159265;

class Figure {
private:
    double cx, cy;
public:
    Figure(double x, double y) : cx(x), cy(y) {}

    virtual void print() const;
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
};

/* тук не се пише virtual!*/void Figure::print() const {
    cout << cx << " " << cy << endl;
}

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double rad, double x, double y) : Figure(x, y), radius(rad) {}

    void print() const {
        Figure::print();
        cout << radius << endl;
    }

    double getArea() const {
        return PI * radius * radius;
    }

    double getPerimeter() const {
        return 2 * PI * radius;
    }
};

class Square : public Figure {
private:
    double side;
public:
    Square(double s, double x, double y) : Figure(x, y), side(s) {}

    void print() const {
        Figure::print();
        cout << side << endl;
    }

    double getArea() const {
        return side * side;
    }

    double getPerimeter() const {
        return 4.0 * side;
    }
};

class Rectangle : public Figure {
private:
    double width, height;
public:
    Rectangle(double w, double h, double x, double y) : Figure(x, y), width(w), height(h) {}

    void print() const {
        Figure::print();
        cout << width << " " << height << endl;
    }

    double getArea() const {
        return width * height;
    }

    double getPerimeter() const {
        return 2 * (width + height);
    }
};

int main() {
    int n, id;
    double x, y, a, b;
    cin >> n;
    Figure** figures = new Figure*[n];
    for (int i = 0; i < n; i++) {
        cin >> id;
        if (id == 0 || id == 1) {
            cin >> a >> x >> y;
            if (id == 0) figures[i] = new Circle(a, x, y);
            else figures[i] = new Square(a, x, y);
        } else {
            cin >> a >> b >> x >> y;
            figures[i] = new Rectangle(a, b, x, y);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (figures[i]->getArea() > figures[j]->getArea()) {
                swap(figures[i], figures[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        figures[i]->print();
        delete figures[i];
    }
    delete[] figures;
}


