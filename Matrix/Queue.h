#pragma once
#include <iostream>

template<class T>
class Queue
{
protected:
	T* Wait;
	size_t MaxQueueLength;
	size_t QueueLength;

public:
	Queue(size_t size) :Wait{ new size_t[size] {} }, MaxQueueLength{ size }, QueueLength{ 0 } {};
	~Queue() { delete[] Wait; MaxQueueLength = 0; QueueLength = 0; }
	void Add(T element);
	T Extract();
	void Clear() { QueueLength = 0; }
	bool IsEmpty() { return !QueueLength; }
	bool IsFull() { return QueueLength == MaxQueueLength; }
	int GetCount() { return QueueLength; }
	void Show();
};

#include "Queue_realize.h"
//class QueueRing : public Queue
//{
//public:
//	QueueRing(int m) : Queue(m) {}
//	int Extract();
//};
//
//class QueuePriority: public Queue
//{
//private:
//	int* Priority;
//
//public:
//	QueuePriority(int m) :Queue(m) { Priority = new int[m] {}; }
//	~QueuePriority() { delete[] Priority; }
//	void Add(int c, int p);
//	void Add(int c) = delete;
//	int Extract();
//	void Show();
//};

