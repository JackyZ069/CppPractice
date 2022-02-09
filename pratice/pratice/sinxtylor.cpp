#include<iostream>
using namespace std;

template<class T>
void bublleSort(T data[], int size)
{
	int i, j;

	T tmp;

	for (i = 1; i <= size; i++)
	{
		bool flag = false;
		for (j = 0;j<=size-i;j++)
			if (data[j]<data[j+1])
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
				flag = true;
			}
		if (!flag)break;
	}
}


int main()
{
	int i[4] = { 2,1,5,4 };
	bublleSort(i, 4);

	float f[4] = { 1.2,4.1,2.1,3.3 };
	bublleSort(f, 4);

	for (int j = 0;j < 4; j++)
	{
		cout << i[j] << endl;
	}
	for (int j = 0; j < 4; j++)
	{
		cout << f[j] << endl;
	}
}
