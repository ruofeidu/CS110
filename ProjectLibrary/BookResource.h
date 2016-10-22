/***************************************************
  文件: BookResouce.h
  引用：Library.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：每套书的ISBN等信息
  构想：Date Month User
***************************************************/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;

class BookResource {
	friend class Library;

private:
	static const int BOOKMAX = 6;					//最大单册数目
	static const int error_code = 555555;			//错误码
	int Copy, Borrowed, Ordered;					//复本数，借出数，预约数

	string ISBN, Title, Author, Query, ID, Category, Super;	//ISBN，书名，作者，索书号，编号，分类，综合
	string *KEY[7];											//关键字
	Book List[BOOKMAX];										//单册信息
	
public:
	BookResource ( void ) :Borrowed(0), Copy(0) { KEY[0] = &Title; KEY[1] = &ISBN; KEY[2] = &Author; KEY[3] = &Query; KEY[4] = &Category; KEY[5] = &ID; KEY[6] = &Super; }

	//类的封装——只读函数
	const int GetCopy() const { return Copy; }
	const int GetBorrowed() const { return Borrowed; }
	const int GetOrdered() const { return Ordered; }
	const int GetState( int x ) const { return List[x].State; }
	const string GetISBN() const { return ISBN; }
	const string GetTitle() const { return Title; }
	const string GetAuthor() const { return Author; }
	const string GetID() const { return ID; }
	const string GetKEY( int x ) { return *KEY[x]; }

	//类的封装——可写函数
	void SetID ( const string newID )	{ ID = newID; }
	void SetISBN ( const string newISBN )	{ ISBN = newISBN; }
	void SetTitle ( const string newTitle ) { Title = newTitle; }
	void SetAuthor( const string newAuthor ) { Author = newAuthor; }
	void SetQuery( const string newQuery ) { Query = newQuery; }
	void SetCopy ( const int newCopy )		{ Copy = newCopy; }
	void SetBorrowed ( const int newBorrowed ) { Borrowed = newBorrowed; }
	void SetOrdered ( const int newOrdered ) { Ordered = newOrdered; }

	//书的方法
	void Lend( int y , int UID);
	void Return( int y );
	void Cancel( int y );
	void LendOrder( int y, int UID);
	void Insert( int State, int ID, int UserID, int OrderID );
	void Del( int ID );
	void Show();
	void Display();
	string StatePrint( int x );
	
	//书的初始化，建立索书号等。
	void BuildID();
	int val(string s);
};
