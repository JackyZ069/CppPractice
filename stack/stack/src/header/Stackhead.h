#pragma once
#ifndef STACK_H
#define STACK_H

#include<iostream>

#define MAXSIZE 100
#define overflow -2
#define Status int
#define OK 1
#define ERROR 0


template<class SElemType>
class SqStack
{
public:
	SqStack();
	SqStack(SqStack& S);
	~SqStack();
	Status StackEmpty(SqStack& S);//判断栈空
	Status ClearStack(SqStack& S);//清空栈
	Status DestroyStack(SqStack& S);//销毁栈
	Status Push(SqStack& S,SElemType e);//入栈
	Status Pop(SqStack& S,SElemType& e);//出栈

public:
	SElemType* base;//栈底指针
	SElemType* top;//栈顶指针
	int stacksize;//栈容量
};

//初始化栈
template<class SElemType>
SqStack<SElemType>::SqStack()
{
	base = new SElemType[MAXSIZE];
	if (!base)exit(overflow);//存储分配失败
	top = base;//栈顶指针等于栈底指针
	stacksize = MAXSIZE;
}

template<class SElemType>
SqStack<SElemType>::SqStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)exit(overflow);//存储分配失败
	S.top = S.base;//栈顶指针等于栈底指针
	S.stacksize = MAXSIZE;
}


template<class SElemType>
SqStack<SElemType>::~SqStack()
{
}

//判断栈空
template<class SElemType>
Status SqStack<SElemType>::StackEmpty(SqStack& S)
{
	if (S.top == S.base)
		return OK;
	else
		return ERROR;
}
//清空栈
template<class SElemType>
Status SqStack<SElemType>::ClearStack(SqStack& S)
{
	if (S.base)S.top = S.base;
	return OK;
}

//销毁栈
template<class SElemType>
Status SqStack<SElemType>::DestroyStack(SqStack& S)
{
	if (S.base)
	{
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}

//入栈
template<class SElemType>
Status SqStack<SElemType>::Push(SqStack& S, SElemType e)
{
	if (S.top - S.base  == S.stacksize)//栈满
		return ERROR;
	*S.top++ = e;//相当于：*S.top = e; S.top++;
	return OK;
}

//出栈
template<class SElemType>
Status SqStack<SElemType>::Pop(SqStack& S, SElemType& e)
{
	if (StackEmpty(S))
		return ERROR;
	e = *--S.top;//相当于：--S.top;e=*S.top;
	return OK;
}


#endif // !STACK_H
