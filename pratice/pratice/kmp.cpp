/*kmp*/
#include <iostream>
#include <string>

using namespace std;

void get_next(string t, int* next);
int Index_KMP(string s, string t);

int main()
{
	string s = "ababadeababaaabadf";
	string t = "ababaaaba";
	int pos = Index_KMP(s, t);
	if (pos!=-1)
	{
		cout << "find " << t << " at the index " << pos << " of " << s << endl;
	}
	else
	{
		cout << "can't find " << t << " in " << s << endl;
	}
	return 0;
}

int Index_KMP(string s, string t)
{
	int lens = s.length();
	int lent = t.length();
	int* next = new int[lent];
	get_next(t, next);//get the next array
	int i = 0;
	int j = 0;
	while (i < lens && j < lent)
	{
		if (j == 0 || t[j] == s[i])
		{
			++i;
			++j;
		}
		else
		{
			j = next[j - 1];
		}
	}
		if (j == lent)
		{
			return i - lent;
		}
		else
		{
			return -1;
		}

}
void get_next(string t, int* next)
{
	int lent = t.length();
	int i = 0;
	int j = 0;
	next[0] = 0;
	while (i<lent)
	{
		if (j == 0 || t[i] == t[j - 1])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
		{
			j = next[j - 1];
		}
	}
}