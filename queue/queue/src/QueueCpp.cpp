//队列是头删尾插的线性表
//只在队首队尾运算，且按照先进先出（FIFO）原则
//入队出队基本操作
//循环队列更为常见

#include"header/QueueHead.h"
using namespace  std;
void int_test()
{
	cout << "\n开始测试int数据" << endl;

	//创建队列
	SqQueue<int>* queue = new SqQueue<int>();
	queue->EnQueue(*queue, 10);
	queue->EnQueue(*queue, 20);
	queue->EnQueue(*queue, 30);

	//判断是否为空
	if (!queue->QEmpty(*queue))
		cout << "Not empty!\n";
	else
		cout << "Empty\n";

	//打印队列中全部数据
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