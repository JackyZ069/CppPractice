#pragma once
#ifndef DOUBLE_LINK_H
#define DOUBLE_LINK_H
#include<iostream>
#define Status int
#define OK 1
#define ERROR 0


using namespace std;

template <class ElemType>

//结点定义
struct DNode
{
public:
	ElemType data;
	DNode* prior;
	DNode* next;
public:
	DNode() {}
	//构造结点
	DNode(ElemType e, DNode* prior, DNode* next)
	{
		this->data = e;
		this->prior = prior;
		this->next = next;
	}
};

//链表定义
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

	Status IsEmpty();//判断是否为空
	int GetLength();//获得长度

	ElemType getData(int index);//获取某个结点数据
	ElemType getFisrtData();//获取头结点数据
	ElemType getLastData();//获取尾结点数据

	Status insert(int index, ElemType elem);//在某个位置插入结点
	Status insertFirst(ElemType elem);//插入头结点
	Status insertLast(ElemType elem);//插入尾结点

	Status del(int index);//删除某个结点
	Status delFirst();//删除头结点
	Status delLast();//删除尾结点
};

//构造函数
template<class ElemType>
DoubleLinkList<ElemType>::DoubleLinkList():length(0)
{
	//创建“表头”。表头没有存储数据
	phead = new DNode<ElemType>();
	phead->prior = phead->next = phead;
}

//析构函数
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

//获取长度
template<class ElemType>
int DoubleLinkList<ElemType>::GetLength()
{
	return length;
}


//判断是否为空
template<class ElemType>
Status DoubleLinkList<ElemType>::IsEmpty()
{
	return (length == 0);
}

//获取结点地址
template<class ElemType>
DNode<ElemType>* DoubleLinkList<ElemType>::getNode(int index)
{
	if (index<0||index>= length)
	{
		cout << "get node failed\n";
		return NULL;
	}

	//正向查找
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

	//反向查找

	int j = 0;
	int rindex = length - index - 1;
	DNode<ElemType>* prindex = phead->prior;
	while (j++ < rindex) {
		prindex = prindex->prior;
	}

	return prindex;
}

//获取第index位置的结点的值
template<class ElemType>
ElemType DoubleLinkList<ElemType>::getData(int index)
{
	return getNode(index)->data;
}

//获取第一个位置的结点的值
template<class ElemType>
ElemType DoubleLinkList<ElemType>::getFisrtData()
{
	return getNode(0)->data;
}

//获取最后一个结点的值
template<class ElemType>
ElemType DoubleLinkList<ElemType>::getLastData()
{
	return getNode(length - 1)->data;
}

//将结点插入到index位置之前
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

//将结点插入到第一个结点前
template<class ElemType>
Status DoubleLinkList<ElemType>::insertFirst(ElemType e)
{
	DNode<ElemType>* pnode = new DNode<ElemType>(e, phead, phead->next);
	phead->next->prior = pnode;
	phead->next = pnode;
	length++;

	return OK;
}

//将结点插入到最后一个结点
template<class ElemType>
Status DoubleLinkList<ElemType>::insertLast(ElemType e)
{
	DNode<ElemType>* pnode = new DNode<ElemType>(e, phead->prior, phead);
	phead->prior->next = pnode;
	phead->prior = pnode;
	length++;

	return OK;
}

//删除index位置的结点
template<class ElemType>
Status DoubleLinkList<ElemType>::del(int index)
{
	DNode<ElemType>* pnode = getNode(index);
	pnode->prior->next = pnode->next;
	pnode->next->prior = pnode->prior;
	delete pnode;

	return OK;
}

//删除第一个位置的结点
template<class ElemType>
Status DoubleLinkList<ElemType>::delFirst()
{
	return del(0);
}

//删除最后一个位置的结点
template<class ElemType>
Status DoubleLinkList<ElemType>::delLast()
{
	return (length -1);
}
#endif // !DOUBLE_LINK_H