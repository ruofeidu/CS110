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
#include <conio.h>
#include <string>
#include "Library.h"
#include "MDStarea.h"
using namespace std;

//添加读者
void Library::AddUser(){
	string UserName, UserPW, UserDept;
	int UserID, UserType;
	char ch;

	++UserTotal; 
	UserID = UserTotal;

	cout << "◇ 请输入新读者类别：";
	UserType = Readln(0, 3);
	switch (UserType) {
		case 1:		User[UserID] = &Admins[AdminTotal++];		break;
		case 2:		User[UserID] = &Teachers[TeacherTotal++];	break;
		case 3:		User[UserID] = &Students[StudentTotal++];	break;
		default:	cout << "◇ 请输入0-3的数字，禁止增加超级管理员！返回~ "; return;  break; 
	}

	cout << "◇ 请输入新读者姓名：";  getline( cin, UserName); 
	cout << "◇ 请输入新读者密码：";  while( ( ch = getch() ) != 0x0d ){ cout << "*";  UserPW = UserPW + ch; } cout << endl;
	cout << "◇ 请输入新读者工作单位：";  getline( cin, UserDept );
	
	UserExist[UserID] = true; 
	User[UserID]->SetID ( UserID );
	User[UserID]->SetType ( UserType );
	User[UserID]->SetName ( UserName );
	User[UserID]->SetDept ( UserDept );
	User[UserID]->SetPassword ( MDStarea(UserPW) );

	History[HisNum++]= "★ 管理员" + I->GetName() + "添加新读者" + User[UserID]->GetName();  
}

// 删除读者
void Library::DeleteUser(){
	int x, y; 

	cout << "◇ 请输入要删除的读者ID:" << endl;
	x = Readln( 1, UserTotal ); 
	if ( x == 0 ) { cout << "▲ 禁止删除超级管理员！！！"; system("pause"); return; }
		if (! UserExist[x] ) { cout << "▲ 出错啦~~ 这个人不存在" << endl;  system("pause"); return; }
		else { User[x]->Display(); cout << "◇ 您确定要删除这个人吗？输入 1 确定删除，0 取消操作~ " << endl; }
	y = Readln( 0, 1); 
	if ( y == 1 ) {
		UserExist[x] = false;
		History[HisNum++]= "★ 管理员" + I->GetName() + "删除读者" + User[x]->GetName();  
	}
}

// 展示管理员
void Library::ShowAdmin(){
	for ( int i = 0; i < AdminTotal; ++i ){
		cout << "编号" << i << "："; 
		Admins[i].Display();
	}
}

// 编辑管理员
void Library::EditAdmin(){
	int x, y; 
	cout << "☆ 请输入要编辑的管理员编号:" << endl;
	x = Readln( 0, AdminTotal - 1);
				 
	Admins[x].Display(); 
	cout << "◇ 您确定要编辑这个人吗？输入 1 确定编辑，0 取消操作~ " << endl; 
	cout << "权限管理" << '\t' << "读者管理" << '\t' << "书目管理" << '\t' << "流通管理" << endl; 
	cout << Admins[x].GetManageAdmin () << "\t\t" << Admins[x].GetManageBook() << "\t\t" << Admins[x].GetManageBorrow() << "\t\t" << Admins[x].GetManageUser() << endl;
	y = Readln( 0, 1); 
	if ( y != 1 ) return;

	cout << "◇ 请输入该管理员能否访问权限管理？ ( 1：能 0：不能)："; x = Readln( 0, 1); Admins[x].SetManageAdmin(x);
	cout << "◇ 请输入该管理员能否访问读者管理？ ( 1：能 0：不能)："; x = Readln( 0, 1); Admins[x].SetManageUser(x);
	cout << "◇ 请输入该管理员能否访问书目管理？ ( 1：能 0：不能)："; x = Readln( 0, 1); Admins[x].SetManageBook(x);
	cout << "◇ 请输入该管理员能否访问流通管理？ ( 1：能 0：不能)："; x = Readln( 0, 1); Admins[x].SetManageBorrow(x);
	History[HisNum++]= "★ 管理员" + I->GetName() + "编辑管理员权限" + Admins[x].GetName();  
}

