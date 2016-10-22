/***************************************************
  �ļ�: Reader.h
  ���ã�Library.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;���û�Reader�࣬�̳���Teacher, Student
  ���룺Date Month User
***************************************************/
#pragma once
#include <iostream>
using namespace std;

class Reader {
	friend class Library;
	
private:
	static const int LISTMAX = 10;			//���������Ĳ���
	int ID, Borrowed;							//���, ���Ĳ���
	string Name, Dept, Password, Super;			//��������λ�����룬�ۺ�
	string *KEY[4];								//���ڹؼ��ֲ�ѯ
	int List[LISTMAX];							//�鼮�б�

	void Insert( int x );						//��������
	int Find( int x );							//��������
	void Del( int x );							//ɾ������

protected:
	int MAX;									//ÿ���˲�ͬ�Ľ������

public:
	int Type;

	Reader() : Borrowed(0), ID(0) { KEY[0] = &Name; KEY[1] = &Dept; KEY[2] = &Super; };

	//�麯����
	//��ʦ��
	virtual int GetAN( void ) { return 0; }
	virtual int GetAID( void ) { return 0; }

	virtual bool Order( int x ) { return false; }
	virtual void CancelAppoint( void ) { return; }

	//����Ա��
	virtual int GetManageAdmin() { return 0; }
	virtual int GetManageUser() { return 0; }
	virtual int GetManageBook() { return 0; }
	virtual int GetManageBorrow() { return 0; }

	virtual void SetManageAdmin( int x ) { }
	virtual void SetManageUser( int x ){ }
	virtual void SetManageBook( int x ) { }
	virtual void SetManageBorrow( int x ) { }

	//��ķ�װ
	string GetName() { return Name; }
	string GetDept() { return Dept; }
	string GetPW() { return Password; }

	int GetID() { return ID; }
	int GetType() { return Type; }
	int GetBorrowed() { return Borrowed; }
	int GetBook(int x) { return List[x]; }
	const string GetKEY( int x ) { return *KEY[x]; }

	void SetType( int NewType ) { Type = NewType; };
	void SetID( int NewID ) { ID = NewID; };
	void SetName( string NewName ) { Name = NewName; };
	void SetDept( string NewDept )	{ Dept = NewDept; };
	void SetPassword( string NewPW ) { Password = NewPW; };
	void SetBorrowed( int NewBorrowed ) { Borrowed = NewBorrowed; };

	//���顢���顢չʾ
	bool Borrow( int id );
	bool Return( int id );
	void Show();
	void Display();
};

class Teacher : public Reader {
private:
	int AppointNum;			//ԤԼ����
	int AppointID;			//ԤԼ���

public:
	Teacher();
	bool Order( int x );	//ԤԼ
	int GetAN();			//�õ�ԤԼ����
	int GetAID();			//�õ�ԤԼ���
	void CancelAppoint( void );	//ȡ��ԤԼ
};


class Student : public Reader {
private:

public:
	Student () { MAX = 5; }
	bool Order( int x ) { return false; }
};