/***************************************************
  �ļ�: Teacher.cpp
  ���ã�Reader.h
  ��;����ʦ��Ϣ
  ���룺Date Month User
***************************************************/
#pragma once
#include "Reader.h"

// ���캯��
Teacher::Teacher(){ 
	MAX = 10;
	AppointNum = 0;
	AppointID = 0;
}

// ��ʦԤԼ
bool Teacher::Order( int x ) {
	if ( Type == 3 ) return false;
	if ( AppointNum == 0 ) {
		++AppointNum;
		AppointID = x;
	return true;
	} else return false; 
}

// ȡ��ԤԼ�鼮����
int Teacher::GetAN(){
	return AppointNum; 
}

// ȡ��ԤԼ�鼮��� 
// ���= ISBN + ������
int Teacher::GetAID(){
	return AppointID;
}

// ȡ��ԤԼ
void Teacher::CancelAppoint( void ) { 
	AppointNum = 0;
}