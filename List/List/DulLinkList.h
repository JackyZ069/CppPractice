#pragma once
#ifndef DOUBLE_LINK_H
#define DOUBLE_LINK_H
#include<iostream>
#define Status int
#define OK 1
#define ERROR 0


using namespace std;

template <class ElemType>

//��㶨��
struct DNode
{
public:
	ElemType data;
	DNode* prior;
	DNode* next;
public:
	DNode() {}
	//������
	DNode(ElemType e, DNode* prior, DNode* next)
	{
		this->data = e;
		this->prior = prior;
		this->next = next;
	}
};

//������
template<class ElemType>
class DoubleLinkList
{
private:
	int length;
	DNode<ElemType>* phead;
private:
	DNode<ElemType>* getNode(int index);
public:
	DoubleLinkList();
	~DoubleLinkList();

	Status IsEmpty();//�ж��Ƿ�Ϊ��
	int GetLength();//��ó���

	ElemType getData(int index);//��ȡĳ���������
	ElemType getFisrtData();//��ȡͷ�������
	ElemType getLastData();//��ȡβ�������

	Status insert(int index, ElemType elem);//��ĳ��λ�ò�����
	Status insertFirst(ElemType elem);//����ͷ���
	Status insertLast(ElemType elem);//����β���

	Status del(int index);//ɾ��ĳ�����
	Status delFirst();//ɾ��ͷ���
	Status delLast();//ɾ��β���
};

//���캯��
template<class ElemType>
DoubleLinkList<ElemType>::DoubleLinkList():length(0)
{
	//��������ͷ������ͷû�д洢����
	phead = new DNode<ElemType>();
	phead->prior = phead->next = phead;
}

//��������
template<class ElemType>
DoubleLinkList<ElemType>::~DoubleLinkList()
{
	DNode<ElemType>* ptmp, * pnode;
	pnode = phead->next;
	while (pnode!=phead)
	{
		ptmp = pnode;
		pnode = pnode->next;
		delete ptmp;
	}
	delete phead;
	phead = NULL;
}

//��ȡ����
template<class ElemType>
int DoubleLinkList<ElemType>::GetLength()
{
	return length;
}


//�ж��Ƿ�Ϊ��
template<class ElemType>
Status DoubleLinkList<ElemType>::IsEmpty()
{
	return (length == 0);
}

//��ȡ����ַ
template<class ElemType>
DNode<ElemType>* DoubleLinkList<ElemType>::getNode(int index)
{
	if (index<0||index>= length)
	{
		cout << "get node failed\n";
		return NULL;
	}

	//�������
	if (index <= length / 2)
	{
		int i = 0;
		DNode<ElemType>* pindex = phead->next;
		while (i++ < index)
		{
			pindex = pindex->next;
		}

		return pindex;
	}

	//�������

	int j = 0;
	int rindex = length - index - 1;
	DNode<ElemType>* prindex = phead->prior;
	while (j++ < rindex) {
		prindex = prindex->prior;
	}

	return prindex;
}

//��ȡ��indexλ�õĽ���ֵ
template<class ElemType>
ElemType DoubleLinkList<ElemType>::getData(int index)
{
	return getNode(index)->data;
}

//��ȡ��һ��λ�õĽ���ֵ
template<class ElemType>
ElemType DoubleLinkList<ElemType>::getFisrtData()
{
	return getNode(0)->data;
}

//��ȡ���һ������ֵ
template<class ElemType>
ElemType DoubleLinkList<ElemType>::getLastData()
{
	return getNode(length - 1)->data;
}

//�������뵽indexλ��֮ǰ
template<class ElemType>
Status DoubleLinkList<ElemType>::insert(int index, ElemType e)
{
	if (index == 0)
		return insertFirst(e);
	
	DNode<ElemType>* pindex = getNode(index);
	DNode<ElemType>* pnode = new DNode<ElemType>(e, pindex->prior, pindex);
	pindex->prior->next = pnode;
	pindex->prior = pnode;
	length++;

	return OK;
}

//�������뵽��һ�����ǰ
template<class ElemType>
Status DoubleLinkList<ElemType>::insertFirst(ElemType e)
{
	DNode<ElemType>* pnode = new DNode<ElemType>(e, phead, phead->next);
	phead->next->prior = pnode;
	phead->next = pnode;
	length++;

	return OK;
}

//�������뵽���һ�����
template<class ElemType>
Status DoubleLinkList<ElemType>::insertLast(ElemType e)
{
	DNode<ElemType>* pnode = new DNode<ElemType>(e, phead->prior, phead);
	phead->prior->next = pnode;
	phead->prior = pnode;
	length++;

	return OK;
}

//ɾ��indexλ�õĽ��
template<class ElemType>
Status DoubleLinkList<ElemType>::del(int index)
{
	DNode<ElemType>* pnode = getNode(index);
	pnode->prior->next = pnode->next;
	pnode->next->prior = pnode->prior;
	delete pnode;

	return OK;
}

//ɾ����һ��λ�õĽ��
template<class ElemType>
Status DoubleLinkList<ElemType>::delFirst()
{
	return del(0);
}

//ɾ�����һ��λ�õĽ��
template<class ElemType>
Status DoubleLinkList<ElemType>::delLast()
{
	return (length -1);
}
#endif // !DOUBLE_LINK_H