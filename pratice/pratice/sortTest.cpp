#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

int main()
{
	std::vector<int> values = { 3,2,5,6,1 };
	std::sort(values.begin(), values.end(), [](int a, int b)
		{	
			if (a == 1)
				return false;
			if (b == 1)
				return true;
			return a < b;
		}); 

	for (int value : values)
		std::cout << value << std::endl;
	std::cin.get();
}