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
	QElemType* base;//��ʼ���Ķ�̬����洢�ռ�
	int front;		//ͷָ��
	int rear;		//βָ��

public:
	SqQueue();
	SqQueue(SqQueue& Q);					 //���г�ʼ��
	~SqQueue();
	Status QEmpty(SqQueue& Q);				 //�ж϶ӿ�
	int QueueLength(SqQueue Q);				 //��ȡ���г���
	Status EnQueue(SqQueue& Q, QElemType e); //��Ӳ���
	Status DeQueue(SqQueue& Q, QElemType& e);//���Ӳ���
	QElemType GetHead(SqQueue Q);			 //��ȡ��ͷԪ��
};

template<class QElemType>
inline SqQueue<QElemType>::~SqQueue()
{
}
//���еĳ�ʼ��
template<class QElemType>
SqQueue<QElemType>::SqQueue()
{
	base = new QElemType[MAXQSIZE];//��������ռ�
	if (!base)exit(overflow);		 //�洢����ʧ��
	front = rear = 0;			 //ͷָ��βָ����Ϊ0��
}
template<class QElemType>
SqQueue<QElemType>::SqQueue(SqQueue& Q)
{
	Q.base = new QElemType[MAXQSIZE];//��������ռ�
	if (!Q.base)exit(overflow);		 //�洢����ʧ��
	Q.front = Q.rear = 0;			 //ͷָ��βָ����Ϊ0��
}

//�ж϶ӿ�
template<class QElemType>
Status SqQueue<QElemType>::QEmpty(SqQueue& Q)
{
	if (Q.rear == Q.front)return OK;
	else return ERROR;
}

//��ȡ���г���
template<class QElemType>
int SqQueue<QElemType>::QueueLength(SqQueue Q)
{
	return ((Q.rear - Q.front + MAXQSIZE) % MAXQSIZE);
}

//��Ӳ���
template<class QElemType>
Status SqQueue<QElemType>::EnQueue(SqQueue& Q, QElemType e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;//����
	Q.base[Q.rear] = e;									//��Ԫ�ؼ����β
	Q.rear = (Q.rear + 1) % MAXQSIZE;					//��βָ��+1
	return OK;
}

//���Ӳ���
template<class QElemType>
Status SqQueue<QElemType>::DeQueue(SqQueue& Q, QElemType& e)
{
	if (QEmpty(Q))return ERROR;		    //�ӿ�
	e = Q.base[Q.front];			    //�����ͷԪ�أ�������
	Q.front = (Q.front + 1) % MAXQSIZE; //��ͷָ��+1
	return OK;
}

//��ȡ��ͷԪ��
template<class QElemType>
QElemType SqQueue<QElemType>::GetHead(SqQueue Q)
{
	if (!QEmpty(Q))return Q.base[Q.front];
	else return QElemType();
}

#endif // !QUEUE_H
