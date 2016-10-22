/***************************************************
  文件: Library.h
  引用：Menu.cpp
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：图书馆类
***************************************************/
#pragma once
#include "BookResource.h"
#include "Administrator.h"
#include "Reader.h"
#include "CodeChecker.h"

class Library{

private:

static const int MAX_BOOK = 40000;		// 最大书籍个数
static const int MAX_ADMIN = 10;			// 最大管理员个数
static const int MAX_TEACHER = 50;		// 最大教师个数
static const int MAX_STUDENT = 200;		// 最大学生个数
static const int MAX_USER = MAX_ADMIN + MAX_TEACHER + MAX_STUDENT + 1;		// 最大读者个数

char DataBaseName[MAX_TEACHER], UserFileName[MAX_TEACHER], ManageFileName[MAX_TEACHER]; // 书籍库文件，读者文件，管理历史记录文件
bool FindMode, Flag[MAX_BOOK];		// 搜索模式：是否允许在结果中搜索; 书籍是否被查找过
int HisNum, BookResult, UserResult, BookKey, UserKey;	// 历史记录条数
string History[MAX_STUDENT];		// 历史记录文件

CodeMachine CodeChecker;			// 验证码系统
SuperAdmin Root;					// 超级管理员
Administrator Admins[MAX_ADMIN];	// 管理员
Teacher Teachers[MAX_TEACHER];		// 教师
Student Students[MAX_STUDENT];		// 学生

public:
	int BookTotal, AdminTotal, TeacherTotal, StudentTotal, UserTotal;		//各种总数
	bool UserExist[MAX_USER], BookExist[MAX_BOOK];				//删除标记
	
	Reader *I, *User[MAX_USER], *SUser[MAX_USER];				//读者，搜索用读者指针
	BookResource Books[MAX_BOOK], *SBook[MAX_BOOK];				//书籍，搜索用书籍指针

public:
	Library ( int Type = 0 ) : BookTotal(0), AdminTotal(0), TeacherTotal(0), StudentTotal(0), BookKey(0), UserKey(0), FindMode(0) {}


	// 输入模块
	void Input( void );

	// 输出模块
	void Output( void );
		void OutputBook();
		void OutputUser();
		void OutputSystem();
		void OutputHistory();

	// 登录模块
	bool Login ( void );
		int UserLocate ( string UserName );

	// 搜索模块
	void Findout( string task );
		// 初始化搜索引擎
		void InitSBook( void );
		void InitSUser( void );
		// 搜索引擎调用
		void FindoutUser( string task );
		void FindoutAND( string a, string b );
		void FindoutOR( string a, string b );
		void FindoutEX( string a, string b );
		void FindoutNOT( string b );
		// 快速定位
		int LocateBook( string x );
		int LocateUser( int x );
		// 搜索结果重排序
		void Swap( int a, int b) ;
		void Qsort(int l, int r);
		void Sort( int x ) ;
		// 得到搜索结果
		int GetBookResult();
		int GetUserResult();
		// 取得搜索模式
		string GetFindMode();
		string GetBookSMode();
		string GetUserSMode();

	// 设置模块
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

	// 流通模块
	void ActBorrow( int id, int num, int reader = -1 );
	void ActReturn( int id, int num, int reader = -1 );
	void ActOrder( int id, int num, int reader = -1 );

	// 菜单模块
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

	// 管理模块
		//用户管理
		void AddUser();
		void EditUser();
		void DeleteUser();
		//管理员管理
		void ShowAdmin();
		void EditAdmin();
		//图书管理
		void AddBook();
		void DeleteBook();
		void EditBook();
		void KillBook( int i );

	
	// 系统函数模块
	int Readln( int l = -100000 , int r = 100000 );
	int Val(string s);
};
