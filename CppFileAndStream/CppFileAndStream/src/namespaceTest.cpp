/* 
C++ Ӧ�ó����С����磬�����ܻ�дһ����Ϊ xyz() �ĺ�����
����һ�����õĿ���Ҳ����һ����ͬ�ĺ��� xyz()����������
�������޷��ж�����ʹ�õ�����һ�� xyz() ������
*/
#include<iostream>
using namespace std;

//first namespace
namespace first_space {
	void func()
	{
		cout << "Inside first_space" << endl;
	}
}

//second one
namespace second_space {
	void func()
	{
		cout << "Inside scond_space" << endl;
	}
}

using namespace first_space;
int main()
{
	func();
	return 0;
}