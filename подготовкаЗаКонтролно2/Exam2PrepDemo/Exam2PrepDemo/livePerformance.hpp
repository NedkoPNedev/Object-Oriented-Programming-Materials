#ifndef _PERFORMANCE_H
#define _PERFORMANCE_H
#include"spectator.hpp"
#include"feelings.hpp"

template <typename T>
class LivePerformance {
private:
	char performer[101];
	Spectator<T> spectators[128];
	int spectatorsSize;
	Happiness happiness;
	Sadness sadness;
	Love love;
public:
	LivePerformance(const char*);
	void addSpectators(const Spectator<T>&);
	void addSpectators(const Spectator<T>*, const int);
	void getFeelingsRate()const;
	void makeFeelingsPoll();
};

template <typename T>
LivePerformance<T>::LivePerformance(const char* _performer) {
	strcpy(performer, _performer);
	spectatorsSize = 0;
	happiness.setRate(0.5);
	sadness.setRate(0.5);
	love.setRate(0.5);
}

template <typename T>
void LivePerformance<T>::addSpectators(const Spectator<T>& _spectator) {
	spectators[spectatorsSize++] = _spectator;
}

template <typename T>
void LivePerformance<T>::addSpectators(const Spectator<T>* _spectators, const int _spectatorsSize) {
	for (int i = 0; i < _spectatorsSize; i++) {
		spectators[spectatorsSize++] = _spectators[i];
	}
}

template <typename T>
void LivePerformance<T>::getFeelingsRate() const {
	happiness.print();
	sadness.print();
	love.print();
}

template <typename T>
void LivePerformance<T>::makeFeelingsPoll() {
	for (int i = 0; i < spectatorsSize; i++) {
		happiness.setRate((happiness.getRate() + spectators[i].rateFeeling()) / 2);
		sadness.setRate((sadness.getRate() + spectators[i].rateFeeling()) / 2);
		love.setRate((love.getRate() + spectators[i].rateFeeling()) / 2);
	}
	getFeelingsRate();
}


template <typename T>
void addSpectators(LivePerformance<T>& performance, const Ticket<T>* tickets, const int n) {
	for (int i = 0; i < n; i++) {
		if (tickets[i].getPlaces() == 1) {
			Spectator<T> s(&tickets[i]);
			performance.addSpectators(s);
		}
		else {
			Spectator<T>* s = new Spectator<T>[tickets[i].getPlaces()];
			Spectator<T> s1(&tickets[i]);
			s[0] = s1;
			performance.addSpectators(s, tickets[i].getPlaces());
		}
	}
}

#endif // _PERFORMANCE_H
