/***************************************************
  文件: Login.cpp
  引用：Library.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：登录
  构想：MD5
***************************************************/
#pragma once
#include <iostream>
#include <conio.h>
#include "Library.h"
#include "Administrator.h"
#include "Reader.h"
#include "MDStarea.h"
using namespace std;
  
//定位读者
int Library::UserLocate ( string UserName ){
	for (int  i = 1; i <= UserTotal; ++i )
		if ( User[i]->GetName() == UserName )
			return i;
	
	return -1;
}

//登录
bool Library::Login(){

	int ID;
	char ch;
	string UserName, UserPW, UserCode ;
	

	CodeChecker.Generate ();

	cout << "★ 请输入用户名：";		getline(cin, UserName);
	cout << "★ 请输入密码：";			while( ( ch = getch() ) != 0x0d ){ cout << "*";  UserPW = UserPW + ch; } cout << endl;
	CodeChecker.ShowPic ();
	cout << "★ 请输入验证码：";		getline(cin, UserCode);
	


	ID = UserLocate( UserName );		//定位用户名
	if ( ID == -1 ) return false;
	if ( User[ID]->GetName() == UserName && User[ID]->GetPW() == MDStarea(UserPW) ){
		if ( CodeChecker.Check( UserCode ) ) {
			I = User[ID];
			return true;
		} else {
			cout << "▲ 验证码错误~~ " << endl;
			return false;
		}
	} else return false;
}