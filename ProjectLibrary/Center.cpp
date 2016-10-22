/***************************************************
  文件: Center.cpp
  引用：Library.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：个人信息中心
  构想：MD5 实现
***************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Library.h"
#include "MDStarea.h"
using namespace std;

//读者类型转换函数
string TypeTrans( int x ){
	switch (x){
		case 0:		return "超级管理员";
		case 1:		return "管理员";
		case 2:		return "教师";
		case 3:		return "学生";
		default:	return "游客";
	}
}

//展示某一位读者
void Library::ShowUser( int x ){

	if ( x != -1 && UserExist[x] ){
		User[0] = I;
		I = User[x];
	}
	
	cout << "○ 您的姓名：" << I->GetName() << endl; 
	cout << "○ 您的密码：" << I->GetPW() << " (已经过星海碧空MDStarea算法加密)" << endl; 
	cout << "○ 您的工作单位：" << I->GetDept() << endl; 
	cout << "○ 您的用户类型：" << TypeTrans( I->GetType() ) << endl; 
	cout << "○ 您借阅的书籍个数：" << I->GetBorrowed() << endl; 
	
	if ( I->GetBorrowed() > 0 ) 
			BannerBook();
		for ( int i = 0; i < I->GetBorrowed (); ++i ){
			Books[ I->GetBook ( i ) / 10 ].Display();
		}

		if ( I->GetType() < 3 ){
			cout << "○ 您预约的书籍个数：" << I->GetAN() << endl; 
			for ( int i = 0; i < I->GetAN(); ++i ) {
				BannerBook();
				Books[ I->GetAID() / 10 ].Display();
			}
		}

	if ( x != -1 && UserExist[x] ) I = User[0];
}

void Library::SetMyName(){
	string str;
	cout << "★ 请输入新的用户名："; 
	getline(cin, str); 
	I->SetName ( str );
}

void Library::SetMyPW(){
	string str;
	cout << "★ 请输入新密码：";
	getline(cin, str);
	I->SetPassword ( MDStarea(str) ); 
}

void Library::SetMyDept(){
	string str;
	cout << "★ 请输入新工作单位：" ; 
	getline(cin, str); 
	I->SetDept ( str ); 
}

