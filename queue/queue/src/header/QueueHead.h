#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>

#define MAXQSIZE 100
#define overflow -2
#define Status int
#define OK 1
#define ERROR 0

template<class QElemType>
class SqQueue
{
public:
	QElemType* base;//初始化的动态分配存储空间
	int front;		//头指针
	int rear;		//尾指针

public:
	SqQueue();
	SqQueue(SqQueue& Q);					 //队列初始化
	~SqQueue();
	Status QEmpty(SqQueue& Q);				 //判断队空
	int QueueLength(SqQueue Q);				 //获取队列长度
	Status EnQueue(SqQueue& Q, QElemType e); //入队操作
	Status DeQueue(SqQueue& Q, QElemType& e);//出队操作
	QElemType GetHead(SqQueue Q);			 //获取队头元素
};

template<class QElemType>
inline SqQueue<QElemType>::~SqQueue()
{
}
//队列的初始化
template<class QElemType>
SqQueue<QElemType>::SqQueue()
{
	base = new QElemType[MAXQSIZE];//分配数组空间
	if (!base)exit(overflow);		 //存储分配失败
	front = rear = 0;			 //头指针尾指针置为0；
}
template<class QElemType>
SqQueue<QElemType>::SqQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE];//分配数组空间
	if (!Q.base)exit(overflow);		 //存储分配失败
	Q.front = Q.rear = 0;			 //头指针尾指针置为0；
}

//判断队空
template<class QElemType>
Status SqQueue<QElemType>::QEmpty(SqQueue& Q)
{
	if (Q.rear == Q.front)return OK;
	else return ERROR;
}

//获取队列长度
template<class QElemType>
int SqQueue<QElemType>::QueueLength(SqQueue Q)
{
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

//入队操作
template<class QElemType>
Status SqQueue<QElemType>::EnQueue(SqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;//队满
	Q.base[Q.rear] = e;									//新元素加入队尾
	Q.rear = (Q.rear + 1) % MAXQSIZE;					//队尾指针+1
	return OK;
}

//出队操作
template<class QElemType>
Status SqQueue<QElemType>::DeQueue(SqQueue& Q, QElemType& e)
{
	if (QEmpty(Q))return ERROR;		    //队空
	e = Q.base[Q.front];			    //保存队头元素，并返回
	Q.front = (Q.front + 1) % MAXQSIZE; //队头指针+1
	return OK;
}

//获取队头元素
template<class QElemType>
QElemType SqQueue<QElemType>::GetHead(SqQueue Q)
{
	if (!QEmpty(Q))return Q.base[Q.front];
	else return QElemType();
}

#endif // !QUEUE_H
