#include <iostream>
#include <thread>

using namespace std;

//virtuale func
void foo(int z)
{
	for (int i = 0; i < z; i++)
	{
		cout << "Thread uses functional pointer as the callable parameter\n";
	}
}

//callable object
class thread_obj {
public:
	void operator()(int x)
	{
		for (int i = 0; i < x; i++)
		{
			cout << "Thread uses functional object as the callable parameter\n ";
		}
	}
};


int main()
{
	cout << "thread 1,2,3"
		"run alone" << endl;

	//functional pointer
	thread th1(foo, 3);

	//functional object
	thread th2(thread_obj(),3);

	//define Lambda expression
	auto f = [](int x) {
		for (int i = 0; i < x; i++)
		{
			cout << "Thread uses the Lambda expression as the callable parameter\n";
		}
	};
	
	//Lambda expression as the callable parameter
	thread th3(f, 3);

	//wait the threads
	//wait the th1
	th1.join();

	//wait the th2
	th2.join();

	//wait the th3
	th3.join();

	return 0;
}