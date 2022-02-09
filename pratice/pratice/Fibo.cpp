#include <iostream>
using namespace std;

//—≠ª∑À„∑®
int Fibo(int n) {
	if (n <= 2)
	{
		return 1;
	}
	int prev = 1;
	int curr = 1;

	for (int i = 3; i <= n; i++)
	{
		int sum = prev + curr;
		prev = curr;
		curr = sum;
	}
	
	return curr;
}
/*µ›πÈÀ„∑®
long Fibo(long ln)
{
	if (ln < 2)
	{
		return ln;
	}

	return Fibo(ln - 1) + Fibo(ln - 2);
}
*/
int main() 
{
	int ls = Fibo(4);
	cout << ls << endl;
	return 0;
}
