#include"header/Stackhead.h"
using namespace  std;


void int_test()
{
	cout << "\n开始测试int数据" << endl;

	//创建栈
	SqStack<int>* stack = new SqStack<int>();
	stack->Push(*stack, 10);
	stack->Push(*stack, 20);
	stack->Push(*stack, 30);

	//判断是否为空
	if (!stack->StackEmpty(*stack))
		cout << "Not empty!\n";
	else
		cout << "Empty\n";

	//打印栈中全部数据
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