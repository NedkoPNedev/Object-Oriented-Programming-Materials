#ifndef _GROUP_TICKET_H
#define _GROUP_TOCKET_H
#include"ticket.hpp"

template <typename T>
class GroupTicket :public Ticket<T> {
private:
	int places;
public:
	GroupTicket(const T&, const char*, const double, const int);
	GroupTicket(const GroupTicket<T>&);
	GroupTicket<T>& operator=(const GroupTicket<T>&);
	~GroupTicket() {};
	int getPlaces()const;
};

template <typename T>
GroupTicket<T>::GroupTicket(const T& _id = T(), const char* _title = "\n", const double _price = 0, const int _places = 1) :
	Ticket<T>(_id, _title, (_price - _places > 0 ? _price - _places : 0)) {
	places = _places;
}
template <typename T>
GroupTicket<T>::GroupTicket(const GroupTicket& other) : Ticket<T>(other) {
	places = other.places;
}

template <typename T>
GroupTicket<T>& GroupTicket<T>::operator=(const GroupTicket<T>& other) {
	if (this != &other) {
		Ticket<T>::operator=(other);
		places = other.places;
	}
	return *this;
}

template <typename T>
int GroupTicket<T>::getPlaces() const {
	return places;
}





#endif // _GROUP_TICKET_H


