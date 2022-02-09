#include"List.h"

struct SqList
{
	int* elem;
	int length;
};


//线性表初始化
int Init_Sq(SqList& L)
{
	L.elem = new int[MAXSIZE];
	if (!L.elem)exit(OverFlow);
	L.length = 0;
	return OK;
}

//线性表的销毁
void DestoryList(SqList& L)
{
	if (L.elem)
	{
		delete L.elem;
	}
}

//clear SqList
int ClearSqList(SqList& L)
{
	L.length = 0;
	return OK;
}

//get the length of SqList
int ListLength(SqList& L)
{
	return (L.length);
}

//search by value
int LocatedElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			return i + 1;
		}
	}
	return 0;
}


//Insert to the SqList
int ListInsert_Sq(SqList& L, int i, int e)
{
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	for (int j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];//后移
	}
	L.elem[i - 1] = e;//Insert
	L.length++;
	return OK;
}

//Delete the SqList
int ListDelete_Sq(SqList& L, int i)
{
	if (i<1 || i>L.length)
	{
		return ERROR;
	}
	for (int j = 1; j <= L.length - 1; j++)
	{
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}

int main()
{
	return 0;
}

  