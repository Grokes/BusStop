#pragma once
class Stack
{
	enum { EMPTY = -1, FULL = 20 };
	char stack[FULL + 1];
	int top;

public:
	Stack() :top{ EMPTY } {};
	void Push(char c);
	char Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
};

