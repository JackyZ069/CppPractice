#include"DulLinkList.h"

using namespace std;

void int_test()
{
	cout << "\n��ʼ���� int����" << endl;

	//����˫������
	DoubleLinkList<int>* pdlink = new DoubleLinkList<int>();

	pdlink->insert(0, 20);		//��20���뵽��һ��λ��
	pdlink->insertLast(10);		//��10׷�ӵ�����ĩβ
	pdlink->insertFirst(30);	//��30���뵽��һ��λ��
	
	//�ж��Ƿ�Ϊ��
	if (pdlink->IsEmpty())
		cout << "Not empty!";
	else
		cout << "Empty";

	//��ȡ�����С
	cout << "The length ofDouble Link is:" << pdlink->GetLength();

	//��ӡ������ȫ������
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
