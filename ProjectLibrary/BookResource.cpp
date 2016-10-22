/***************************************************
  �ļ�: BookResouce.cpp
  ���ã�BookResouce.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;��ÿ�����ISBN����Ϣ
  ���룺Date Month User
***************************************************/
#pragma once
#include <iostream>
#include "BookResource.h"
#include "Book.h"
using namespace std;

//����
void BookResource::Lend( int y , int UID){
	++Borrowed;
	List[y].State = 1; 
	List[y].UserID = UID; 
}

//����
void BookResource::Return( int y ){
	--Borrowed;
	Cancel(y);
}

//ȡ��ԤԼ
void BookResource::Cancel( int y ){
	List[y].State = 0;
}

//ԤԼ
void BookResource::LendOrder( int y, int UID){
	List[y].State = 2;
	List[y].OrderID = UID;
}

//���������
void BookResource::BuildID(){
	int pos = Query.find('-',0);
	Category = Query.substr ( 0, pos ); 
	ID = Query.substr ( pos + 1, Query.size() - pos ); 
	Super = "ISBN=" + ISBN + "����=" + Title + "����=" + Author + "���=" + Category + "���=" + ID + "�����" + Query;
}

//�����µ���
void BookResource::Insert( int State, int ID, int UserID, int OrderID ) {
	List[ID-1].State = State;
	List[ID-1].ID = ID;
	List[ID-1].UserID = UserID;
	List[ID-1].OrderID = OrderID;
}

//ɾ������
void BookResource::Del( int ID ){
	for ( int i = 0; i < Copy; ++i )
		if ( List[i].ID == ID ) {
			for ( int j = i; j < Copy - 1; ++j )
				List[j] = List[j+1];
			break;
		}
}

//��ӡÿ����״̬
string BookResource::StatePrint( int x ){
	switch ( x ) {
		case 0: return "�ɽ��ġ�"; break;
		case 1: return "�ѳ��衣"; break;
		case 2: return "��ԤԼ��"; break; 
		case 3: return "��������"; break;
		default: return "�����С�"; break;
	}
}

//��ʾ�Ȿ��ÿ���������
void BookResource::Show() {
	for ( int i = 0; i < Copy ; ++i ) {
		cout << "ISBNΪ" << ISBN << "�ĵ�" << i + 1 << "����" << StatePrint( List[i].State );
		if ( List[i].State == 1 ) cout << "������ID��" << List[i].UserID ;
		if ( List[i].State == 2 ) cout << "ԤԼ��ID��" << List[i].UserID ; 
		cout << endl;
	}
}

//չʾһ����
void BookResource::Display() {
	cout << ISBN << '\t' << Title << '\t';
	if ( Title.size() < 24 ) cout << '\t';
	if ( Title.size() < 16 ) cout << '\t';
	if ( Title.size() < 8 ) cout << '\t';
	cout << Author;
	if ( Author.size() < 8 ) cout << '\t';
	cout << '\t' <<  Category << '\t' << ID << '\t' << Copy << endl;
}

//�ַ���������
int BookResource::val(string s) {
	int x = 0;
	unsigned int i;
	bool flag = false;
    
	if (s[0] == '-')
		flag = true;
	else if (s[0] >= '0' && s[0] <= '9')
		x = ( s[0] - '0' );
	else
		return (error_code);
    
	for ( i = 1; i < s.length(); ++i )
		if (s[i] >= '0' && s[i] <= '9')
			x = x * 10 + ( s[i] - '0' );
		else
			return (error_code); 
            
	if (flag) x = -x;
            
	return (x);
}
