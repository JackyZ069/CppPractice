//usetime0.cpp -- using the first draft of the Time class
//compile usetime0.cpp and mytime0.cpp together
#include<iostream>
#include"header/mytime0.h"

int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2,40);
	Time fixing(5,55);
	Time total;

	cout << "planning time =";
	planning.show();
	cout << endl;

	cout << "coding time=";
	coding.show();
	cout << endl;

	cout << "coding time=";
	fixing.show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	total.show();
	cout << endl;

	return 0;
}