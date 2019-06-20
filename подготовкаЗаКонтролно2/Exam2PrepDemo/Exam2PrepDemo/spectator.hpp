#ifndef _SPECTATOR_H
#define _SPECTATOR_H
#include"groupTicket.hpp"
#include<cstdlib>

template <typename T>
class Spectator {
private:
	Ticket<T>* ticket;
	void setTicket(const Ticket<T>*);
public:
	Spectator(const Ticket<T>*);
	Spectator(const Spectator<T>&);
	Spectator<T>& operator=(const Spectator<T>&);
	~Spectator();
	bool hasTicket()const;
	double rateFeeling()const;
};
template <typename T>
void Spectator<T>::setTicket(const Ticket<T>* _ticket) {
	if (_ticket)
		ticket = new Ticket<T>(*_ticket);
	else ticket = nullptr;
}

template <typename T>
Spectator<T>::Spectator(const Ticket<T>* _ticket = nullptr) {
	setTicket(_ticket);
}

template <typename T>
Spectator<T>::Spectator(const Spectator<T>& other) {
	setTicket(other.ticket);
}

template <typename T>
Spectator<T>& Spectator<T>::operator=(const Spectator<T>& other) {
	if (this != &other)
		setTicket(other.ticket);
	return *this;
}

template <typename T>
Spectator<T>::~Spectator() {
	if (ticket != nullptr)delete ticket;
}

template <typename T>
bool Spectator<T>::hasTicket()const {
	return (ticket != nullptr);
}

template <typename T>
double Spectator<T>::rateFeeling()const {
	return (double)(rand() % 100) / 100;
}




#endif // _PERFORMANCE_H

