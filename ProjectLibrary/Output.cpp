/***************************************************
  文件: Input.cpp
  引用：Library.h
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：输出模块
  构想：历史记录
***************************************************/
#pragma once
#include <fstream>
#include <string>
#include "Library.h"
#include "BookResource.h"
#include "Book.h"
#include "Reader.h"
#include "MDStarea.h"
using namespace std;

//输出函数
void Library::Output(){
	OutputBook();
	OutputUser();
	OutputSystem();
	OutputHistory();
}

//输出书籍
void Library::OutputBook(){
	ofstream fout;
	fout.open ( DataBaseName );
	for ( int i = 0; i < BookTotal; ++i ) if ( BookExist[i] ){
		fout << Books[i].ISBN << '\t' << Books[i].Title << '\t' << Books[i].Author << '\t' << Books[i].Query << '\t';
		fout << Books[i].Copy << '\t';
		for ( int j = 0; j < Books[i].Copy ; ++j ) {
			fout << Books[i].List[j].State << '\t' << Books[i].List[j].ID << '\t' << Books[i].List[j].UserID << '\t' << Books[i].List[j].OrderID << '\t';
		}
		fout << endl;
	}
	fout.close ();
}

//输出系统文件
void Library::OutputSystem(){
	ofstream fout;
	fout.clear();
	fout.open ( "System.ini" );
	fout <<  DataBaseName << endl << UserFileName << endl << ManageFileName << endl;
	fout.close();
}


//输出读者文件
void Library::OutputUser(){
	ofstream fout;
	fout.clear ();
	fout.open ( UserFileName );
	fout << UserTotal << endl; 
	for ( int i = 1; i <= UserTotal; ++i ) if ( UserExist[i] ) {
		fout << User[i]->GetID() << '\t' << User[i]->GetType() << '\t' << User[i]->GetName() << '\t' << User[i]->GetPW()
			<< '\t' << User[i]->GetDept() << '\t' << User[i]->GetBorrowed() << '\t'; 

		for ( int j = 0; j < User[i]->GetBorrowed(); ++j )
			fout << User[i]->List[j] << '\t';
		
		if ( User[i]->Type < 3 ){
			fout << User[i]->GetAN() << '\t';
			if ( User[i]->GetAN() == 1 ) fout << User[i]->GetAID() << '\t';
		}	

		if ( User[i]->Type < 2 )
			fout << User[i]->GetManageAdmin() << '\t' << User[i]->GetManageBook() << '\t' << User[i]->GetManageUser() << '\t'
			<< User[i]->GetManageBorrow();

		fout << endl; 

	}
	fout.close();
}

//输出历史记录文件
void Library::OutputHistory(){
	ofstream fout;
	fout.clear();
	fout.open ( ManageFileName );
	fout << HisNum << endl;
	for ( int i = 0; i < HisNum; ++i ) fout << History[i] << endl;
	fout.close();
}