//编辑读者
void Library::EditUser(){
	string UserName, UserPW, UserDept;
	int UserID, UserType;

	int x, y; 

	cout << "◇ 请输入要编辑的读者ID:";
	x = Readln( 1, UserTotal ); 
	if (! UserExist[x] ) cout << "▲ 出错啦~~ 这个人不存在" << endl; 
		else { User[x]->Display(); cout << "◇ 您确定要编辑这个人吗？输入 1 确定编辑，0 取消操作~ " << endl; }
	y = Readln( 0, 1 );
	if ( y != 1 ) return;

	UserID = x;

	cout << "◇ 请输入新读者类别："; UserType = Readln( 0,3 );
	switch (UserType) {
		case 1:		User[UserID] = &Admins[AdminTotal++];		break;
		case 2:		User[UserID] = &Teachers[TeacherTotal++];	break;
		case 3:		User[UserID] = &Students[StudentTotal++];	break;
		default:	cout << "▲ 请输入0-3的数字，禁止增加超级管理员！返回~ "; return;  break; 
	}

	cout << "◇ 请输入该读者新姓名：";		getline( cin, UserName ); 
	cout << "◇ 请输入该读者新密码：";		getline( cin, UserPW );
	cout << "◇ 请输入该读者新工作单位：";  getline( cin, UserDept ); 
	
	UserExist[UserID] = true; 
	User[UserID]->SetID ( UserID );
	User[UserID]->SetType ( UserType );
	User[UserID]->SetName ( UserName );
	User[UserID]->SetDept ( UserDept );
	User[UserID]->SetPassword ( MDStarea(UserPW) );

	History[HisNum++]= "★ 管理员" + I->GetName() + "编辑读者" + User[UserID]->GetName();  
}

// 添加书籍
void Library::AddBook(){	
	string x;
	int y; 
	cout << "☆ 请输入新书的ISBN：";			getline( cin, x ); Books[BookTotal].SetISBN(x);
	cout << "☆ 请输入新书的标题：";			getline( cin, x ); Books[BookTotal].SetTitle(x); 
	cout << "☆ 请输入新书的作者：";			getline( cin, x ); Books[BookTotal].SetAuthor(x); 
	cout << "☆ 请输入新书的索书号：";			getline( cin, x ); Books[BookTotal].SetQuery(x); 
	cout << "☆ 请输入新书的复本数：";			y = Readln(1, 5 ); Books[BookTotal].SetCopy(y) ;
	
	for ( int i = 0; i < Books[BookTotal].GetCopy() ; ++i ) Books[BookTotal].Insert( 0, i + 1 , 0, 0 );

	//处理新书的分类号和数字编号
	Books[BookTotal].BuildID();
	BannerBook();
	Books[BookTotal].Display();
	BookExist[BookTotal] = true;
	
	History[HisNum++]= "★ 管理员" + I->GetName() + "添加书籍" + Books[BookTotal].GetTitle();  
	
	++BookTotal;
}

// 删除书籍
void Library::DeleteBook(){
	string x; 
	int ans;

	cout << "☆ 请输入要删除书的ISBN编号：";
	getline( cin, x );
	int i = LocateBook(x);
	if ( i != -1 ) {
		cout << "★ 这本书是：" << endl;
		BannerBook();
		Books[i].Display();  
		cout << "☆ 您确定要删除吗？ ( 1 是 0 否 ) ";
		ans = Readln(0,1);
		if ( ans == 1) KillBook(i); else return;
		cout << "☆ 删除成功！" << endl; 
		History[HisNum++]= "★ 管理员" + I->GetName() + "删除书籍" + Books[i].GetTitle(); 
	} else
		cout << "☆ 删除失败！" << endl; 

	system("pause");
}

// 编辑书
void Library::EditBook(){
	string x;
	int y;
	cout << "☆ 请输入要编辑的书的ISBN编号：";
	getline( cin, x);
	int i = LocateBook(x);
	if ( i != -1 ) {
		BannerBook();
		Books[i].Display();
		cout << "☆ 请输入这本书新的ISBN：";			getline(cin, x); Books[i].SetISBN(x);
		cout << "☆ 请输入这本书新的标题：";			getline(cin, x); Books[i].SetTitle(x); 
		cout << "☆ 请输入这本书新的作者：";			getline(cin, x); Books[i].SetAuthor(x); 
		cout << "☆ 请输入这本书新的索书号：";			getline(cin, x); Books[i].SetQuery(x); 
		cout << "☆ 请输入这本书新的复本数：";			y = Readln( 1, 5); 
		if (y < Books[i].GetCopy() ) 
			for ( int j = y; j < Books[i].GetCopy(); ++j ) Books[i].Del(j);
		else for ( int j = Books[i].GetCopy(); j < y; ++j ) Books[i].Insert( 0, 1, 0, 0 );
		Books[i].SetCopy(y);
		cout << "★ 编辑成功！" << endl;
		BannerBook();
		Books[i].Display();
		History[HisNum++]= "★ 管理员" + I->GetName() + "编辑书籍" + Books[i].GetTitle(); 
	}
}

//设置图书和读者的关键字查询类别
void Library::SetBookKey( int x ) { BookKey = x; }
void Library::SetUserKey( int x ) { UserKey = x; }

void Library::KillBook( int i ){
	BookExist[i] = 0; 
}

// 定位书籍
int Library::LocateBook( string x ){
	for ( int i = 0; i < BookTotal; ++i ) if ( Books[i].GetISBN() == x ) return i;
	cout << "★ 您所查找的这本书不存在！请确认ISBN无误。" << endl; 
	return -1; 
}

// 定位读者
int Library::LocateUser( int x ) {
	for ( int i = 1; i <= BookTotal; ++i ) if ( User[i]->GetID() == x ) return i; 
	return -1;
}

