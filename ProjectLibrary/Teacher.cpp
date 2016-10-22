/***************************************************
  文件: Teacher.cpp
  引用：Reader.h
  用途：教师信息
  构想：Date Month User
***************************************************/
#pragma once
#include "Reader.h"

// 构造函数
Teacher::Teacher(){ 
	MAX = 10;
	AppointNum = 0;
	AppointID = 0;
}

// 教师预约
bool Teacher::Order( int x ) {
	if ( Type == 3 ) return false;
	if ( AppointNum == 0 ) {
		++AppointNum;
		AppointID = x;
	return true;
	} else return false; 
}

// 取得预约书籍数量
int Teacher::GetAN(){
	return AppointNum; 
}

// 取得预约书籍编号 
// 编号= ISBN + 单册编号
int Teacher::GetAID(){
	return AppointID;
}

// 取消预约
void Teacher::CancelAppoint( void ) { 
	AppointNum = 0;
}