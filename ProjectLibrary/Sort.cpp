/***************************************************
  �ļ�: Manage.cpp
  ���ã�Library.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;��ͳ����顢ԤԼ���������
  ���룺Date Month User
***************************************************/

#pragma once
#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

// ����������
void Library::Swap( int a, int b) {
	SBook[MAX_BOOK] = SBook[a];
	SBook[a] = SBook[b];
	SBook[b] = SBook[MAX_BOOK];
}

// ��������
void Library::Qsort(int l, int r) {
	int i, j;
	BookResource *pivot;
    
	i = l;  j = r;
	pivot = SBook[(i + j) / 2];
    
	do {
		while ( SBook[i]->GetKEY(BookKey) < pivot->GetKEY(BookKey) ) ++i;
		while ( pivot->GetKEY(BookKey) < SBook[j]->GetKEY(BookKey) ) --j;
		if ( i <= j ){
			Swap( i, j );
			++i; --j;
		}
	} while ( i <= j );
    
	if (l < j) Qsort(l, j);
	if (i < r) Qsort(i, r);
}

// �����ض��ؼ�������
void Library::Sort( int x ) {
	BookKey = x; 
	Qsort( 0, BookResult - 1 );
}

//����û����������,MAX_BOOK��Ϊ�����롣
int Library::Readln( int l ,int r ){
    int x;
	string str;
    do {
		getline( cin, str ) ;
        x = Val(str);
		if (x == MAX_BOOK) cout << "�� ���������Ϣż������~~ @_@ �������������룡" << endl;  
        else if (x < l || x > r) x = MAX_BOOK;
    } while (x == MAX_BOOK);
    
    return (x);
}

//�ַ���ת�������ֵĺ��� 
int  Library::Val(string s) {
    int i, x = 0;
    bool flag = false;
    
	if (s.size() == 0 ) return MAX_BOOK;
    if (s[0] == '-')
        flag = true;
    else if (s[0] >= '0' && s[0] <= '9')
        x = ( s[0] - '0' );
    else
        return MAX_BOOK;
    
    for ( i = 1; i < s.length(); ++i )
        if (s[i] >= '0' && s[i] <= '9')
            x = x * 10 + ( s[i] - '0' );
        else
            return MAX_BOOK; 
            
    if (flag) x = -x;
            
    return (x);
}
