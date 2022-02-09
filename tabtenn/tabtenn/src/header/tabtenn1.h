//tabtenn1.h -- a table-tennis base class
#pragma once
#ifndef TABTENN_H_
#define TABTENN_H_
#include<iostream>
using std::string;

//simple base class
class TableTennisPlayer
{
public:
	TableTennisPlayer(const string& fn = "none",
		const string& ln = "none", bool ht = false);
	void Name() const;
	bool HasTable()const { return hasTable; }
	void ResetTable(bool v) { hasTable = v; };

private:
	string firstname;
	string lastname;
	bool hasTable;
};

class RatePlayer : public TableTennisPlayer
{
public:
	RatePlayer(unsigned int r = 0, const string& fn = "none",
		const string& ln = "none", bool ht = false);
	RatePlayer(unsigned int r, const TableTennisPlayer& tp);
	unsigned int Rating()const { return rating; }
	void ResetRating(unsigned int r) { rating = r; }
private:
	unsigned int rating;
};

#endif // !TABTENN_H_
