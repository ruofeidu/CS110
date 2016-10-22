//#include <iostream>
#include "Set.h"
//using namespace std;

template <class T>
void Set<T>::Union ( const Set<T> &a, const Set<T> &b )
{
	bool flag;
	num = a.num; 
	for ( int i = 0; i < a.num; ++i )
		set[i] = a.set[i]; 

 	for ( int i = 0; i < b.num; ++i )
	{
		flag = true;
		for ( int j = 0; j < a.num; ++j )
			if ( a.set[j] == b.set[i] ) { flag = false; break; }
		if ( flag )
			set[num++] = b.set[i];
	}
}

template <class T>
void Set<T>::Subtract ( const Set<T> &a, const Set<T> &b )
{
	bool flag;
	num = 0;
	for ( int i = 0; i < a.num; ++i )
	{
		flag = true;
		for (int j = 0; j < b.num; ++j )
			if ( b.set[j] == a.set[i] ) { flag = false; break; }
		if ( flag )
			set[num++] = a.set[i];
	}
}

template <class T>
void Set<T>::Intersection ( const Set &a, const Set &b )
{
	num = 0; 

	for ( int i = 0; i < b.num; ++i )
		for ( int j = 0; j < a.num; ++j )
			if ( a.set[j] == b.set[i] ) { set[num++] = b.set[i]; break; }
}
		

template <class T>
bool Set<T>::Add ( T x )
{
	for ( int i = 0; i < num; ++i )
		if ( set[i] == x ) return false; 
	set[num++] = x;
	return true;
}

template <class T>
void Set<T>::Show ()
{
	for ( int i = 0; i < num; ++i )
		cout << set[i] << '\t';
	cout << endl; 
}
