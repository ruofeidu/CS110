/***************************************************
  文件: BookResouce.cpp
  引用：BookResouce.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：每套书的ISBN等信息
  构想：Date Month User
***************************************************/
#pragma once
#include <iostream>
#include "BookResource.h"
#include "Book.h"
using namespace std;

//借书
void BookResource::Lend( int y , int UID){
	++Borrowed;
	List[y].State = 1; 
	List[y].UserID = UID; 
}

//还书
void BookResource::Return( int y ){
	--Borrowed;
	Cancel(y);
}

//取消预约
void BookResource::Cancel( int y ){
	List[y].State = 0;
}

//预约
void BookResource::LendOrder( int y, int UID){
	List[y].State = 2;
	List[y].OrderID = UID;
}

//建立索书号
void BookResource::BuildID(){
	int pos = Query.find('-',0);
	Category = Query.substr ( 0, pos ); 
	ID = Query.substr ( pos + 1, Query.size() - pos ); 
	Super = "ISBN=" + ISBN + "书名=" + Title + "作者=" + Author + "类别=" + Category + "编号=" + ID + "索书号" + Query;
}

//插入新单册
void BookResource::Insert( int State, int ID, int UserID, int OrderID ) {
	List[ID-1].State = State;
	List[ID-1].ID = ID;
	List[ID-1].UserID = UserID;
	List[ID-1].OrderID = OrderID;
}

//删除单册
void BookResource::Del( int ID ){
	for ( int i = 0; i < Copy; ++i )
		if ( List[i].ID == ID ) {
			for ( int j = i; j < Copy - 1; ++j )
				List[j] = List[j+1];
			break;
		}
}

//打印每本书状态
string BookResource::StatePrint( int x ){
	switch ( x ) {
		case 0: return "可借阅。"; break;
		case 1: return "已出借。"; break;
		case 2: return "被预约。"; break; 
		case 3: return "仅阅览。"; break;
		default: return "购买中。"; break;
	}
}

//显示这本书每本单册情况
void BookResource::Show() {
	for ( int i = 0; i < Copy ; ++i ) {
		cout << "ISBN为" << ISBN << "的第" << i + 1 << "本书" << StatePrint( List[i].State );
		if ( List[i].State == 1 ) cout << "借阅者ID：" << List[i].UserID ;
		if ( List[i].State == 2 ) cout << "预约者ID：" << List[i].UserID ; 
		cout << endl;
	}
}

//展示一本书
void BookResource::Display() {
	cout << ISBN << '\t' << Title << '\t';
	if ( Title.size() < 24 ) cout << '\t';
	if ( Title.size() < 16 ) cout << '\t';
	if ( Title.size() < 8 ) cout << '\t';
	cout << Author;
	if ( Author.size() < 8 ) cout << '\t';
	cout << '\t' <<  Category << '\t' << ID << '\t' << Copy << endl;
}

//字符串变数字
int BookResource::val(string s) {
	int x = 0;
	unsigned int i;
	bool flag = false;
    
	if (s[0] == '-')
		flag = true;
	else if (s[0] >= '0' && s[0] <= '9')
		x = ( s[0] - '0' );
	else
		return (error_code);
    
	for ( i = 1; i < s.length(); ++i )
		if (s[i] >= '0' && s[i] <= '9')
			x = x * 10 + ( s[i] - '0' );
		else
			return (error_code); 
            
	if (flag) x = -x;
            
	return (x);
}
