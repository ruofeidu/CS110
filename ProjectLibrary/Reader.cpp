/***************************************************
  �ļ�: Reader.cpp
  ���ã�Reader.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;�����߲���ʵ��
  ���룺Date Month User
***************************************************/
#pragma once
#include <iostream>
#include <string>
#include "Reader.h"
using namespace std; 

// ɾ�����߽��ĵ��鼮
void Reader::Del( int x ){
	for ( int i = 0; i < Borrowed; ++i )
		if ( List[i] == x ) {
			for ( int j = i; j < Borrowed - 1; ++j )
				List[j] = List[j+1];
			break;
		}
}

// ��������½��ĵ��鼮
void Reader::Insert( int x ) {
	List[Borrowed++] = x;
}

// ���Ҷ����Ƿ���Ĺ�ĳ����
int Reader::Find( int x ) {
	for ( int i = 0; i < Borrowed; ++i )
		if ( List[i] == x ) return i;
	return -1;
}

// ���ĵ�id���鼮
bool Reader::Borrow( int id ) {
	//if ( Find(id) != -1 ) { cout << "������Ȿ��Ŷ~" << endl; return false; }
	if ( Borrowed == MAX ) return false; else Insert( id );
	return true;
}

// �黹��id���鼮��������£����ж��ܷ����پ�������������
bool Reader::Return( int id ) {
	Del( id );
	--Borrowed;
	cout << "�� ����ɹ���" << endl;
	return true;
	/*
	if ( Find( id ) ){
		Del( id );
		--Borrowed;
		cout << "�� ����ɹ���" << endl;
		return true;
	} else {
		cout << "�� ����ʧ�ܣ�������û����Ȿ�飡" << endl; 
		return false;
	}*/
}

// չʾ���߽��ĵ��鼮
void Reader::Show() {
	cout << endl;
	cout << "�� ����ǰ�����" << Borrowed << "�����ISBN�ֱ�Ϊ��" << endl; 
		
	for ( int i = 0; i < Borrowed; ++i )
		cout << "�� " << List[i] / 10 << "�ĵ�" << List[i] % 10 << "������" << endl;
	cout << endl;
}

// ��������ת�����ı�
string TransType( int x )
{
	switch (x){
		case 0:		return "��������Ա";
		case 1:		return "����Ա\t";
		case 2:		return "��ʦ\t";
		case 3:		return "ѧ��\t";
		default:	return "�ο�\t";
	}
}

// ������Ϣչʾ
void Reader::Display(){
	cout << ID << '\t' << Name << '\t' << Dept;
	if (Dept.size() < 8) cout << '\t';
	cout << '\t' << TransType(Type) << '\t' << Borrowed << '\t' << endl;
}
