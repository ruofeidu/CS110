/***************************************************
  �ļ�: Center.cpp
  ���ã�Library.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;��������Ϣ����
  ���룺MD5 ʵ��
***************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Library.h"
#include "MDStarea.h"
using namespace std;

//��������ת������
string TypeTrans( int x ){
	switch (x){
		case 0:		return "��������Ա";
		case 1:		return "����Ա";
		case 2:		return "��ʦ";
		case 3:		return "ѧ��";
		default:	return "�ο�";
	}
}

//չʾĳһλ����
void Library::ShowUser( int x ){

	if ( x != -1 && UserExist[x] ){
		User[0] = I;
		I = User[x];
	}
	
	cout << "�� ����������" << I->GetName() << endl; 
	cout << "�� �������룺" << I->GetPW() << " (�Ѿ����Ǻ��̿�MDStarea�㷨����)" << endl; 
	cout << "�� ���Ĺ�����λ��" << I->GetDept() << endl; 
	cout << "�� �����û����ͣ�" << TypeTrans( I->GetType() ) << endl; 
	cout << "�� �����ĵ��鼮������" << I->GetBorrowed() << endl; 
	
	if ( I->GetBorrowed() > 0 ) 
			BannerBook();
		for ( int i = 0; i < I->GetBorrowed (); ++i ){
			Books[ I->GetBook ( i ) / 10 ].Display();
		}

		if ( I->GetType() < 3 ){
			cout << "�� ��ԤԼ���鼮������" << I->GetAN() << endl; 
			for ( int i = 0; i < I->GetAN(); ++i ) {
				BannerBook();
				Books[ I->GetAID() / 10 ].Display();
			}
		}

	if ( x != -1 && UserExist[x] ) I = User[0];
}

void Library::SetMyName(){
	string str;
	cout << "�� �������µ��û�����"; 
	getline(cin, str); 
	I->SetName ( str );
}

void Library::SetMyPW(){
	string str;
	cout << "�� �����������룺";
	getline(cin, str);
	I->SetPassword ( MDStarea(str) ); 
}

void Library::SetMyDept(){
	string str;
	cout << "�� �������¹�����λ��" ; 
	getline(cin, str); 
	I->SetDept ( str ); 
}

