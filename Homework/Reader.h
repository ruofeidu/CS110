#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct List
{
	int data;
	List *next;
};

class reader
{
protected:
	int MAX;
	int borrowed;

private:
	int No;

	char name[10];
	char dept[20];
	List *head;

	bool Insert( int x, int index );
	bool Find( int x );
	void Del( int x );

public:
	reader (int n, char *nm, char *d);
	bool bookBorrow( int id );
	bool bookReturn( int id );
	void show();
};

class readerTeacher : public reader
{
public:
	readerTeacher( int n, char *nm, char *d ): reader(n, nm, d) { MAX = 10; }
};

class readerStudent : public reader
{
public:
	readerStudent ( int n, char *nm, char *d ) : reader( n, nm, d ) { MAX = 5; }
};

