#include<iostream>

using namespace std;

int binarysearch(int* arr, int left, int right, int target)//递归实现
{
	int middle = (left + right) / 2;
	if (left > right)
		return -1;
	if (arr[middle] == target)
		return middle;
	if (arr[middle] > target)
		return binarysearch(arr, left, middle - 1, target);
	if (arr[middle] < target)
		return binarysearch(arr, middle + 1, right, target);

};

int binarysearch1(int a[], int n, int target)//循环实现
{
	int left = 0, right = n, middle;
	while (left<right)
	{
		middle = (left + right) / 2;
		if (target == a[middle])
			return middle;
		else if (target > a[middle])
			left = middle + 1;
		else if (target < a[middle])
			right = middle ;
	}
	return -1;
}

int main()
{
	int a[10] = { 5,6,7,8,9,10,11,12,13,14 };
	int index = binarysearch(a, 0,9, 12);
	cout << index << endl;
	int index1 = binarysearch1(a, 10, 12);
	cout << index1 << endl;
	return 0;
}