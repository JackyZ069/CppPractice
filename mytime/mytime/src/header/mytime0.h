#pragma once
//mytime0.h -- Time class before operator
#ifndef MYTIME_H_
#define MYTIME_H_

class Time
{
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time Sum(const Time& t)const;
	void show()const;
private:
	int hours;
	int minutes;
};

#endif // !MYTIME_H_
