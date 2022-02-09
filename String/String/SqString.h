#pragma once
#ifndef STRING_H
#define STRING_H

#include<iostream>

#define MAXLEN 80
#define overflow -2
#define Status int
#define OK 1
#define ERROR 0

class SqString
{
public:
	SqString();
	~SqString();

public:
	char ch[MAXLEN + 1];//存储串的一维数组
	int length;			//串的当前长度
	int Index_BF(SqString S, SqString T);
};

SqString::SqString()
{
	
}

SqString::~SqString()
{
}

int SqString::Index_BF(SqString S, SqString T)
{
	int i = 1,j = 1;
	while (i<=S.length&&j<=T.length)
	{
		if (S.ch[i] == T.ch[j]) { ++i; ++j; }	//主串和子串一次匹配下一个字符
		else { i = i - j + 2; j = 1; }			//主串、子串指针回溯重新开始下一次匹配
	}
	if (j > T.length) { return i - T.length; }	//返回匹配的第一个字符的下标
	
	else return 0;								//模式匹配不成功
}
#endif // !STRING_H
