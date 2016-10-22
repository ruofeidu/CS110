/***************************************************
  �ļ�: BookResouce.h
  ���ã�Library.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;��ÿ�����ISBN����Ϣ
  ���룺Date Month User
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
	static const int BOOKMAX = 6;					//��󵥲���Ŀ
	static const int error_code = 555555;			//������
	int Copy, Borrowed, Ordered;					//���������������ԤԼ��

	string ISBN, Title, Author, Query, ID, Category, Super;	//ISBN�����������ߣ�����ţ���ţ����࣬�ۺ�
	string *KEY[7];											//�ؼ���
	Book List[BOOKMAX];										//������Ϣ
	
public:
	BookResource ( void ) :Borrowed(0), Copy(0) { KEY[0] = &Title; KEY[1] = &ISBN; KEY[2] = &Author; KEY[3] = &Query; KEY[4] = &Category; KEY[5] = &ID; KEY[6] = &Super; }

	//��ķ�װ����ֻ������
	const int GetCopy() const { return Copy; }
	const int GetBorrowed() const { return Borrowed; }
	const int GetOrdered() const { return Ordered; }
	const int GetState( int x ) const { return List[x].State; }
	const string GetISBN() const { return ISBN; }
	const string GetTitle() const { return Title; }
	const string GetAuthor() const { return Author; }
	const string GetID() const { return ID; }
	const string GetKEY( int x ) { return *KEY[x]; }

	//��ķ�װ������д����
	void SetID ( const string newID )	{ ID = newID; }
	void SetISBN ( const string newISBN )	{ ISBN = newISBN; }
	void SetTitle ( const string newTitle ) { Title = newTitle; }
	void SetAuthor( const string newAuthor ) { Author = newAuthor; }
	void SetQuery( const string newQuery ) { Query = newQuery; }
	void SetCopy ( const int newCopy )		{ Copy = newCopy; }
	void SetBorrowed ( const int newBorrowed ) { Borrowed = newBorrowed; }
	void SetOrdered ( const int newOrdered ) { Ordered = newOrdered; }

	//��ķ���
	void Lend( int y , int UID);
	void Return( int y );
	void Cancel( int y );
	void LendOrder( int y, int UID);
	void Insert( int State, int ID, int UserID, int OrderID );
	void Del( int ID );
	void Show();
	void Display();
	string StatePrint( int x );
	
	//��ĳ�ʼ������������ŵȡ�
	void BuildID();
	int val(string s);
};
