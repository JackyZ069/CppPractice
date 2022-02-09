#include"DulLinkList.h"

using namespace std;

void int_test()
{
	cout << "\n开始测试 int数据" << endl;

	//创建双向链表
	DoubleLinkList<int>* pdlink = new DoubleLinkList<int>();

	pdlink->insert(0, 20);		//将20插入到第一个位置
	pdlink->insertLast(10);		//将10追加到链表末尾
	pdlink->insertFirst(30);	//将30插入到第一个位置
	
	//判断是否为空
	if (pdlink->IsEmpty())
		cout << "Not empty!";
	else
		cout << "Empty";

	//获取链表大小
	cout << "The length ofDouble Link is:" << pdlink->GetLength();

	//打印链表中全部数据
	for (int i = 0; i < pdlink->GetLength(); i++)
	{
		cout << "pdlink(" << i << ")=" << pdlink->getData(i) << endl;
	}
}

int main()
{
	int_test();
	system("pause");
	return 0;
}
