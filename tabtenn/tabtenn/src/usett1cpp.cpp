//usett1.cpp -- using base class and derived class
#include<iostream>
#include"header/tabtenn1.h"

int main(void)
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatePlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();			//derived object uses base method
	if (rplayer1.HasTable())
	{
		cout << ":has a table.\n";
	}
	else
	{
		cout << ":hasn't a table.\n";
	}
	player1.Name();				//base object uses base method
	if (player1.HasTable())
	{
		cout << ": has a table.\n";
	}
	else
	{
		cout << ": hasn't a table.\n";
	}
	cout << "Name:";
	rplayer1.Name();
	cout << "; Rating:" << rplayer1.Rating() << endl;
	//initialize RatePlayer using TableTennisPlayer object
	RatePlayer rplay2(1212, player1);
	cout << "Name:";
	rplay2.Name();
	cout << "; Rating:" << rplay2.Rating() << endl;

	return 0;
}