/***************************************************
  文件: Manage.cpp
  引用：Library.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：统筹借书、预约、还书服务
  构想：Date Month User
***************************************************/

#pragma once
#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

// 交换两本书
void Library::Swap( int a, int b) {
	SBook[MAX_BOOK] = SBook[a];
	SBook[a] = SBook[b];
	SBook[b] = SBook[MAX_BOOK];
}

// 快速排序
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

// 按照特定关键字排序
void Library::Sort( int x ) {
	BookKey = x; 
	Qsort( 0, BookResult - 1 );
}

//获得用户输入的整数,MAX_BOOK作为错误码。
int Library::Readln( int l ,int r ){
    int x;
	string str;
    do {
		getline( cin, str ) ;
        x = Val(str);
		if (x == MAX_BOOK) cout << "☆ 您输入的信息偶看不懂~~ @_@ ，请您重新输入！" << endl;  
        else if (x < l || x > r) x = MAX_BOOK;
    } while (x == MAX_BOOK);
    
    return (x);
}

//字符串转换成数字的函数 
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
