#pragma once
#include <iostream>
using namespace std;

template <class T>
class Set{
private:
	static const int MAX = 1000;
	int num; 
	T set[MAX];

public:
	Set ( void ) : num ( 0 ) {};
	~Set ( void ) {};
	void Show ( void );
	bool Add ( T x );
	void Union ( const Set &a, const Set &b );
	void Subtract ( const Set &a, const Set &b );
	void Intersection ( const Set &a, const Set &b );
};

