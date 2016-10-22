/***************************************************
  �ļ�: Library.h
  ���ã�Menu.cpp
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;��ͼ�����
***************************************************/
#pragma once
#include "BookResource.h"
#include "Administrator.h"
#include "Reader.h"
#include "CodeChecker.h"

class Library{

private:

static const int MAX_BOOK = 40000;		// ����鼮����
static const int MAX_ADMIN = 10;			// ������Ա����
static const int MAX_TEACHER = 50;		// ����ʦ����
static const int MAX_STUDENT = 200;		// ���ѧ������
static const int MAX_USER = MAX_ADMIN + MAX_TEACHER + MAX_STUDENT + 1;		// �����߸���

char DataBaseName[MAX_TEACHER], UserFileName[MAX_TEACHER], ManageFileName[MAX_TEACHER]; // �鼮���ļ��������ļ���������ʷ��¼�ļ�
bool FindMode, Flag[MAX_BOOK];		// ����ģʽ���Ƿ������ڽ��������; �鼮�Ƿ񱻲��ҹ�
int HisNum, BookResult, UserResult, BookKey, UserKey;	// ��ʷ��¼����
string History[MAX_STUDENT];		// ��ʷ��¼�ļ�

CodeMachine CodeChecker;			// ��֤��ϵͳ
SuperAdmin Root;					// ��������Ա
Administrator Admins[MAX_ADMIN];	// ����Ա
Teacher Teachers[MAX_TEACHER];		// ��ʦ
Student Students[MAX_STUDENT];		// ѧ��

public:
	int BookTotal, AdminTotal, TeacherTotal, StudentTotal, UserTotal;		//��������
	bool UserExist[MAX_USER], BookExist[MAX_BOOK];				//ɾ�����
	
	Reader *I, *User[MAX_USER], *SUser[MAX_USER];				//���ߣ������ö���ָ��
	BookResource Books[MAX_BOOK], *SBook[MAX_BOOK];				//�鼮���������鼮ָ��

public:
	Library ( int Type = 0 ) : BookTotal(0), AdminTotal(0), TeacherTotal(0), StudentTotal(0), BookKey(0), UserKey(0), FindMode(0) {}


	// ����ģ��
	void Input( void );

	// ���ģ��
	void Output( void );
		void OutputBook();
		void OutputUser();
		void OutputSystem();
		void OutputHistory();

	// ��¼ģ��
	bool Login ( void );
		int UserLocate ( string UserName );

	// ����ģ��
	void Findout( string task );
		// ��ʼ����������
		void InitSBook( void );
		void InitSUser( void );
		// �����������
		void FindoutUser( string task );
		void FindoutAND( string a, string b );
		void FindoutOR( string a, string b );
		void FindoutEX( string a, string b );
		void FindoutNOT( string b );
		// ���ٶ�λ
		int LocateBook( string x );
		int LocateUser( int x );
		// �������������
		void Swap( int a, int b) ;
		void Qsort(int l, int r);
		void Sort( int x ) ;
		// �õ��������
		int GetBookResult();
		int GetUserResult();
		// ȡ������ģʽ
		string GetFindMode();
		string GetBookSMode();
		string GetUserSMode();

	// ����ģ��
	void SetDataBaseName();
	void SetUserFileName();
	void SetManageFileName();
	void SetBookKey( int x ) ;
	void SetUserKey( int x ) ;
	void SetFindMode( int x ); 
	void SetUserSMode();
	void SetMyName();
	void SetMyDept();
	void SetMyPW();

	// ��ͨģ��
	void ActBorrow( int id, int num, int reader = -1 );
	void ActReturn( int id, int num, int reader = -1 );
	void ActOrder( int id, int num, int reader = -1 );

	// �˵�ģ��
	void ShowBorrow();
	void ShowReturn();
	void ShowHistory();
	void ShowUser( int x );
	void ShowCertainBook();
	void ShowSetBookKey();
	void ShowEgg();
	void Book_Show( int page = 0 , int items = 15 );
	void User_Show( int page = 1 , int items = 15 );
	void BannerBook();
	void BannerUser();

	// ����ģ��
		//�û�����
		void AddUser();
		void EditUser();
		void DeleteUser();
		//����Ա����
		void ShowAdmin();
		void EditAdmin();
		//ͼ�����
		void AddBook();
		void DeleteBook();
		void EditBook();
		void KillBook( int i );

	
	// ϵͳ����ģ��
	int Readln( int l = -100000 , int r = 100000 );
	int Val(string s);
};
