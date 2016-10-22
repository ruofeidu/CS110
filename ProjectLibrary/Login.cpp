/***************************************************
  �ļ�: Login.cpp
  ���ã�Library.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;����¼
  ���룺MD5
***************************************************/
#pragma once
#include <iostream>
#include <conio.h>
#include "Library.h"
#include "Administrator.h"
#include "Reader.h"
#include "MDStarea.h"
using namespace std;
  
//��λ����
int Library::UserLocate ( string UserName ){
	for (int  i = 1; i <= UserTotal; ++i )
		if ( User[i]->GetName() == UserName )
			return i;
	
	return -1;
}

//��¼
bool Library::Login(){

	int ID;
	char ch;
	string UserName, UserPW, UserCode ;
	

	CodeChecker.Generate ();

	cout << "�� �������û�����";		getline(cin, UserName);
	cout << "�� ���������룺";			while( ( ch = getch() ) != 0x0d ){ cout << "*";  UserPW = UserPW + ch; } cout << endl;
	CodeChecker.ShowPic ();
	cout << "�� ��������֤�룺";		getline(cin, UserCode);
	


	ID = UserLocate( UserName );		//��λ�û���
	if ( ID == -1 ) return false;
	if ( User[ID]->GetName() == UserName && User[ID]->GetPW() == MDStarea(UserPW) ){
		if ( CodeChecker.Check( UserCode ) ) {
			I = User[ID];
			return true;
		} else {
			cout << "�� ��֤�����~~ " << endl;
			return false;
		}
	} else return false;
}