/***************************************************
  �ļ�: Administrator.h
  ���ã�Reader.h
  ��;������Ա��
  ���룺�̳�Teacher��
***************************************************/
#pragma once
#include "Reader.h"

class Administrator : public Teacher {
private:
	//�ܷ���� Ȩ�޹���, ���߹���, �鼮����, ��ͨ����
	int ManageAdmin, ManageUser, ManageBook, ManageBorrow;

public:
	Administrator( void ):ManageAdmin(1), ManageUser(1), ManageBook(1), ManageBorrow(0){}

	// ˽�б����ķ�װ����Ȩ�޹���, ���߹���, �鼮����, ��ͨ����Ķ����д�롣
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
	//�ܷ�������ݿ����Ĭ���ܡ�
	int ManageDataBase;
public:
	SuperAdmin( void ) : ManageDataBase(1) {}
	int GetManageDataBase() { return ManageDataBase; }
	void SetManageDataBase( int x ) { ManageDataBase = x; }
};

