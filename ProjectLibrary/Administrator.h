/***************************************************
  文件: Administrator.h
  引用：Reader.h
  用途：管理员类
  构想：继承Teacher类
***************************************************/
#pragma once
#include "Reader.h"

class Administrator : public Teacher {
private:
	//能否进入 权限管理, 读者管理, 书籍管理, 流通管理
	int ManageAdmin, ManageUser, ManageBook, ManageBorrow;

public:
	Administrator( void ):ManageAdmin(1), ManageUser(1), ManageBook(1), ManageBorrow(0){}

	// 私有变量的封装——权限管理, 读者管理, 书籍管理, 流通管理的读入和写入。
	int GetManageAdmin() { return ManageAdmin; }
	int GetManageUser() { return ManageUser; }
	int GetManageBook() { return ManageBook; }
	int GetManageBorrow() { return ManageBorrow; }

	void SetManageAdmin( int x ) { ManageAdmin = x; }
	void SetManageUser( int x ){ ManageUser = x; }
	void SetManageBook( int x ) { ManageBook = x; }
	void SetManageBorrow( int x ) { ManageBorrow = x; }
};

class SuperAdmin : public Administrator {
private:
	//能否管理数据库管理，默认能。
	int ManageDataBase;
public:
	SuperAdmin( void ) : ManageDataBase(1) {}
	int GetManageDataBase() { return ManageDataBase; }
	void SetManageDataBase( int x ) { ManageDataBase = x; }
};

