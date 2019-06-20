#include<iostream>
#include"livePerformance.hpp"
#include"feelings.hpp"

using namespace std;

int main()
{
	LivePerformance<int> lp("lala");
	Ticket<int> t(3, "lala", 5);
	GroupTicket<int> t1(2, "lala", 5, 4);
	Ticket<int> ts[5];
	ts[0] = t;
	ts[1] = t1;
	addSpectators(lp, ts, 3);
	lp.makeFeelingsPoll();

	return 0;
}
