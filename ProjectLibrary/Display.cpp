/***************************************************
  文件: Display.cpp
  引用：Library.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：菜单服务
  构想：Date Month User
***************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

//图书标题行
void Library::BannerBook(){
	cout << "ISBN" << '\t' << "书名" << "\t\t\t\t" << "作者" << "\t\t" << "类别" << "\t" << "编号" << '\t' << "复本数" << endl;
}

//读者标题行
void Library::BannerUser(){
	cout << "ID" << '\t' << "姓名" << '\t' << "单位" << "\t\t" << "类别" << "\t\t" << "借书个数" << endl; 
}

//彩蛋模块
void Library::ShowEgg(){
	cout<<" █　☆█　◢◤◥◣　███◣　███◣　█　☆█" << endl;
	cout<<" █▅▅█　█▄▄█　█　☆█　█　☆█　◥███" << endl;
	cout<<" █　　█　█　　█　███◤　███◤　　　　█" << endl;
	cout<<" █　　█　█　☆█　█　　　☆█　　　☆◥██◤" << endl;
	cout << "                新年快乐！                     " << endl;
}

//展示所有图书
void Library::Book_Show( int page, int items ){
	BannerBook();
	for ( int i = page; i < min( BookResult , page + items ); ++i ) if ( SBook[i] != NULL )
		SBook[i]->Display();
	cout << endl;
}

//展示所有读者
void Library::User_Show( int page, int items ){
	BannerUser();
	for ( int i = page; i < min( UserResult, page + items ); ++i ) if ( SUser[i] != NULL )		//该读者没被删除..翻页
		if ( UserExist[SUser[i]->GetID()] ) SUser[i]->Display();								//
	cout << endl;
}

//查看特定书籍
void Library::ShowCertainBook(){
	string keywords;
	int x, y, order; 

	cout << "◇ 请输入图书ISBN进入单册信息查询：";
	getline( cin, keywords ); 
	y = LocateBook ( keywords );
	if ( y == -1 ) {
		cout << "◇ 不存在ISBN为" << keywords << "的图书，操作无效~" << endl; 
		return;
	} else {
		Books[y].Show();
		if ( I->GetType() > 1 ) {
			cout << "★ 您不是超级管理员，必须通过流通管理借阅或者预订书籍！" << endl;
			return;
		}
	    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
		cout << "┃                                                                          ┃" << endl;
	    cout << "┃      【0】借阅                                                           ┃" << endl;
		if ( I->GetType() < 3 && I->GetAN() == 0 ) 
		cout << "┃      【1】预约                                                           ┃" << endl;
		cout << "┃                                                                          ┃" << endl;
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
		if ( I->GetType() < 3 && I->GetAN() == 0 ) order = Readln(0,1); else order = Readln(0, 0);

		cout << "◇ 请问您要第几本？范围：1 - " << Books[y].GetCopy() << endl;
		x = Readln( 1, Books[y].GetCopy() ); --x; 
		if ( Books[y].GetState(x) != 0 ) {
			cout << "★ 该书已出借或者被预约，不能再次借阅！";
			return;
		}
		if ( order == 1 ) ActOrder( y, x ); else ActBorrow( y, x );
	}
}

//关键字查询
void Library::ShowSetBookKey(){
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
	cout << "┃                                                                          ┃" << endl;
	cout << "┃  请输入查询类别：                                                        ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃      【 0 】按 标题 查询                                                 ┃" << endl;
	cout << "┃      【 1 】按 ISBN 查询                                                 ┃" << endl;
	cout << "┃      【 2 】按 作者 查询                                                 ┃" << endl;
	cout << "┃      【 3 】按 索书号 查询                                               ┃" << endl;
	cout << "┃      【 4 】按 类别 查询                                                 ┃" << endl;
	cout << "┃      【 5 】按 编号 查询                                                 ┃" << endl;
	cout << "┃      【 6 】表达式智能模糊查询                                           ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	int i = Readln( 0, 6 ); 
	SetBookKey( i ); 
	cout << "★ 设置成功！" << endl; 
}

void Library::ShowHistory() {
	cout << "▲ 当前共有管理历史记录：" << HisNum << "条。" << endl;
	for ( int i = 0; i < HisNum; ++i ){
		cout << History[i] << endl;
	}
}