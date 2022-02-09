#pragma once
//string1.h -- fixed and augmented string class edfinition
#ifndef STRING1_H_
#define STRING1_H_
#include<iostream>
using std::ostream;
using std::istream;

class String
{
public:
	//constructors and other methods
	String(const char* s);	//constructor
	String();				//default constructor
	String(const String& s);	//copy constructor
	~String();				//destructor
	int length() const { return len; }
	//overloaded oprator methods
	String& operator=(const String&);
	String& operator=(const char*);
	char& operator[](int t);
	const char& operator[](int i)const;
	//overloaded operator friends
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);
	//static function
	static int HowMany();

private:
	char* str;				//ptr to string
	int len;				//len to string
	static int num_strings;	//number of objects
	static const int CINLIM = 80;	//cin input limit
};

#endif // !STRNIG1_H-
