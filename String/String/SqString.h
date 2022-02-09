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
	char ch[MAXLEN + 1];//�洢����һά����
	int length;			//���ĵ�ǰ����
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
		if (S.ch[i] == T.ch[j]) { ++i; ++j; }	//�������Ӵ�һ��ƥ����һ���ַ�
		else { i = i - j + 2; j = 1; }			//�������Ӵ�ָ��������¿�ʼ��һ��ƥ��
	}
	if (j > T.length) { return i - T.length; }	//����ƥ��ĵ�һ���ַ����±�
	
	else return 0;								//ģʽƥ�䲻�ɹ�
}
#endif // !STRING_H
