//usetime0.cpp -- using the first draft of the Time class
//compile usetime0.cpp and mytime0.cpp together
#include<iostream>
#include"header/mytime1.h"

int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
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

	total = coding + fixing;
	//operator notation
	cout << "coding + fixing =";
	total.show();
	cout << endl;

	Time morefixing(3.28);
	cout << "more fixing time=";
	morefixing.show();
	cout << endl;
	total = morefixing.operator+(total);
	//function notation
	cout << "morefixing.operator+(total)=";
	total.show();
	cout << endl;


	return 0;
}
