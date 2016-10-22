/***************************************************
  文件: Input.cpp
  引用：Library.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：输入模块
  构想：历史记录
***************************************************/
#pragma once
#include <fstream>
#include <string>
#include "Library.h"
#include "BookResource.h"
#include "Book.h"
#include "Reader.h"
using namespace std;

void Library::Input(){
	string UserName, UserPW, UserDept, ID;
	int UserID, UserType, UserBorrow, i, BookID, x;

	ifstream fin;
	fin.open ( "System.ini" );
	fin >> DataBaseName >> UserFileName >> ManageFileName;
	fin.close();

	
	// 从读者文件中读入读者信息
	fin.clear();
	fin.open ( UserFileName );
	fin >> UserTotal; 
	for (int k = 0; k < UserTotal; ++k ) {
		fin >> UserID >> UserType >> UserName >> UserPW >> UserDept >> UserBorrow;
		switch ( UserType ) {
			case 0:		User[UserID] = &Root; break;
			case 1:		User[UserID] = &Admins[AdminTotal++];		break;
			case 2:		User[UserID] = &Teachers[TeacherTotal++];	break;
			case 3:		User[UserID] = &Students[StudentTotal++];	break;
		}

		UserExist[UserID] = true; 
		User[UserID]->SetID ( UserID );
		User[UserID]->SetType ( UserType );
		User[UserID]->SetName ( UserName );
		User[UserID]->SetDept ( UserDept );
		User[UserID]->SetPassword ( UserPW );

		//读入读者借的每一本书
		for ( i = 0; i < UserBorrow; ++i ){
			fin >> BookID;
			User[UserID]->Borrow ( BookID );
		}

		//读入读者预约的书
		if ( UserType < 3 ){	
			fin >> UserBorrow;
			if ( UserBorrow == 1 ) {
				fin >> BookID;
				User[UserID]->Order ( BookID );
			}
		}

		//读入管理员权限
		if ( UserType < 2 ){
			fin >> x; User[UserID]->SetManageAdmin(x);
			fin >> x; User[UserID]->SetManageUser(x);
			fin >> x; User[UserID]->SetManageBook(x);
			fin >> x; User[UserID]->SetManageBorrow(x);
		}
	}

	
	// 从书籍数据库读入书本
	BookTotal = 0;
	fin.close ();
	fin.clear ();
	fin.open ( DataBaseName );
	i = fin.peek();

	while ( fin.peek() != EOF ) {
		char str[100];
		fin.getline( str, 100, '\t' );	Books[BookTotal].ISBN = str;
		fin.getline( str, 100, '\t' );	Books[BookTotal].Title = str;
		fin.getline( str, 100, '\t' );	Books[BookTotal].Author = str;
		fin.getline( str, 100, '\t' );	Books[BookTotal].Query = str;
		fin >> Books[BookTotal].Copy ;
		for ( int i = 0; i < Books[BookTotal].Copy ; ++i ) {
			fin >> Books[BookTotal].List[i].State >> Books[BookTotal].List[i].ID >> Books[BookTotal].List[i].UserID >> Books[BookTotal].List[i].OrderID;
		}
		fin.getline ( str ,100 );
		
		//处理分类号,数字编号,模糊智能搜索
		Books[BookTotal].BuildID();
		BookExist[BookTotal] = true;
		++BookTotal;
	}
	fin.close();

	// 读入历史记录文件
	fin.clear ();
	fin >> HisNum; getline( fin, History[0] );
	for ( int i = 0; i < HisNum; ++i ) getline ( fin, History[i] );
	fin.close();

	InitSBook();
	InitSUser();
}
	
