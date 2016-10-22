#pragma once
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

const int MAXL = 500; 

class LongLongInt			//高精度类 
{
	friend ostream & operator << ( ostream & os, const LongLongInt & x );
	friend istream & operator >> ( istream & is,	   LongLongInt & x );

	friend LongLongInt operator + (LongLongInt a,LongLongInt b);
	friend LongLongInt operator - (LongLongInt a,LongLongInt b); //a必须大于等于b 
	friend LongLongInt operator * (LongLongInt a,LongLongInt b);
	friend LongLongInt operator / (LongLongInt a,LongLongInt b);

	friend bool operator < (LongLongInt a,LongLongInt b);
	friend bool operator > (LongLongInt a,LongLongInt b);
	friend bool operator == (LongLongInt a,LongLongInt b);
	friend bool operator <= (LongLongInt a,LongLongInt b);
	friend bool operator >= (LongLongInt a,LongLongInt b);

private:
	int num[MAXL];	//数字 
	int l;			//长度
	bool minus;		//正负

public:
	LongLongInt();
	LongLongInt(int x);
	operator int();
	operator int*();
	int length();
};

bool RangeCmp (int *a, int *b, int l);