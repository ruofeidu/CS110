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

void Library::SetDataBaseName() {
	system("dir *.dat");
	Output();
	cout << "�� �������µ��鼮���ݿ����ƣ�";
	cin.getline ( DataBaseName, 50 ); 
}

void Library::SetUserFileName() {
	system("dir *.dat");
	Output(); 
	cout << "�� �������µ��û����ݿ����ƣ�";
	cin.getline ( UserFileName, 50 ); 
}

void Library::SetManageFileName() {
	system("dir *.dat");
	Output(); 
	cout << "�� �������µĹ������ݿ����ƣ�";
	cin.getline ( ManageFileName, 50 ); 

}