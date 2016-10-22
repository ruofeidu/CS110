/***************************************************
  文件: Reader.h
  引用：Library.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：用户Reader类，继承类Teacher, Student
  构想：Date Month User
***************************************************/
#pragma once
#include <iostream>
using namespace std;

class Reader {
	friend class Library;
	
private:
	static const int LISTMAX = 10;			//个人最大借阅册数
	int ID, Borrowed;							//编号, 借阅册数
	string Name, Dept, Password, Super;			//姓名，单位，密码，综合
	string *KEY[4];								//便于关键字查询
	int List[LISTMAX];							//书籍列表

	void Insert( int x );						//插入新书
	int Find( int x );							//查找新书
	void Del( int x );							//删除新书

protected:
	int MAX;									//每个人不同的借书个数

public:
	int Type;

	Reader() : Borrowed(0), ID(0) { KEY[0] = &Name; KEY[1] = &Dept; KEY[2] = &Super; };

	//虚函数们
	//教师用
	virtual int GetAN( void ) { return 0; }
	virtual int GetAID( void ) { return 0; }

	virtual bool Order( int x ) { return false; }
	virtual void CancelAppoint( void ) { return; }

	//管理员用
	virtual int GetManageAdmin() { return 0; }
	virtual int GetManageUser() { return 0; }
	virtual int GetManageBook() { return 0; }
	virtual int GetManageBorrow() { return 0; }

	virtual void SetManageAdmin( int x ) { }
	virtual void SetManageUser( int x ){ }
	virtual void SetManageBook( int x ) { }
	virtual void SetManageBorrow( int x ) { }

	//类的封装
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

	//借书、还书、展示
	bool Borrow( int id );
	bool Return( int id );
	void Show();
	void Display();
};

class Teacher : public Reader {
private:
	int AppointNum;			//预约个数
	int AppointID;			//预约编号

public:
	Teacher();
	bool Order( int x );	//预约
	int GetAN();			//得到预约个数
	int GetAID();			//得到预约编号
	void CancelAppoint( void );	//取消预约
};


class Student : public Reader {
private:

public:
	Student () { MAX = 5; }
	bool Order( int x ) { return false; }
};