/*
朴素算法
*/

#include <iostream>
#include <string>

using namespace std;

int Index(string s, string t)
{
	int lens = s.length();//get the length of s and t;
	int lent = t.length();
	int i = 0;
	int j = 0;
	while (i< lens&& j< lent)
	{
		if(s[i]==t[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j ==lent)
	{
		return i - lent;
	}
	else
	{
		return -1;
	}
}

int main()
{
	string s, t;
	cin >> s>> t;
	int pos = Index(s, t);
	if (pos !=-1)
	{
		cout << "find " << t << " at the index " << pos << " of " << s << endl;
	}
	else
	{
		cout << "con't find " << t << " in " << s << endl;
	}
	return 0;
}