/***************************************************
  �ļ�: Act.cpp
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
	if ( task.find( "=" , 0 ) != string::npos ) SetBookKey(6);	//��������
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

	//���ȼ���ߵ���ȫƥ��
	for (int i = 0; i < BookTotal; ++i) if (BookExist[i]){	
		if ((FindMode ^ Flag[i]) && Books[i].GetKEY(BookKey) == task) {
			SBook[BookResult++] = &Books[i];
			Flag[i] = false;
		}
	}

	// �����Ӵ�ƥ��
	string sink;							// ö�ٲ�ͬ���ȵ��Ӵ�
	int MINLEN = 0;							// ��С���ȣ����ڱ��ʽ����
	if ( BookKey == 6 ) MINLEN = 4;			// �������ʽ���ܼ���
	for ( i = task.length(); BookResult < MAXRES && i > MINLEN; --i )									//��ʼ
		for ( j = 0; BookResult < MAXRES && j + i < task.length(); ++j ) {								//����
			sink = ""; cut += BookTotal; if ( cut > MAXCUT ) break;							//���ܱ��ʽ������
			for (int k = j; k <= j + i; ++k ) sink += task[k];									//��ȡ
			for (int k = 0; BookResult < MAXRES && k < BookTotal; ++k )if (BookExist[k]){				//����
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

	//cout << "����ȫƥ�䣺" << endl;
	for (i = 1; i <= UserTotal; ++i) if ( UserExist[i] )
		if (Flag[i] && User[i]->GetKEY(UserKey) == task) {
			SUser[UserResult++] = User[i];
			Flag[i] = false;
		}  

	string sink;   //ö�ٲ�ͬ���ȵ��Ӵ�
	//cout << "�������Ӵ�ƥ�䣺" << endl;
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
	if ( FindMode == 1 ) return ("��"); else return ("��");
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
		case 0:		return "������ѯ��  ";
		case 1:		return "ISBN��ѯ��  ";
		case 2:		return "���߲�ѯ��  ";
		case 3:		return "����Ų�ѯ��";
		case 4:		return "����ѯ��  ";
		case 5:		return "��Ų�ѯ��  ";
		default:	return "���ܱ��ʽ��";
	}
}

string Library::GetUserSMode(){
	switch( UserKey ){
		case 0:		return "����";
		case 1:		return "��λ";
		default:	return "����";
	}
}

void Library::SetUserSMode(){
	cout << "������������������������������������������������������������������������������" << endl;   
	cout << "��                                                                          ��" << endl;
	cout << "��  �������ѯ���                                                        ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��      �� 0 ���� ���� ��ѯ                                                 ��" << endl;
	cout << "��      �� 1 ���� ��λ ��ѯ                                                 ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "������������������������������������������������������������������������������" << endl;
	int i = Readln( 0, 1 ); 
	SetUserKey( i ); 
	cout << "�� ���óɹ���" << endl;
	system("pause");
}