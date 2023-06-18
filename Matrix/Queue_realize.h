#pragma once
#include "Queue.h"

template<class T>
void Queue<T>::Add(T element)
{
	if (!IsFull())
		Wait[QueueLength++] = element;
}
template<class T>
T Queue<T>::Extract()
{
	if (!IsEmpty())
	{
		auto temp = Wait[0];
		for (size_t i{ 1 }; i < QueueLength; ++i)
			Wait[i - 1] = Wait[i];
		--QueueLength;
		return temp;
	}
	else
		return T();
}
template<class T>
void Queue<T>::Show()
{
	for (int i{}; i < QueueLength; ++i)
		std::cout << Wait[i] << " ";
}
//
//int QueueRing::Extract()
//{
//	if (!IsEmpty())
//	{
//		auto temp = Wait[0];
//		for (int i{ 1 }; i < QueueLength; ++i)
//			Wait[i - 1] = Wait[i];
//		Wait[QueueLength-1] = temp;
//		return temp;
//	}
//	else
//		return -1;
//}

//void QueuePriority::Add(int c, int p)
//{
//	if (!IsFull())
//	{
//		Wait[QueueLength] = c;
//		Priority[QueueLength] = p;
//		++QueueLength;
//	}
//}
//
//int QueuePriority::Extract()
//{
//	if (!IsEmpty())
//	{
//		auto max_pri_ind = 0;
//		for (int i{}; i < QueueLength; ++i)
//			if (Priority[i] > Priority[max_pri_ind])
//				max_pri_ind = i;
//		auto temp1 = Wait[max_pri_ind];
//
//		for (int i{ max_pri_ind + 1}; i < QueueLength; ++i)
//		{
//			Wait[i - 1] = Wait[i];
//			Priority[i - 1] = Priority[i];
//		}
//
//		return temp1;
//	}
//	else
//		return -1;
//}
//
//void QueuePriority::Show()
//{
//	for (int i{}; i < QueueLength; ++i)
//		std::cout << Wait[i] << "-" << Priority[i] << " ";
//}