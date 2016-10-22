/***************************************************
  �ļ�: Book.h
  ���ã�BookResource.h
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;��ÿ���鵥����Ϣ
  ���룺Date Month User
***************************************************/

#pragma once
#include "BookResource.h"
using namespace std;

class Book {
	   friend class BookResource;
	   friend class Library;

private:
    int State;  	// ͼ��״̬��0. �����  1.  �ѳ���   2. ��ԤԼ  3. ������  4.������...
	int UserID;		// ������ID
	int OrderID;	// Ԥ����ID

public:
	int ID;			// ͼ����BookResource��ı��
	Book() : State(0), ID(0), UserID(0), OrderID(0) {}
};
