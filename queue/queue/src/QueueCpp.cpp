//������ͷɾβ������Ա�
//ֻ�ڶ��׶�β���㣬�Ұ����Ƚ��ȳ���FIFO��ԭ��
//��ӳ��ӻ�������
//ѭ�����и�Ϊ����

#include"header/QueueHead.h"
using namespace  std;
void int_test()
{
	cout << "\n��ʼ����int����" << endl;

	//��������
	SqQueue<int>* queue = new SqQueue<int>();
	queue->EnQueue(*queue, 10);
	queue->EnQueue(*queue, 20);
	queue->EnQueue(*queue, 30);

	//�ж��Ƿ�Ϊ��
	if (!queue->QEmpty(*queue))
		cout << "Not empty!\n";
	else
		cout << "Empty\n";

	//��ӡ������ȫ������
	while (!queue->QEmpty(*queue))
	{
		int e;
		queue->DeQueue(*queue, e);
		cout << e << endl;
	}
}


int main()
{
	int_test();
	return 0;
}