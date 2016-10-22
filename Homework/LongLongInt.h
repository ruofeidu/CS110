#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int MAXL = 500; 

class LongLongInt			//�߾����� 
{
	friend ostream & operator << ( ostream & os, const LongLongInt & x );
	friend istream & operator >> ( istream & is,	   LongLongInt & x );

	friend LongLongInt operator + (LongLongInt a,LongLongInt b);
	friend LongLongInt operator - (LongLongInt a,LongLongInt b); //a������ڵ���b 
	friend LongLongInt operator * (LongLongInt a,LongLongInt b);
	friend LongLongInt operator / (LongLongInt a,LongLongInt b);

	friend bool operator < (LongLongInt a,LongLongInt b);
	friend bool operator > (LongLongInt a,LongLongInt b);
	friend bool operator == (LongLongInt a,LongLongInt b);
	friend bool operator <= (LongLongInt a,LongLongInt b);
	friend bool operator >= (LongLongInt a,LongLongInt b);

private:
	int num[MAXL];	//���� 
	int l;			//����
	bool minus;		//����

public:
	LongLongInt();
	LongLongInt(int x);
	operator int();
	operator int*();
	int length();
};

bool RangeCmp (int *a, int *b, int l);