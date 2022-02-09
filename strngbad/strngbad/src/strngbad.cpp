//strngbad.cpp -- StringBad class methods
#include<cstring>
#include<string.h>
#include"header/strngbad.h"
using std::cout;

//initializing static class member
int StringBad::num_strings = 0;

//class methods
//construct StringBad from C string
StringBad::StringBad(const char* s)
{
	len = std::strlen(s);		//set size
	str = new char[len + 1];	//allot storage
	strcpy_s(str, len + 1, s);		//initialize pointer
	num_strings++;
	cout << num_strings << ":\"" << str << "\"object created\n";			//for your information
}

StringBad::StringBad()
{
	len = 4;
	str = new char[5];
	strcpy_s(str,len+1, "C++");	//default string
	num_strings++;
	cout << num_strings << ":\"" << str << "\"default object created\n";	//FYI
}

StringBad::~StringBad()			//necessary destructor
{
	cout << "\"" << str << "\"object deleted, ";	//FYI
	--num_strings;						//required
	cout << num_strings << "left\n";	//FYI
	delete[]str;						//required
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
	os << st.str;
	return os;
}