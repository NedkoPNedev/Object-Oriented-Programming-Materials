#ifndef _TICKET_H
#define _TOCKET_H
#include<cstring>

template <typename T>
class Ticket {
private:
	T id;
	char* title;
	double price;
	void copyTicket(const Ticket<T>&);
public:
	Ticket(const T&, const char*, const double);
	Ticket(const Ticket<T>&);
	Ticket<T>& operator=(const Ticket<T>&);
	~Ticket();
	virtual int getPlaces()const;
	double getPrice()const;
};

template <typename T>
void Ticket<T>::copyTicket(const Ticket<T>& other) {
	id = other.id;
	title = new char[strlen(other.title)];
	strcpy(title, other.title);
	price = other.price;
}

template <typename T>
Ticket<T>::Ticket(const T& _id = T(), const char* _title = "\n", const double _price = 0) {
	id = _id;
	title = new char[strlen(_title)];
	strcpy(title, _title);
	price = _price;
}

template <typename T>
Ticket<T>::Ticket(const Ticket<T>& other) {
	copyTicket(other);
}

template <typename T>
Ticket<T>& Ticket<T>::operator=(const Ticket<T>& other) {
	if (this != &other) {
		delete[] title;
		copyTicket(other);
	}
	return *this;
}

template <typename T>
Ticket<T>::~Ticket() {
	delete[] title;
}

template <typename T>
int Ticket<T>::getPlaces()const {
	return 1;
}

template <typename T>
double Ticket<T>::getPrice()const {
	return price;
}

template <typename T>
double sumPrices(Ticket<T>** tickets, const int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += tickets[i]->getPrice()*tickets[i]->getPlaces();
	}
	return sum;
}

#endif // _TICKET_H

