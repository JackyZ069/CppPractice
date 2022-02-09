//usetime2.cpp -- using the first draft of the Time class
//compile usetime0.cpp and mytime2.cpp together
#include<iostream>
#include"header/mytime2.h"

int main()
{
	using std::cout;
	using std::endl;
	Time weeding(2, 40);
	Time waxing(5, 55);
	Time total;
	Time diff;
	Time adjusted;

	cout << "weeding time=";
	weeding.show();
	cout << endl;

	cout << "waxing time =";
	waxing.show();
	cout << endl;

	cout << "total work time = ";
	total = weeding + waxing;
	total.show();
	cout << endl;

	diff = weeding - waxing;
	diff.show();
	cout << endl;

	adjusted = total * 1.5;
	adjusted.show();
	cout << endl;

	return	0;

}
