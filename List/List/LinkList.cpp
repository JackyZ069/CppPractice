#include"List.h"

using namespace std;

typedef struct Lnode
{
	int data;
	Lnode* next;
}Londe, * LinkList;

//Initailize LinkList
Status InitList_L(LinkList& L)
{
	L = new Lnode;
	L->next = NULL;
	return OK;
}

//Is empty?
Status IsEmpty(LinkList& L)
{
	if (L->next)return FALSE;
	else return TURE;
}

//Destory LinkList
Status DestoryLinkList(LinkList& L)
{
	while (L)
	{
		Lnode* P;
		P = L;
		L = L->next;
		delete P;
	}
	return OK;
}

//Clear LinkList
Status ClearList(LinkList& L)
{
	Lnode* q, * p;
	p = L->next;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
}

//Get the length of LinkList
int ListLength_L(LinkList L)
{
	LinkList p;
	p = L->next;
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

//Get the value of Lnode
Status GetElem(LinkList L, int i, int& e)
{
	Lnode* p;
	p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return ERROR;
	e = p->data;
	return OK;
}

//Locate the element
Lnode* LocateElem(LinkList L, int e)
{
	Lnode* p;
	p = L->next;
	while (p && p->data != e)
		p = p ->next;
	return p;
}

//Delete Lnode
Status LnodeDelete(LinkList& L, int i, int e)
{
	Lnode* p, * q;
	p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p->next || j > i - 1)return ERROR;
	q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}

//��������--ǰ�巨
void CreadList_H(LinkList& L, int n)
{
	L = new Lnode;
	Lnode* p;
	L->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
	for (int i = n; i > 0; --i)
	{
		p = new Londe;//�����µĽ��
		cin >> p->data;//�½���Ԫ��ֵ
		p->next = L->next;
		L->next = p;
	}
}

//��������--β�巨
void CreatList_R(LinkList& L, int n)
{
	L = new Lnode;
	L->next = NULL;
	Lnode* r, * p;
	r = L;
	for (int i = 0; i < n; ++i)
	{
		p = new Lnode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;//���뵽��β
		r = p;//rָ���µ�β���
	}
}

//��βָ�������ϲ�
LinkList Connect(LinkList Ta, LinkList Tb)
{
	Lnode* p;
	p = Ta->next;
	Ta->next = Tb->next;
	delete Tb->next;
	Tb->next = p;
	return Tb;
}


int main()
{
	return 0;
}