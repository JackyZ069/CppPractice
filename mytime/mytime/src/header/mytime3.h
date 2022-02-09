#pragma once
//mytime3.h -- Time class with friends
#ifndef MYTIME3_H_
#define MYTIME3_H_

class Time
{
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	void show()const;
	Time operator+(const Time& t)const;
	Time operator-(const Time& t)const;
	Time operator*(double n)const;
	friend Time operator*(double m, const Time& t)
	{
		return t * m;//inline definition
	}
	friend std::ostream & operator<< (std::ostream & os, const Time & t);

private:
	int hours;
	int minutes;
};

#endif // !MYTIME_H_
#pragma once
#pragma once
