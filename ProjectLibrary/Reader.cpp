/***************************************************
  文件: Reader.cpp
  引用：Reader.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：读者操作实现
  构想：Date Month User
***************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Reader.h"
using namespace std; 

// 删除读者借阅的书籍
void Reader::Del( int x ){
	for ( int i = 0; i < Borrowed; ++i )
		if ( List[i] == x ) {
			for ( int j = i; j < Borrowed - 1; ++j )
				List[j] = List[j+1];
			break;
		}
}

// 插入读者新借阅的书籍
void Reader::Insert( int x ) {
	List[Borrowed++] = x;
}

// 查找读者是否借阅过某本书
int Reader::Find( int x ) {
	for ( int i = 0; i < Borrowed; ++i )
		if ( List[i] == x ) return i;
	return -1;
}

// 借阅第id本书籍
bool Reader::Borrow( int id ) {
	//if ( Find(id) != -1 ) { cout << "您借过这本书哦~" << endl; return false; }
	if ( Borrowed == MAX ) return false; else Insert( id );
	return true;
}

// 归还第id本书籍，代码更新：先判断能否还书再决定还不还……
bool Reader::Return( int id ) {
	Del( id );
	--Borrowed;
	cout << "★ 还书成功！" << endl;
	return true;
	/*
	if ( Find( id ) ){
		Del( id );
		--Borrowed;
		cout << "★ 还书成功！" << endl;
		return true;
	} else {
		cout << "★ 还书失败！您可能没借过这本书！" << endl; 
		return false;
	}*/
}

// 展示读者借阅的书籍
void Reader::Show() {
	cout << endl;
	cout << "○ 您当前所借的" << Borrowed << "本书的ISBN分别为：" << endl; 
		
	for ( int i = 0; i < Borrowed; ++i )
		cout << "→ " << List[i] / 10 << "的第" << List[i] % 10 << "本复本" << endl;
	cout << endl;
}

// 读者类型转换成文本
string TransType( int x )
{
	switch (x){
		case 0:		return "超级管理员";
		case 1:		return "管理员\t";
		case 2:		return "教师\t";
		case 3:		return "学生\t";
		default:	return "游客\t";
	}
}

// 读者信息展示
void Reader::Display(){
	cout << ID << '\t' << Name << '\t' << Dept;
	if (Dept.size() < 8) cout << '\t';
	cout << '\t' << TransType(Type) << '\t' << Borrowed << '\t' << endl;
}
