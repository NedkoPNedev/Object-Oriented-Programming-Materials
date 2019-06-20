/// Задача 1
/*
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int = 0, int = 1);
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    bool isFraction_1() const { return numerator % denominator != 0; }

    friend bool isFraction_2(const Fraction&);
};

Fraction::Fraction(int n, int d) : numerator(n), denominator(d) {
}

bool isFraction_2(const Fraction& fraction) {
    return fraction.numerator % fraction.denominator != 0;
}

bool isFraction_3(const Fraction& fraction) {
    return fraction.getNumerator() % fraction.getDenominator() != 0;
}

int main() {
    Fraction fraction(5, 3);
    cout << fraction.isFraction_1() << " " << isFraction_2(fraction) << " " << isFraction_3(fraction) << endl;
    return 0;
}
*/

/// Задача 2
/*
#include <iostream>
using namespace std;

template <typename T>
struct Elem {
	T data;
	Elem<T>* next;
};

template <typename T>
class Stack {
private:
	Elem<T>* start;
	void deleteStack();
	void copyStack(const Stack<T>&);
public:
	Stack();
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	~Stack();

	void push(const T&);
	void pop(T&);
	bool empty() const { return start == NULL; }
	void print();
};

template <typename T>
void Stack<T>::deleteStack() {
	Elem<T>* ptr;
	while (start) {
		ptr = start;
		start = start->next;
		delete ptr;
	}
}

template <typename T>
void Stack<T>::copyStack(const Stack<T>& other) {
	if (other.start == NULL) {
		start = NULL;
		return;
	}
	start = new Elem<T>;
	start->data = other.start->data;
	start->next = NULL;
	Elem<T>* currPtr = start;
	Elem<T>* otherPtr = other.start->next;
	while (otherPtr) {
		Elem<T>* tempPtr = new Elem<T>;
		tempPtr->data = otherPtr->data;
		tempPtr->next = NULL;
		currPtr->next = tempPtr;
		currPtr = currPtr->next;
		otherPtr = otherPtr->next;
	}
}

template <typename T>
Stack<T>::Stack() : start(NULL) {
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
	copyStack(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
	if (this != &other) {
		deleteStack();
		copyStack(other);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack() {
	deleteStack();
}

template <typename T>
void Stack<T>::push(const T& value) {
	Elem<T>* newElemPtr = new Elem<T>;
	newElemPtr->data = value;
	newElemPtr->next = start;
	start = newElemPtr;
}

template <typename T>
void Stack<T>::pop(T& value) {
	if (empty()) {
		return;
	}
	Elem<T>* ptr = start;
	value = ptr->data;
	start = start->next;
	delete ptr;
}

template <typename T>
void Stack<T>::print() {
	T val;
	Elem<T>* ptr = start;
	while (!empty()) {
		pop(val);
		cout << val << " ";
	}
	cout << endl;
}

int main() {
	Stack<int> st;
	for (int i = 0; i < 10; i++) st.push(i);
	Stack<int> st2 = st;
	int a;
	st2.pop(a);
	st2.pop(a);
	st2.print();
	system("pause");
	return 0;
}*/

/// Задача 3
#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    void simplify();
public:
    Time(int = 0, int = 0);
    void reset(int = 0, int = 0);
    void addMin(int);
    void addHours(int);

    operator int() const;
    Time operator+(const Time&);
    Time operator-(const Time&);
    Time operator*(int);
    friend Time operator*(int mult, const Time& time);

    void print() const;
};

void Time::simplify() {
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes = minutes % 60;
    }
}

Time::Time(int h, int m){
    reset(h, m);
}

void Time::reset(int h, int m) {
    hours = h;
    minutes = m;
    simplify();
}

void Time::addMin(int mins) {
    minutes += mins;
    simplify();
}

void Time::addHours(int hours) {
    this->hours = hours;
}

Time::operator int() const {
    return hours * 60 + minutes;
}

Time Time::operator+(const Time& other) {
    Time t;
    t.minutes = minutes + other.minutes;
    t.hours = hours + other.hours;
    t.simplify();
    return t;
}

Time Time::operator-(const Time& other) {
    Time t;
    int mins = (int)(*this) - (int)other;
    t.minutes = mins % 60;
    t.hours = mins / 60;
    t.simplify();
    return t;
}

Time Time::operator*(int mult) {
    Time t;
    int mins = (int)(*this) * mult;
    t.minutes = mins % 60;
    t.hours = mins / 60;
    return t;
}

Time operator*(int mult, const Time& time) {
    Time t;
    int mins = (int)time * mult;
    t.minutes = mins % 60;
    t.hours = mins / 60;
    return t;
}

void Time::print() const {
    cout << "hours : " << hours << " " << "minutes : " << minutes << endl;
}

int main() {
    Time t1, t2(0, 12);
    t1.print();
    t2.print();
    Time t3 = t2;
    t3.print();
    t3.addMin(105);
    t3.print();
    t2.addHours(6);
    t2.print();
    t1 = t2 + t3;
    t1.print();
    t1 = t2 - t3;
    t1.print();
    t1 = t1 * 2;
    t1.print();
    (6*t1).print();
    cout << t1 << endl;
    return 0;
}
