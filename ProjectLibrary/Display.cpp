/***************************************************
  �ļ�: Display.cpp
  ���ã�Library.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;���˵�����
  ���룺Date Month User
***************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Library.h"
using namespace std;

//ͼ�������
void Library::BannerBook(){
	cout << "ISBN" << '\t' << "����" << "\t\t\t\t" << "����" << "\t\t" << "���" << "\t" << "���" << '\t' << "������" << endl;
}

//���߱�����
void Library::BannerUser(){
	cout << "ID" << '\t' << "����" << '\t' << "��λ" << "\t\t" << "���" << "\t\t" << "�������" << endl; 
}

//�ʵ�ģ��
void Library::ShowEgg(){
	cout<<" ������������������������������������������" << endl;
	cout<<" ���|�|�������{�{��������������������������" << endl;
	cout<<" ������������������������������������������������" << endl;
	cout<<" ���������������������������������������" << endl;
	cout << "                ������֣�                     " << endl;
}

//չʾ����ͼ��
void Library::Book_Show( int page, int items ){
	BannerBook();
	for ( int i = page; i < min( BookResult , page + items ); ++i ) if ( SBook[i] != NULL )
		SBook[i]->Display();
	cout << endl;
}

//չʾ���ж���
void Library::User_Show( int page, int items ){
	BannerUser();
	for ( int i = page; i < min( UserResult, page + items ); ++i ) if ( SUser[i] != NULL )		//�ö���û��ɾ��..��ҳ
		if ( UserExist[SUser[i]->GetID()] ) SUser[i]->Display();								//
	cout << endl;
}

//�鿴�ض��鼮
void Library::ShowCertainBook(){
	string keywords;
	int x, y, order; 

	cout << "�� ������ͼ��ISBN���뵥����Ϣ��ѯ��";
	getline( cin, keywords ); 
	y = LocateBook ( keywords );
	if ( y == -1 ) {
		cout << "�� ������ISBNΪ" << keywords << "��ͼ�飬������Ч~" << endl; 
		return;
	} else {
		Books[y].Show();
		if ( I->GetType() > 1 ) {
			cout << "�� �����ǳ�������Ա������ͨ����ͨ������Ļ���Ԥ���鼮��" << endl;
			return;
		}
	    cout << "������������������������������������������������������������������������������" << endl;   
		cout << "��                                                                          ��" << endl;
	    cout << "��      ��0������                                                           ��" << endl;
		if ( I->GetType() < 3 && I->GetAN() == 0 ) 
		cout << "��      ��1��ԤԼ                                                           ��" << endl;
		cout << "��                                                                          ��" << endl;
		cout << "������������������������������������������������������������������������������" << endl;
		if ( I->GetType() < 3 && I->GetAN() == 0 ) order = Readln(0,1); else order = Readln(0, 0);

		cout << "�� ������Ҫ�ڼ�������Χ��1 - " << Books[y].GetCopy() << endl;
		x = Readln( 1, Books[y].GetCopy() ); --x; 
		if ( Books[y].GetState(x) != 0 ) {
			cout << "�� �����ѳ�����߱�ԤԼ�������ٴν��ģ�";
			return;
		}
		if ( order == 1 ) ActOrder( y, x ); else ActBorrow( y, x );
	}
}

//�ؼ��ֲ�ѯ
void Library::ShowSetBookKey(){
	cout << "������������������������������������������������������������������������������" << endl;   
	cout << "��                                                                          ��" << endl;
	cout << "��  �������ѯ���                                                        ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��      �� 0 ���� ���� ��ѯ                                                 ��" << endl;
	cout << "��      �� 1 ���� ISBN ��ѯ                                                 ��" << endl;
	cout << "��      �� 2 ���� ���� ��ѯ                                                 ��" << endl;
	cout << "��      �� 3 ���� ����� ��ѯ                                               ��" << endl;
	cout << "��      �� 4 ���� ��� ��ѯ                                                 ��" << endl;
	cout << "��      �� 5 ���� ��� ��ѯ                                                 ��" << endl;
	cout << "��      �� 6 �����ʽ����ģ����ѯ                                           ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "������������������������������������������������������������������������������" << endl;
	int i = Readln( 0, 6 ); 
	SetBookKey( i ); 
	cout << "�� ���óɹ���" << endl; 
}

void Library::ShowHistory() {
	cout << "�� ��ǰ���й�����ʷ��¼��" << HisNum << "����" << endl;
	for ( int i = 0; i < HisNum; ++i ){
		cout << History[i] << endl;
	}
}