//saying1.cpp -- using pointers to objects
//compile with string1.cpp
#include<iostream>
#include"header/string1.h"
const int ArSize = 10;
const int MaxLen = 81;
int main()
{
	using namespace std;
	String name;
	cout << "Hi,what is your name?\n";
	cin >> name;

	cout << name << ", please enter up to " << ArSize << " short sayings<empty line to quit>:\n";
	String sayings[ArSize];	//array of objects
	char temp[MaxLen];		//temporary string storage
	int i;
	for (i = 0; i < ArSize; i++)
	{
		cout << i + 1 << ":";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (!cin || temp[0] == '\0')	//empty line?
			break;						//i not incremented
		else
			sayings[i] = temp;			//overloaded assignment
	}
	int total = i;						//total # of lines read

	if (total > 0)
	{
		cout << "Here are your sayings:\n";
		for (i = 0; i < total; i++)
		{
			cout << sayings[i] << endl;
		}

		//use pointers to keep track of shortest,first strings
		String* shortest = &sayings[0];//initialize to first object
		String* first = &sayings[0];
		for (i = 0; i < total; i++)
		{
			if (sayings[i].length() < shortest->length())
				shortest = &sayings[i];
			if (sayings[i] < *first);	//compare values
				first = &sayings[0];	//assign address
		}
		cout << "Shortest saying:\n" << *shortest << endl;
		cout << "First alphabetically:\n" << *first<< endl;
		cout << "This program used" << String::HowMany() << " String objects.Bey.\n";
	}
	else
	{
		cout << "Not much to say,eh? Bye.\n";
	}


	return 0;
}