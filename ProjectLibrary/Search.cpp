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

void Library::InitSBook (){
	 for ( int i = 0; i < MAX_BOOK; ++i  )
		SBook[i] = &Books[i];
		BookResult = BookTotal;
}

void Library::InitSUser (){
	for ( int i = 0; i < MAX_USER; ++i  ) if ( UserExist[i] ) { 
		++UserResult; 
		SUser[i] = User[i]; 
	} 
	memset(Flag, false, sizeof(Flag)); 
}

void Library::Findout( string task ){
	const int MAXRES = 40000;
	const int MAXCUT = 2000000;
	string a, b; 
	unsigned int i, j, cut = 0;
	if ( !FindMode ) memset( Flag, true , sizeof(Flag) ); 

	BookResult = 0;
	if ( task.find( "=" , 0 ) != string::npos ) SetBookKey(6);	//智能搜索
		else if ( BookKey == 6 ) BookKey = 0;

	i = task.find( "AND", 0 ); 
	if ( i != string::npos ) {
		a = task.substr ( 0, i - 1 );
		b = task.substr ( i + 4 ); 
		return FindoutAND( a, b ); 
	}

	i = task.find( "OR", 0 ); 
	if ( i != string::npos ) {
		a = task.substr ( 0, i - 1 );
		b = task.substr ( i + 4 ); 
		return FindoutOR( a, b );
	}

	i = task.find( "EX", 0 ); 
	if ( i != string::npos ) {
		a = task.substr ( 0, i - 1 );
		b = task.substr ( i + 4 ); 
		return FindoutEX( a, b );
	}

	i = task.find( "NOT", 0 ); 
	if ( i != string::npos ) {
		b = task.substr ( i + 4 ); 
		return FindoutNOT( b );
	}

	//优先级最高的完全匹配
	for (int i = 0; i < BookTotal; ++i) if (BookExist[i]){	
		if ((FindMode ^ Flag[i]) && Books[i].GetKEY(BookKey) == task) {
			SBook[BookResult++] = &Books[i];
			Flag[i] = false;
		}
	}

	// 连续子串匹配
	string sink;							// 枚举不同长度的子串
	int MINLEN = 0;							// 最小长度，便于表达式检索
	if ( BookKey == 6 ) MINLEN = 4;			// 开启表达式智能检索
	for ( i = task.length(); BookResult < MAXRES && i > MINLEN; --i )									//起始
		for ( j = 0; BookResult < MAXRES && j + i < task.length(); ++j ) {								//结束
			sink = ""; cut += BookTotal; if ( cut > MAXCUT ) break;							//智能表达式检索用
			for (int k = j; k <= j + i; ++k ) sink += task[k];									//提取
			for (int k = 0; BookResult < MAXRES && k < BookTotal; ++k )if (BookExist[k]){				//搜索
				if ((FindMode ^ Flag[k]) && Books[k].GetKEY(BookKey).find(sink,0) != string::npos) {
					SBook[BookResult++] = &Books[k];
					Flag[k] = false;
				}

			}
		} 
}

// AND
void Library::FindoutAND( string a, string b ){
	cout << Flag[0] << FindMode << endl;

	for (int i = 0; i < BookTotal; ++i)
		if ( (FindMode ^ Flag[i]) && ( Books[i].GetKEY(BookKey).find( a , 0 ) != string::npos && Books[i].GetKEY(BookKey).find( b, 0 ) != string::npos ) ) {
			SBook[BookResult++] = &Books[i];
			Flag[i] = false;
		}  
}

// OR
void Library::FindoutOR( string a, string b ){
	for (int i = 0; i < BookTotal; ++i)
		if ( (FindMode ^ Flag[i]) && ( Books[i].GetKEY(BookKey).find( a , 0 ) != string::npos || Books[i].GetKEY(BookKey).find( b, 0 ) != string::npos ) ) {
			SBook[BookResult++] = &Books[i];
			Flag[i] = false;
		}  
}

// EX
void Library::FindoutEX( string a, string b ){
	for (int i = 0; i < BookTotal; ++i)
		if ( (FindMode ^ Flag[i]) && Books[i].GetKEY(BookKey).find( a , 0 ) != string::npos && Books[i].GetKEY(BookKey).find( b, 0 ) == string::npos) {
			SBook[BookResult++] = &Books[i];
			Flag[i] = false;
		}  
}

// NOT
void Library::FindoutNOT( string b ){
	for (int i = 0; i < BookTotal; ++i)
		if ( (FindMode ^ Flag[i]) && Books[i].GetKEY(BookKey).find( b, 0 ) == string::npos) {
			SBook[BookResult++] = &Books[i];
			Flag[i] = false;
		}  
}



void Library::FindoutUser( string task ){
	string a, b; 
	int i, j, cut = 0;
	memset( Flag, true , sizeof(Flag) ); 

	UserResult = 0;

	//cout << "★完全匹配：" << endl;
	for (i = 1; i <= UserTotal; ++i) if ( UserExist[i] )
		if (Flag[i] && User[i]->GetKEY(UserKey) == task) {
			SUser[UserResult++] = User[i];
			Flag[i] = false;
		}  

	string sink;   //枚举不同长度的子串
	//cout << "★连续子串匹配：" << endl;
	for ( i = task.length() - 1; i >= 0; --i )
		for ( j = 0; j + i < task.length(); ++j ) {
			sink = "";
			for (int k = j; k <= j + i; ++k ) sink += task[k];
			for (int k = 1; k <= UserTotal; ++k ) if ( UserExist[k] )
				if (Flag[k] && User[k]->GetKEY(UserKey).find(sink,0) != string::npos) {
					SUser[UserResult++] = User[k];
					Flag[k] = false;
				}
		} 
		
}

string Library::GetFindMode(){
	if ( FindMode == 1 ) return ("开"); else return ("关");
}

void Library::SetFindMode( int x ) {
	if ( x == 1 ) FindMode = true; else FindMode = false; 
}

int Library::GetBookResult (){
	return BookResult;
}

int Library::GetUserResult (){
	return UserResult;
}

string Library::GetBookSMode(){
	switch( BookKey ){
		case 0:		return "书名查询）  ";
		case 1:		return "ISBN查询）  ";
		case 2:		return "作者查询）  ";
		case 3:		return "索书号查询）";
		case 4:		return "类别查询）  ";
		case 5:		return "编号查询）  ";
		default:	return "智能表达式）";
	}
}

string Library::GetUserSMode(){
	switch( UserKey ){
		case 0:		return "姓名";
		case 1:		return "单位";
		default:	return "智能";
	}
}

void Library::SetUserSMode(){
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
	cout << "┃                                                                          ┃" << endl;
	cout << "┃  请输入查询类别：                                                        ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃      【 0 】按 姓名 查询                                                 ┃" << endl;
	cout << "┃      【 1 】按 单位 查询                                                 ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	int i = Readln( 0, 1 ); 
	SetUserKey( i ); 
	cout << "★ 设置成功！" << endl;
	system("pause");
}