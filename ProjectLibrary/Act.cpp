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
int Read(int, int);

void Library::ShowBorrow(){
	string book;
	int user, x, y;

	cout << "�� ���������ID��";
	user = Readln( 0, UserTotal );
	if ( UserExist[user] ) User[user]->Display (); else { cout << "�� �ö��߲�����Ŷ~~" << endl; return; }
	cout << "�� ������Ҫ���ĵ�ͼ��ISBN��";
	getline( cin, book ); 
	y = LocateBook ( book );
	if ( y == -1 ) cout << "�� ������ISBNΪ" << book << "��ͼ�飬������Ч~" << endl; else {
		Books[y].Show();
		Books[y].Display();
		cout << "������������������������������������������������������������������������������" << endl;   
		cout << "��                                                                          ��" << endl;
		cout << "��      ��0������                                                           ��" << endl;
		if ( User[user]->GetType() < 3 && User[user]->GetAN() == 0 ) 
		cout << "��      ��1��ԤԼ                                                           ��" << endl;
		cout << "��                                                                          ��" << endl;
		cout << "������������������������������������������������������������������������������" << endl;
		if ( User[user]->GetType() < 3 && User[user]->GetAN() == 0 ) x = Read(0, 1); else x = Read(0, 0);
		cout << "�� ������λ��������ĵڼ����������������������Χ��1 - " << Books[y].GetCopy();
		x = Read( 1, Books[y].GetCopy() ); --x; 
		if ( x == 1 ) ActOrder( y, x ,user); else ActBorrow( y, x ,user);
	}
}

void Library::ShowReturn(){
	string book;
	int user, x;

	cout << "�� ���������ID��";
	user = Readln( 0, UserTotal );
	if ( UserExist[user] ) User[user]->Display (); else { cout << "�� �ö��߲�����Ŷ~~" << endl; return; }
	x = 0;
	if ( User[user]->GetType() < 3 ) {
		cout << "�� �ö�����Ҫ�黹�����顾0��������Ҫȡ��Ԥ�����أ���1��";
		x = Readln( 0, 1 );
	}
	if ( x == 0 ){
		if ( User[user]->GetBorrowed () == 0) { cout << "�� �ö��ߵ�ǰû�н��顭�� " << endl; return; }
		cout << "�� �������ĵ�" << User[user]->GetBorrowed () << "������ϢΪ��" << endl; 
		BannerBook();
		for ( int i = 0; i < User[user]->GetBorrowed (); ++i ){						
			Books[ User[user]->GetBook ( i ) / 10 ].Display();
		}
		cout << "�� ������ö���Ҫ�黹�ڼ�����" << endl; 
		x = Readln( 1, User[user]->GetBorrowed () );
		--x;
		Books[ User[user]->GetBook ( x ) / 10 ].Return ( User[user]->GetBook ( x ) % 10 );
		User[user]->Return ( User[user]->GetBook ( x ) );
	} else
	if ( User[user]->GetType() < 3 ){
		cout << "�� ��ԤԼ���鼮������" << User[user]->GetAN() << endl;
		cout << "�� ��ԤԼ�ĵ�" << 1 << "���鼮�ǣ�" << endl;
		BannerBook ();
		for ( int i = 0; i < User[user]->GetAN(); ++i ) {
			Books[ User[user]->GetAID() / 10 ].Display();
		}

		cout << "�� ��ȷ��Ҫȡ��Ԥ����1 ȷ�� " << endl ;
		x = Read( 0, 1 );
		if ( x == 1 ){
			User [user]->CancelAppoint ();
			Books[ User[user]->GetAID() / 10].Cancel ( User[user]->GetAID() % 10);
		}
	} else cout << "�� �ö�����ѧ��������Ԥ����Ŷ~~" << endl;
}

void Library::ActBorrow( int id, int num, int reader ){
	if ( Books[id].List[num].State != 0 ) { cout << "�� ����ʧ��~~ �Ȿ�鲻�ǿ����״̬~~ " << endl; return; }

	if ( reader == -1 ){
	if ( I->Borrow ( id * 10 + num )){ 
			Books[id].Lend( num, I->GetID() );
			cout << "�� ���ĳɹ���" << endl;
		} else cout << "�� ����ʧ�ܣ������˻��Ѵ����������ƻ���������������ĳ�����ᣡ" << endl; 
	} else {
		if ( User[reader]->Borrow ( id * 10 + num ) ) {
			Books[id].Lend( num, User[reader]->GetID() );
			cout << "�� ���ĳɹ���" << endl;
			History[HisNum++]= "�� ����Ա" + I->GetName() + "�ö���" + User[reader]->GetName() + "����ISBNΪ" + Books[id].GetISBN() + "���顣";
		} else cout << "�� ����ʧ�ܣ����˻��Ѵ����������ƻ���������������ĳ�����ᣡ" << endl; 
	}
}	

void Library::ActOrder( int id, int num, int reader ){
	if ( reader == -1 ){
		if ( I->Order ( id * 10 + num ) ) {
			Books[id].LendOrder( num, I->GetID() );
			cout << "�� ԤԼ�ɹ���" << endl;
		} else cout << "�� ԤԼʧ�ܣ������˻��Ѵ����ԤԼ����!" << endl; 
	} else {
		if ( User[reader]->Order ( id * 10 + num ) ) {
			Books[id].LendOrder( num, User[reader]->GetID() );
			cout << "�� ԤԼ�ɹ���" << endl;
			History[HisNum++]= "�� ����Ա" + I->GetName() + "�ö���" + User[reader]->GetName() + "ԤԼISBNΪ" + Books[id].GetISBN() + "���顣";
		} else cout << "�� ԤԼʧ�ܣ����˻��Ѵ����ԤԼ���ƣ�" << endl; 
	}
}

void Library::ActReturn( int id, int num, int reader ){
	Books[id].Return ( num );
	if ( reader == -1 ) I->Return ( num ); else User[reader]->Return ( num );
}	