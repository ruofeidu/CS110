/***************************************************
  �ļ�: Manage.cpp
  ���ã�Library.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;��ͳ����顢ԤԼ���������
  ���룺Date Month User
***************************************************/

#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include "Library.h"
#include "MDStarea.h"
using namespace std;

//��Ӷ���
void Library::AddUser(){
	string UserName, UserPW, UserDept;
	int UserID, UserType;
	char ch;

	++UserTotal; 
	UserID = UserTotal;

	cout << "�� �������¶������";
	UserType = Readln(0, 3);
	switch (UserType) {
		case 1:		User[UserID] = &Admins[AdminTotal++];		break;
		case 2:		User[UserID] = &Teachers[TeacherTotal++];	break;
		case 3:		User[UserID] = &Students[StudentTotal++];	break;
		default:	cout << "�� ������0-3�����֣���ֹ���ӳ�������Ա������~ "; return;  break; 
	}

	cout << "�� �������¶���������";  getline( cin, UserName); 
	cout << "�� �������¶������룺";  while( ( ch = getch() ) != 0x0d ){ cout << "*";  UserPW = UserPW + ch; } cout << endl;
	cout << "�� �������¶��߹�����λ��";  getline( cin, UserDept );
	
	UserExist[UserID] = true; 
	User[UserID]->SetID ( UserID );
	User[UserID]->SetType ( UserType );
	User[UserID]->SetName ( UserName );
	User[UserID]->SetDept ( UserDept );
	User[UserID]->SetPassword ( MDStarea(UserPW) );

	History[HisNum++]= "�� ����Ա" + I->GetName() + "����¶���" + User[UserID]->GetName();  
}

// ɾ������
void Library::DeleteUser(){
	int x, y; 

	cout << "�� ������Ҫɾ���Ķ���ID:" << endl;
	x = Readln( 1, UserTotal ); 
	if ( x == 0 ) { cout << "�� ��ֹɾ����������Ա������"; system("pause"); return; }
		if (! UserExist[x] ) { cout << "�� ������~~ ����˲�����" << endl;  system("pause"); return; }
		else { User[x]->Display(); cout << "�� ��ȷ��Ҫɾ������������� 1 ȷ��ɾ����0 ȡ������~ " << endl; }
	y = Readln( 0, 1); 
	if ( y == 1 ) {
		UserExist[x] = false;
		History[HisNum++]= "�� ����Ա" + I->GetName() + "ɾ������" + User[x]->GetName();  
	}
}

// չʾ����Ա
void Library::ShowAdmin(){
	for ( int i = 0; i < AdminTotal; ++i ){
		cout << "���" << i << "��"; 
		Admins[i].Display();
	}
}

// �༭����Ա
void Library::EditAdmin(){
	int x, y; 
	cout << "�� ������Ҫ�༭�Ĺ���Ա���:" << endl;
	x = Readln( 0, AdminTotal - 1);
				 
	Admins[x].Display(); 
	cout << "�� ��ȷ��Ҫ�༭����������� 1 ȷ���༭��0 ȡ������~ " << endl; 
	cout << "Ȩ�޹���" << '\t' << "���߹���" << '\t' << "��Ŀ����" << '\t' << "��ͨ����" << endl; 
	cout << Admins[x].GetManageAdmin () << "\t\t" << Admins[x].GetManageBook() << "\t\t" << Admins[x].GetManageBorrow() << "\t\t" << Admins[x].GetManageUser() << endl;
	y = Readln( 0, 1); 
	if ( y != 1 ) return;

	cout << "�� ������ù���Ա�ܷ����Ȩ�޹��� ( 1���� 0������)��"; x = Readln( 0, 1); Admins[x].SetManageAdmin(x);
	cout << "�� ������ù���Ա�ܷ���ʶ��߹��� ( 1���� 0������)��"; x = Readln( 0, 1); Admins[x].SetManageUser(x);
	cout << "�� ������ù���Ա�ܷ������Ŀ���� ( 1���� 0������)��"; x = Readln( 0, 1); Admins[x].SetManageBook(x);
	cout << "�� ������ù���Ա�ܷ������ͨ���� ( 1���� 0������)��"; x = Readln( 0, 1); Admins[x].SetManageBorrow(x);
	History[HisNum++]= "�� ����Ա" + I->GetName() + "�༭����ԱȨ��" + Admins[x].GetName();  
}

