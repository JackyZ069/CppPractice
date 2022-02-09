#include<iostream>
using namespace std;

void bubble(int arr[],int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (arr[j]<arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j+1] = temp;
			}
		}
	}
}

void print(int arr[],int n)
{
	for (int i = 0; i < n-1; i++)
	{
		cout << arr[i] << "\t";
	}
}

int main()
{
	int a[7] = { 4,5,8,9,2,6,8 };
	bubble(a, 7);
	print(a, 7);
	return 0;

}