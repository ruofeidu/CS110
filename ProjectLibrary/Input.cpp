/***************************************************
  �ļ�: Input.cpp
  ���ã�Library.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;������ģ��
  ���룺��ʷ��¼
***************************************************/
#pragma once
#include <fstream>
#include <string>
#include "Library.h"
#include "BookResource.h"
#include "Book.h"
#include "Reader.h"
using namespace std;

void Library::Input(){
	string UserName, UserPW, UserDept, ID;
	int UserID, UserType, UserBorrow, i, BookID, x;

	ifstream fin;
	fin.open ( "System.ini" );
	fin >> DataBaseName >> UserFileName >> ManageFileName;
	fin.close();

	
	// �Ӷ����ļ��ж��������Ϣ
	fin.clear();
	fin.open ( UserFileName );
	fin >> UserTotal; 
	for (int k = 0; k < UserTotal; ++k ) {
		fin >> UserID >> UserType >> UserName >> UserPW >> UserDept >> UserBorrow;
		switch ( UserType ) {
			case 0:		User[UserID] = &Root; break;
			case 1:		User[UserID] = &Admins[AdminTotal++];		break;
			case 2:		User[UserID] = &Teachers[TeacherTotal++];	break;
			case 3:		User[UserID] = &Students[StudentTotal++];	break;
		}

		UserExist[UserID] = true; 
		User[UserID]->SetID ( UserID );
		User[UserID]->SetType ( UserType );
		User[UserID]->SetName ( UserName );
		User[UserID]->SetDept ( UserDept );
		User[UserID]->SetPassword ( UserPW );

		//������߽��ÿһ����
		for ( i = 0; i < UserBorrow; ++i ){
			fin >> BookID;
			User[UserID]->Borrow ( BookID );
		}

		//�������ԤԼ����
		if ( UserType < 3 ){	
			fin >> UserBorrow;
			if ( UserBorrow == 1 ) {
				fin >> BookID;
				User[UserID]->Order ( BookID );
			}
		}

		//�������ԱȨ��
		if ( UserType < 2 ){
			fin >> x; User[UserID]->SetManageAdmin(x);
			fin >> x; User[UserID]->SetManageUser(x);
			fin >> x; User[UserID]->SetManageBook(x);
			fin >> x; User[UserID]->SetManageBorrow(x);
		}
	}

	
	// ���鼮���ݿ�����鱾
	BookTotal = 0;
	fin.close ();
	fin.clear ();
	fin.open ( DataBaseName );
	i = fin.peek();

	while ( fin.peek() != EOF ) {
		char str[100];
		fin.getline( str, 100, '\t' );	Books[BookTotal].ISBN = str;
		fin.getline( str, 100, '\t' );	Books[BookTotal].Title = str;
		fin.getline( str, 100, '\t' );	Books[BookTotal].Author = str;
		fin.getline( str, 100, '\t' );	Books[BookTotal].Query = str;
		fin >> Books[BookTotal].Copy ;
		for ( int i = 0; i < Books[BookTotal].Copy ; ++i ) {
			fin >> Books[BookTotal].List[i].State >> Books[BookTotal].List[i].ID >> Books[BookTotal].List[i].UserID >> Books[BookTotal].List[i].OrderID;
		}
		fin.getline ( str ,100 );
		
		//��������,���ֱ��,ģ����������
		Books[BookTotal].BuildID();
		BookExist[BookTotal] = true;
		++BookTotal;
	}
	fin.close();

	// ������ʷ��¼�ļ�
	fin.clear ();
	fin >> HisNum; getline( fin, History[0] );
	for ( int i = 0; i < HisNum; ++i ) getline ( fin, History[i] );
	fin.close();

	InitSBook();
	InitSUser();
}
	
