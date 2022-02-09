//stack.cpp -- Stack member function
#include"header/stack.h"

Stack::Stack()
{
	top = 0;
	items;
}

bool Stack::isempty()const
{
	return top == 0;
}

bool Stack::isfull()const
{
	return top == MAX;
}

bool Stack::push(Item& item)
{
	if (top<MAX)
	{
		items[top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

bool Stack::pop(Item& item)
{
	if (top>0)
	{
		item = items[--top];
		return true;
	}
	else
	{
		return false;
	}
}