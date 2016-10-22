/***************************************************
  文件: Book.h
  引用：BookResource.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：每本书单册信息
  构想：Date Month User
***************************************************/

#pragma once
#include "BookResource.h"
using namespace std;

class Book {
	   friend class BookResource;
	   friend class Library;

private:
    int State;  	// 图书状态：0. 可外借  1.  已出借   2. 被预约  3. 仅阅览  4.购买中...
	int UserID;		// 借阅者ID
	int OrderID;	// 预订者ID

public:
	int ID;			// 图书在BookResource里的编号
	Book() : State(0), ID(0), UserID(0), OrderID(0) {}
};