//�༭����
void Library::EditUser(){
	string UserName, UserPW, UserDept;
	int UserID, UserType;

	int x, y; 

	cout << "�� ������Ҫ�༭�Ķ���ID:";
	x = Readln( 1, UserTotal ); 
	if (! UserExist[x] ) cout << "�� ������~~ ����˲�����" << endl; 
		else { User[x]->Display(); cout << "�� ��ȷ��Ҫ�༭����������� 1 ȷ���༭��0 ȡ������~ " << endl; }
	y = Readln( 0, 1 );
	if ( y != 1 ) return;

	UserID = x;

	cout << "�� �������¶������"; UserType = Readln( 0,3 );
	switch (UserType) {
		case 1:		User[UserID] = &Admins[AdminTotal++];		break;
		case 2:		User[UserID] = &Teachers[TeacherTotal++];	break;
		case 3:		User[UserID] = &Students[StudentTotal++];	break;
		default:	cout << "�� ������0-3�����֣���ֹ���ӳ�������Ա������~ "; return;  break; 
	}

	cout << "�� ������ö�����������";		getline( cin, UserName ); 
	cout << "�� ������ö��������룺";		getline( cin, UserPW );
	cout << "�� ������ö����¹�����λ��";  getline( cin, UserDept ); 
	
	UserExist[UserID] = true; 
	User[UserID]->SetID ( UserID );
	User[UserID]->SetType ( UserType );
	User[UserID]->SetName ( UserName );
	User[UserID]->SetDept ( UserDept );
	User[UserID]->SetPassword ( MDStarea(UserPW) );

	History[HisNum++]= "�� ����Ա" + I->GetName() + "�༭����" + User[UserID]->GetName();  
}

// ����鼮
void Library::AddBook(){	
	string x;
	int y; 
	cout << "�� �����������ISBN��";			getline( cin, x ); Books[BookTotal].SetISBN(x);
	cout << "�� ����������ı��⣺";			getline( cin, x ); Books[BookTotal].SetTitle(x); 
	cout << "�� ��������������ߣ�";			getline( cin, x ); Books[BookTotal].SetAuthor(x); 
	cout << "�� ���������������ţ�";			getline( cin, x ); Books[BookTotal].SetQuery(x); 
	cout << "�� ����������ĸ�������";			y = Readln(1, 5 ); Books[BookTotal].SetCopy(y) ;
	
	for ( int i = 0; i < Books[BookTotal].GetCopy() ; ++i ) Books[BookTotal].Insert( 0, i + 1 , 0, 0 );

	//��������ķ���ź����ֱ��
	Books[BookTotal].BuildID();
	BannerBook();
	Books[BookTotal].Display();
	BookExist[BookTotal] = true;
	
	History[HisNum++]= "�� ����Ա" + I->GetName() + "����鼮" + Books[BookTotal].GetTitle();  
	
	++BookTotal;
}

// ɾ���鼮
void Library::DeleteBook(){
	string x; 
	int ans;

	cout << "�� ������Ҫɾ�����ISBN��ţ�";
	getline( cin, x );
	int i = LocateBook(x);
	if ( i != -1 ) {
		cout << "�� �Ȿ���ǣ�" << endl;
		BannerBook();
		Books[i].Display();  
		cout << "�� ��ȷ��Ҫɾ���� ( 1 �� 0 �� ) ";
		ans = Readln(0,1);
		if ( ans == 1) KillBook(i); else return;
		cout << "�� ɾ���ɹ���" << endl; 
		History[HisNum++]= "�� ����Ա" + I->GetName() + "ɾ���鼮" + Books[i].GetTitle(); 
	} else
		cout << "�� ɾ��ʧ�ܣ�" << endl; 

	system("pause");
}

// �༭��
void Library::EditBook(){
	string x;
	int y;
	cout << "�� ������Ҫ�༭�����ISBN��ţ�";
	getline( cin, x);
	int i = LocateBook(x);
	if ( i != -1 ) {
		BannerBook();
		Books[i].Display();
		cout << "�� �������Ȿ���µ�ISBN��";			getline(cin, x); Books[i].SetISBN(x);
		cout << "�� �������Ȿ���µı��⣺";			getline(cin, x); Books[i].SetTitle(x); 
		cout << "�� �������Ȿ���µ����ߣ�";			getline(cin, x); Books[i].SetAuthor(x); 
		cout << "�� �������Ȿ���µ�����ţ�";			getline(cin, x); Books[i].SetQuery(x); 
		cout << "�� �������Ȿ���µĸ�������";			y = Readln( 1, 5); 
		if (y < Books[i].GetCopy() ) 
			for ( int j = y; j < Books[i].GetCopy(); ++j ) Books[i].Del(j);
		else for ( int j = Books[i].GetCopy(); j < y; ++j ) Books[i].Insert( 0, 1, 0, 0 );
		Books[i].SetCopy(y);
		cout << "�� �༭�ɹ���" << endl;
		BannerBook();
		Books[i].Display();
		History[HisNum++]= "�� ����Ա" + I->GetName() + "�༭�鼮" + Books[i].GetTitle(); 
	}
}

//����ͼ��Ͷ��ߵĹؼ��ֲ�ѯ���
void Library::SetBookKey( int x ) { BookKey = x; }
void Library::SetUserKey( int x ) { UserKey = x; }

void Library::KillBook( int i ){
	BookExist[i] = 0; 
}

// ��λ�鼮
int Library::LocateBook( string x ){
	for ( int i = 0; i < BookTotal; ++i ) if ( Books[i].GetISBN() == x ) return i;
	cout << "�� �������ҵ��Ȿ�鲻���ڣ���ȷ��ISBN����" << endl; 
	return -1; 
}

// ��λ����
int Library::LocateUser( int x ) {
	for ( int i = 1; i <= BookTotal; ++i ) if ( User[i]->GetID() == x ) return i; 
	return -1;
}

