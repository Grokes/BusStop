#pragma once
#include "Queue.h"
#include <vector>

class BusStop
{
private:
	const size_t capacity{ 20 };
	Queue<size_t> people_queue;
	size_t people_time;
	size_t bus_time;
	bool end;

public:
	BusStop(size_t capacity, size_t people_time, size_t bus_time, bool type) :capacity{capacity},
															people_time { people_time },
															bus_time{ bus_time }, 
															end{type}, 
															people_queue(capacity) {}
	void Start();
};

