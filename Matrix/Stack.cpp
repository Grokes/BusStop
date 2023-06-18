#include "Stack.h"
void Stack::Push(char c)
{
	if(!IsFull())
		stack[++top] = c;
}

char Stack::Pop()
{
	if (!IsEmpty())
		return stack[--top];
	else
		return 0;
}

void Stack::Clear()
{
	top == EMPTY;
}

bool Stack::IsEmpty()
{
	return top == EMPTY;
}

bool Stack::IsFull()
{
	return top == FULL;
}

int Stack::GetCount()
{
	return top + 1;
}