/***************************************************
  文件: Act.cpp
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
#include <string>
#include "Library.h"
using namespace std;

void Library::SetDataBaseName() {
	system("dir *.dat");
	Output();
	cout << "☆ 请输入新的书籍数据库名称：";
	cin.getline ( DataBaseName, 50 ); 
}

void Library::SetUserFileName() {
	system("dir *.dat");
	Output(); 
	cout << "☆ 请输入新的用户数据库名称：";
	cin.getline ( UserFileName, 50 ); 
}

void Library::SetManageFileName() {
	system("dir *.dat");
	Output(); 
	cout << "☆ 请输入新的管理数据库名称：";
	cin.getline ( ManageFileName, 50 ); 

}