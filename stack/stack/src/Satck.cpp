#include"header/Stackhead.h"
using namespace  std;


void int_test()
{
	cout << "\n��ʼ����int����" << endl;

	//����ջ
	SqStack<int>* stack = new SqStack<int>();
	stack->Push(*stack, 10);
	stack->Push(*stack, 20);
	stack->Push(*stack, 30);

	//�ж��Ƿ�Ϊ��
	if (!stack->StackEmpty(*stack))
		cout << "Not empty!\n";
	else
		cout << "Empty\n";

	//��ӡջ��ȫ������
	while (!stack->StackEmpty(*stack))
	{
		int e;
		stack->Pop(*stack, e);
		cout<<e<<endl;
	}
}


int main()
{
	int_test();
	return 0;
}