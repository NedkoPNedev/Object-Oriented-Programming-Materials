/// Задача 1
/*#include <iostream>

using namespace std;

struct Product {

    char description[32];
    double cost;
    int productNumber;
};

int main() {

    Product product_1 = {"screw-driver", 5.50, 456 };
    Product product_2 = {"hammer", 8.20,  324};

    cout << product_1.description << " " << product_1.cost << " " << product_1.productNumber << endl;
    cout << product_2.description << " " << product_2.cost << " " << product_2.productNumber << endl;

    Product products[3] = {{"screw-driver", 5.50, 456 }, {"hammer", 8.20,  324}, {"socket", 7.75, 458}};

    for (int i = 0; i < 3; i++) {
         cout << products[i].description << " " << products[i].cost << " " << products[i].productNumber << endl;
    }
    return 0;
}*/

/// Задача 2
/*#include <iostream>
#include <cmath>

using namespace std;

struct Triangle {
    double a, b, c;
};

void createTriangle(Triangle& t) {
    bool validTriangle;
    do {
        cin >> t.a >> t.b >> t.c;
        validTriangle = (t.a > 0) && (t.b > 0) && (t.c > 0) && (t.a + t.b > t.c) &&
        (t.b + t.c > t.a) && (t.a + t.c > t.b);
    } while(!validTriangle);
}

void showTriangle(const Triangle& t) {
    cout << t.a << " " << t.b << " " << t.c << endl;
}

double getPerimeter(const Triangle& t) {
    return t.a + t.b + t.c;
}

double getArea(const Triangle& t) {
    double p = getPerimeter(t) / 2;
    return sqrt(p*(p - t.a)*(p - t.b)*(p - t.c));
}

int main() {
    Triangle t;
    createTriangle(t);
    showTriangle(t);
    cout << getPerimeter(t) << " " << getArea(t) << endl;
    return 0;
}*/

/// Задача 3
/*
#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

void createPoint(Point& a) {
    cin >> a.x >> a.y;
}

void showPoint(const Point& a) {
    cout << a.x << " " << a.y << endl;
}

double getSegmentDistance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

struct Triangle {
    Point a, b, c;
};

void createTriangle(Triangle& t) {
    createPoint(t.a);
    createPoint(t.b);
    createPoint(t.c);
}

void showTriangle(const Triangle& t) {
    showPoint(t.a);
    showPoint(t.b);
    showPoint(t.c);
}

double getPerimeter(const Triangle& t) {
    return getSegmentDistance(t.a, t.b) + getSegmentDistance(t.a, t.c) + getSegmentDistance(t.b, t.c);
}

double getArea(const Triangle& t) {
    double a = getSegmentDistance(t.a, t.b);
    double b = getSegmentDistance(t.a, t.c);
    double c = getSegmentDistance(t.b, t.c);
    double p = getPerimeter(t) / 2;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

int main() {
    Triangle t;
    createTriangle(t);
    showTriangle(t);
    cout << getPerimeter(t) << " " << getArea(t) << endl;
    return 0;
}
*/

/// Задача 4
/*#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double getSegmentDistance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double getMaxDistance(Point* points, int n) {
    double maxDistance = 0.0, currentDistance;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            currentDistance = getSegmentDistance(points[i], points[j]);
            if (currentDistance > maxDistance) {
                maxDistance = currentDistance;
            }
        }
    }
    return maxDistance;
}*/

/// Задача 5
/*#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

void sortPoints(Point* points, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].x < points[j].x || (points[i].x == points[j].x && points[i].y < points[j].y)) {
                swap(points[i], points[j]);
            }
        }
    }
}
*/

