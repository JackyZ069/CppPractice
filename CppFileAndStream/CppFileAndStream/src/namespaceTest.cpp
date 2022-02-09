/* 
C++ 应用程序中。例如，您可能会写一个名为 xyz() 的函数，
在另一个可用的库中也存在一个相同的函数 xyz()。这样，编
译器就无法判断您所使用的是哪一个 xyz() 函数。
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