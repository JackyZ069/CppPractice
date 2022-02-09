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
	Status StackEmpty(SqStack& S);//�ж�ջ��
	Status ClearStack(SqStack& S);//���ջ
	Status DestroyStack(SqStack& S);//����ջ
	Status Push(SqStack& S,SElemType e);//��ջ
	Status Pop(SqStack& S,SElemType& e);//��ջ

public:
	SElemType* base;//ջ��ָ��
	SElemType* top;//ջ��ָ��
	int stacksize;//ջ����
};

//��ʼ��ջ
template<class SElemType>
SqStack<SElemType>::SqStack()
{
	base = new SElemType[MAXSIZE];
	if (!base)exit(overflow);//�洢����ʧ��
	top = base;//ջ��ָ�����ջ��ָ��
	stacksize = MAXSIZE;
}

template<class SElemType>
SqStack<SElemType>::SqStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)exit(overflow);//�洢����ʧ��
	S.top = S.base;//ջ��ָ�����ջ��ָ��
	S.stacksize = MAXSIZE;
}


template<class SElemType>
SqStack<SElemType>::~SqStack()
{
}

//�ж�ջ��
template<class SElemType>
Status SqStack<SElemType>::StackEmpty(SqStack& S)
{
	if (S.top == S.base)
		return OK;
	else
		return ERROR;
}
//���ջ
template<class SElemType>
Status SqStack<SElemType>::ClearStack(SqStack& S)
{
	if (S.base)S.top = S.base;
	return OK;
}

//����ջ
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

//��ջ
template<class SElemType>
Status SqStack<SElemType>::Push(SqStack& S, SElemType e)
{
	if (S.top - S.base  == S.stacksize)//ջ��
		return ERROR;
	*S.top++ = e;//�൱�ڣ�*S.top = e; S.top++;
	return OK;
}

//��ջ
template<class SElemType>
Status SqStack<SElemType>::Pop(SqStack& S, SElemType& e)
{
	if (StackEmpty(S))
		return ERROR;
	e = *--S.top;//�൱�ڣ�--S.top;e=*S.top;
	return OK;
}


#endif // !STACK_H
