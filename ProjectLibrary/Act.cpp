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
int Read(int, int);

void Library::ShowBorrow(){
	string book;
	int user, x, y;

	cout << "☆ 请输入读者ID：";
	user = Readln( 0, UserTotal );
	if ( UserExist[user] ) User[user]->Display (); else { cout << "★ 该读者不存在哦~~" << endl; return; }
	cout << "☆ 请输入要借阅的图书ISBN：";
	getline( cin, book ); 
	y = LocateBook ( book );
	if ( y == -1 ) cout << "◇ 不存在ISBN为" << book << "的图书，操作无效~" << endl; else {
		Books[y].Show();
		Books[y].Display();
		cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
		cout << "┃                                                                          ┃" << endl;
		cout << "┃      【0】借阅                                                           ┃" << endl;
		if ( User[user]->GetType() < 3 && User[user]->GetAN() == 0 ) 
		cout << "┃      【1】预约                                                           ┃" << endl;
		cout << "┃                                                                          ┃" << endl;
		cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
		if ( User[user]->GetType() < 3 && User[user]->GetAN() == 0 ) x = Read(0, 1); else x = Read(0, 0);
		cout << "◇ 请问这位读者请求的第几本？（由条形码决定）范围：1 - " << Books[y].GetCopy();
		x = Read( 1, Books[y].GetCopy() ); --x; 
		if ( x == 1 ) ActOrder( y, x ,user); else ActBorrow( y, x ,user);
	}
}

void Library::ShowReturn(){
	string book;
	int user, x;

	cout << "☆ 请输入读者ID：";
	user = Readln( 0, UserTotal );
	if ( UserExist[user] ) User[user]->Display (); else { cout << "★ 该读者不存在哦~~" << endl; return; }
	x = 0;
	if ( User[user]->GetType() < 3 ) {
		cout << "◇ 该读者是要归还借阅书【0】，还是要取消预订书呢？【1】";
		x = Readln( 0, 1 );
	}
	if ( x == 0 ){
		if ( User[user]->GetBorrowed () == 0) { cout << "★ 该读者当前没有借书…… " << endl; return; }
		cout << "□ 您所借阅的" << User[user]->GetBorrowed () << "本书信息为：" << endl; 
		BannerBook();
		for ( int i = 0; i < User[user]->GetBorrowed (); ++i ){						
			Books[ User[user]->GetBook ( i ) / 10 ].Display();
		}
		cout << "◇ 请输入该读者要归还第几本？" << endl; 
		x = Readln( 1, User[user]->GetBorrowed () );
		--x;
		Books[ User[user]->GetBook ( x ) / 10 ].Return ( User[user]->GetBook ( x ) % 10 );
		User[user]->Return ( User[user]->GetBook ( x ) );
	} else
	if ( User[user]->GetType() < 3 ){
		cout << "○ 您预约的书籍个数：" << User[user]->GetAN() << endl;
		cout << "□ 您预约的第" << 1 << "本书籍是：" << endl;
		BannerBook ();
		for ( int i = 0; i < User[user]->GetAN(); ++i ) {
			Books[ User[user]->GetAID() / 10 ].Display();
		}

		cout << "□ 您确定要取消预订吗？1 确定 " << endl ;
		x = Read( 0, 1 );
		if ( x == 1 ){
			User [user]->CancelAppoint ();
			Books[ User[user]->GetAID() / 10].Cancel ( User[user]->GetAID() % 10);
		}
	} else cout << "□ 该读者是学生，不能预订书哦~~" << endl;
}

void Library::ActBorrow( int id, int num, int reader ){
	if ( Books[id].List[num].State != 0 ) { cout << "□ 借阅失败~~ 这本书不是可外借状态~~ " << endl; return; }

	if ( reader == -1 ){
	if ( I->Borrow ( id * 10 + num )){ 
			Books[id].Lend( num, I->GetID() );
			cout << "□ 借阅成功！" << endl;
		} else cout << "□ 借阅失败！您的账户已达最大借阅限制或者您借过这套书的某本单册！" << endl; 
	} else {
		if ( User[reader]->Borrow ( id * 10 + num ) ) {
			Books[id].Lend( num, User[reader]->GetID() );
			cout << "□ 借阅成功！" << endl;
			History[HisNum++]= "★ 管理员" + I->GetName() + "让读者" + User[reader]->GetName() + "借阅ISBN为" + Books[id].GetISBN() + "的书。";
		} else cout << "□ 借阅失败！该账户已达最大借阅限制或者您借过这套书的某本单册！" << endl; 
	}
}	

void Library::ActOrder( int id, int num, int reader ){
	if ( reader == -1 ){
		if ( I->Order ( id * 10 + num ) ) {
			Books[id].LendOrder( num, I->GetID() );
			cout << "□ 预约成功！" << endl;
		} else cout << "□ 预约失败！您的账户已达最大预约限制!" << endl; 
	} else {
		if ( User[reader]->Order ( id * 10 + num ) ) {
			Books[id].LendOrder( num, User[reader]->GetID() );
			cout << "□ 预约成功！" << endl;
			History[HisNum++]= "★ 管理员" + I->GetName() + "让读者" + User[reader]->GetName() + "预约ISBN为" + Books[id].GetISBN() + "的书。";
		} else cout << "□ 预约失败！该账户已达最大预约限制！" << endl; 
	}
}

void Library::ActReturn( int id, int num, int reader ){
	Books[id].Return ( num );
	if ( reader == -1 ) I->Return ( num ); else User[reader]->Return ( num );
}	