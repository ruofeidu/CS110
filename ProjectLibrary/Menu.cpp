/***************************************************
  文件: Menu.cpp
  姓名: 杜若飞
  学号: 5090109228
  工程: 星海碧空图书馆管理系统
  班级: F0903028
  用途：整个工程的菜单文件
  构想：设计自动画菜单的东东
***************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"
#include "MDStarea.h"
using namespace std;
const int error_code = 19910525;		//系统错误码
int ans, pageset = 15;					//选择码，每页显示页数码
bool start, boot = true;				//是否是第一次启动
string str;								//系统自我保护字符串
Library Lib;							//图书馆来喽~

//系统函数
void Cls();								//清屏函数
void Wait();							//等待用户相应
bool Check();							//特殊判断【特殊命令】
int Read( int l, int r);				//读入整数

void Init();							//初始化CMD画面
void Welcome();							//欢迎画面
void Center();							//菜单_个人中心
void Center_UserView();					//菜单_用户登录
void Center_UserModify();				//菜单_修改用户信息
void Search();							//菜单_搜索系统
void Search_Book( int page = 0 );		//菜单_搜索书
void Search_Reader( int page = 0 );	//菜单_搜索读者
void Manage();							//菜单_管理系统
void Manage_Book();						//菜单_管理书籍
void Manage_Admin();					//菜单_管理管理权限
void Manage_Reader();					//菜单_管理读者
void Manage_Trans();					//菜单_管理流通
void Manage_DataBase();					//菜单_管理数据库
void Help();							//菜单_管理帮助系统
void Daily();							//菜单_每日一贴

//检查是否强制返回或者强制退出 
bool Check(){
	bool flag = true; int select;
    if (str == "exit" || str == "halt" ){
		cout << "★ 希望您在碧空图书馆度过开心的一天！再见~ " << endl;
		Lib.Output();
        exit(0) ;
    } else if (str == "welcome" || str == "main"){
        Cls();
        Welcome();  
	} else if (str == "fullscreen" || str == "fs" ){
		system("fullscreen 1"); cout << "★ 已经切换到全屏状态。"; Wait();
	} else if (str == "window" || str == "win" ){
		system("fullscreen 0"); cout << "★ 已经切换到窗口状态。"; Wait();
	} else if (str == "about"){
		cout << "★ 本程序由星海碧空 www.starea.cn 小星海 F0903028 5090109228 杜若飞开发" << endl;
		Wait();
	} else if (str == "egg"){
		cout << "★ 恭喜你找到彩蛋。。下面会发生什么呢？ O(∩_∩)O~" << endl;
		Lib.ShowEgg();	Wait();
	} else if (str == "1 + 1"){
		cout << "1 + 1 = 2 ";
		Wait();
	} else if (str == "setpage"){
		cout << "☆ 请输入每页显示条数：" ; 
		select = Read( 1, 100); 
		pageset = select;
		Wait();
	} else if (str == "login"){
		while (true) {
			Cls();
			Daily();
			if ( Lib.Login() ) {
				cout << "◇ 登录成功！"; 
				Wait();
				Welcome();
			} else {
			cout << "◆ 登录失败！请重新登录！" << endl; 
			Wait();
			}
		}
	} else if (str == "restart") {
		Cls();
		system("Library");
		exit(0);
	} else if (str == "skin") {
		cout << "★ 请选择皮肤：" << endl;
		cout << "【 0 】 中规中矩 " << endl; 
		cout << "【 1 】 黑客帝国 " << endl;
		cout << "【 2 】 红黄预警 " << endl;
		cout << "【 3 】 湖光潋滟 " << endl;
		cout << "【 4 】 茵茵草地 " << endl;
		cout << "【 5 】 国学世界 " << endl;

		select = Read( 0, 5 );
		switch ( select ){
			case 0:	system("color 0F"); break;
			case 1:	system("color 0A"); break;
			case 2:	system("color EC"); break;
			case 3:	system("color B9"); break;
			case 4:	system("color A2"); break;
			case 5:	system("color F0"); break;
		}
		Welcome();
	} else if (str == "save") {
		Lib.Output ();
	} else flag = false;
	return flag;
} 

//清屏函数 
void Cls(){
    system("cls");
}

//字符串转换成数字的函数 
int val(string s)
{
    int i, x = 0;
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
//用户输入不合法输出
void Hint()
{
    if (start) cout << "→ 您的输入我看不懂 @_@ ~ 请您重新输入~" << endl;
	start = false;
}

void Hint2() {
    if (start) cout << "→ 您的数字指令超出合法范围 @_@ ~ 请您重新输入~~" << endl;
	start = false;
}

//获得用户输入的整数
int Read( int l = -100000 , int r = 100000 )
{
    int x;
    do {
		if (!boot) start = true; else boot = false;
		getline( cin, str ) ;
        if (Check()) continue;			
        x = val(str);								
		if (x == error_code) Hint();			
        else if (x < l || x > r)  {						
            x = error_code;
            Hint2();
        }
    } while (x == error_code);
    
    return (x);
}

//程序初始化函数 
void Init(){
	system("fullscreen 1");
	system("color 0a");
	system("prompt ★");
	system("title 星海碧空图书馆管理系统 V1.2 SP1 Build 20100105 作者：F0903028 5090109228 杜若飞");
}

void Wait(){
    system( "pause" );
}

void Center()
{
	bool exit = false; 
	do { Cls(); 	
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【我的个人空间】                            ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 1 】  我的信息浏览                                              ┃" << endl;
    cout << "┃       【 2 】  我的信息更改                                              ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    ans = Read(0,2);
    switch (ans)
    {
		case 1: Cls(); Center_UserView(); break;
		case 2: Cls(); Center_UserModify(); break;
        case 0: exit = true; break;
    }    
	} while (!exit);
} 

void Center_UserView()
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【我的信息浏览】                            ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
	Lib.ShowUser(-1);

    ans = Read(0,0);
    switch (ans) {
        case 0: break;
    }    
} 

void Center_UserModify()
{
	do { Cls(); 	
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【我的信息更改】                            ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 1 】  更改用户名                                                ┃" << endl;
    cout << "┃       【 2 】  更改密码                                                  ┃" << endl;
    cout << "┃       【 3 】  更改工作单位                                              ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    ans = Read(0,3);
    switch (ans){
		case 1: Lib.SetMyName();  break;
		case 2: Lib.SetMyPW();    break;
		case 3: Lib.SetMyDept();  break;
        case 0: return; break;
    }    
	cout << "★ 设置成功！" << endl; Wait();
	} while ( true );
} 

void Search() {
	bool exit = false;
	do { Cls(); 
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【查询系统】                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 1 】  书目查询                                                  ┃" << endl;
    cout << "┃       【 2 】  读者查询                                                  ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    ans = Read(0,2);
    switch (ans) {
		case 1: Cls(); Search_Book(); break;
		case 2: Cls(); Search_Reader(); break;
        case 0: exit = true; break;
    }    
	} while (!exit);
} 

void Search_Book( int page )
{
	int i;
	ans = 0;
	string keywords;
	bool searching = false;
	do{ Cls(); 
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【书目查询】                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
	if ( page == 0 )
    cout << "┃       【 1 】  显示第一页                                                ┃" << endl;
	else 
	cout << "┃       【 1 】  显示上一页                                                ┃" << endl;
	if ( Lib.GetBookResult() > page + pageset )
    cout << "┃       【 2 】  显示下一页                                                ┃" << endl;
    cout << "┃       【 3 】  输入关键字搜索图书信息                                    ┃" << endl;
	cout << "┃       【 4 】  查询单册信息                                              ┃" << endl;
	cout << "┃       【 5 】  设置查询类别（当前:"; 
							   cout << Lib.GetBookSMode() << "                           ┃" << endl;
	cout << "┃       【 6 】  浏览所有书目                                              ┃" << endl;
    cout << "┃       【 7 】  对查找结果重排序                                          ┃" << endl;
	cout << "┃       【 8 】  结果中搜寻模式（当前："; 
	                     cout << Lib.GetFindMode() << "）                                ┃" << endl;
	cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 

	if (Lib.GetBookResult() == 0) { cout << "▲ 对不起，当前图书馆没有您想要的书~~~ 请浏览全部书目。" << endl; Lib.InitSBook(); }
	if ( searching ) cout << "共找到结果: " << Lib.GetBookResult() << "个。" << "当前显示第" << page / pageset + 1 << "页。" << endl;
	if ( ans == 1 || ans == 2 || searching ) Lib.Book_Show( page, pageset );
	ans = Read(0,9);
    switch (ans)
    {
		case 1:		if ( page > 0 ) page -= pageset; break;
		case 2:		if ( Lib.GetBookResult() > page + pageset ) page += pageset; break;
		case 3:		cout << "◇ 请输入关键字："; 
					getline( cin, keywords ); 
					Lib.Findout ( keywords );
					searching = true;
					page = 0;
					break;
		case 4:		Lib.ShowCertainBook(); Wait(); break;
		case 5:		Cls(); Lib.ShowSetBookKey(); Wait();
					break;
		case 6:		Lib.InitSBook(); break;
		case 7:		Cls();
					cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
					cout << "┃                                                                          ┃" << endl;
					cout << "┃      【 0 】按 标题 排序                                                 ┃" << endl;
					cout << "┃      【 1 】按 ISBN 排序                                                 ┃" << endl;
					cout << "┃      【 2 】按 作者 排序                                                 ┃" << endl;
					cout << "┃      【 3 】按 索书号 排序                                               ┃" << endl;
					cout << "┃      【 4 】按 类别 排序                                                 ┃" << endl; 
					cout << "┃      【 5 】按 编号 排序                                                 ┃" << endl; 
					cout << "┃                                                                          ┃" << endl;
					cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
					i = Read( 0, 5);
					Lib.Sort( i );
					break;
		case 8:		cout << "★ 请输入搜索模式：【0】 在全数据库中搜索  【1】 在结果中搜索" << endl;
					i = Read(0, 1);
					Lib.SetFindMode(i);
					break;
		case 9:		cout << "☆ 请输入要跳到多少页：" ; 
					page = Read( 1, Lib.GetBookResult() / pageset );
					break;
        case 0:		return; break;
    }    
	} while ( true );
} 

void Search_Reader( int page )
{	ans = 0; 
	string keywords;
	bool exit = false, searching = false;
	int i; 
	do{ Cls(); 
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【读者查询】                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
	if ( page == 0 )
    cout << "┃       【 1 】  第一页                                                    ┃" << endl;
	else 
	cout << "┃       【 1 】  上一页                                                    ┃" << endl;
	if (Lib.GetUserResult() > page + pageset)
    cout << "┃       【 2 】  下一页                                                    ┃" << endl;
    cout << "┃       【 3 】  输入关键字                                                ┃" << endl;
	cout << "┃       【 4 】  设置查询类别（当前:" << Lib.GetUserSMode() << "查询）                             ┃" << endl;
	cout << "┃       【 5 】  查询读者详细信息                                          ┃" << endl;
	cout << "┃       【 6 】  浏览所有读者                                              ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
	//搜索结果提示信息：
	if ( searching ) cout << "共找到结果: " << Lib.GetUserResult() << "个。" << "当前显示第" << page / pageset + 1 << "页。" << endl;
	if ( ans == 1 || ans == 2 || searching ) Lib.User_Show( page );
	ans = Read(0,6);
    switch (ans)
    {
		case 1:		if ( page > 0) page -= pageset; break;
		case 2:		if ( Lib.GetUserResult() > page + pageset) page += pageset; break;
		case 3:		cout << "◇ 请输入关键字："; 
					getline( cin, keywords ); 
					Lib.FindoutUser ( keywords ); 
					searching = true;
					break;
		case 4:		Cls(); Lib.SetUserSMode(); break;
		case 5:		if ( Lib.I->GetType() > 1 ) { cout << "★ 您不是管理员，无权查看！" << endl; break; }
					cout << "☆ 请输入读者ID";		i = Read( 1, Lib.UserTotal );
					i = Lib.LocateUser( i );
					if ( i == -1 ) cout << "★ 您所查找的读者不存在！"; else Lib.ShowUser(i);
					Wait();
					break;
		case 6:		Lib.InitSUser(); break;
        case 0:		exit = true; break;
    }    
	} while (!exit);
}

void Manage()
{
	do { Cls(); 
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【管理系统】                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 1 】  读者管理                                                  ┃" << endl;
    cout << "┃       【 2 】  书目管理                                                  ┃" << endl;
    cout << "┃       【 3 】  流通管理                                                  ┃" << endl;
	cout << "┃       【 4 】  管理员权限管理                                            ┃" << endl;
	if ( Lib.I->GetType() == 0 )
	cout << "┃       【 5 】  数据库位置修改                                            ┃" << endl;
	cout << "┃       【 6 】  MDStarea单向加密工具                                      ┃" << endl;
	cout << "┃       【 7 】  查看历史记录                                              ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    if ( Lib.I->GetType() == 0 ) ans = Read(0,7); else ans = Read(0,4);
    switch (ans)
    {
		case 1: Cls(); if ( Lib.I->GetManageUser() == 1 ) Manage_Reader(); else cout << "□ 您没有权限！"; break;
		case 2: Cls(); if ( Lib.I->GetManageBook() == 1 ) Manage_Book();   else cout << "□ 您没有权限！"; break;
		case 3: Cls(); if ( Lib.I->GetManageBorrow() == 1 ) Manage_Trans(); else cout << "□ 您没有权限！"; break;
		case 4: Cls(); if ( Lib.I->GetManageAdmin() == 1 ) Manage_Admin();  else cout << "□ 您没有权限！"; break;
		case 5: Cls(); if ( Lib.I->GetType() == 0 ) Manage_DataBase(); else cout << "□ 您没有权限！"; break;
		case 6: cout << "★ 请输入待加密字符串："; getline( cin, str);  cout << "★ 加密结果如下：" << MDStarea(str) << endl; break;
		case 7: Cls(); Lib.ShowHistory();  break;
		case 0: return; break;
    }  Wait();
	} while (true);
} 

void Manage_Reader()
{
	do { Cls(); 
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【读者管理】                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 1 】  添加读者                                                  ┃" << endl;
    cout << "┃       【 2 】  删除读者                                                  ┃" << endl;
    cout << "┃       【 3 】  修改读者                                                  ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    ans = Read(0, 3);
    switch (ans){
		case 1: Lib.AddUser(); Wait(); break; 
		case 2: Lib.DeleteUser(); Wait(); break;
		case 3: Lib.EditUser (); Wait(); break;
        case 0: return; break;
    }    
	} while (true);
} 

void Manage_Admin()
{
	do { Cls(); 
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【管理员权限管理】                          ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 1 】  修改管理员权限                                            ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    ans = Read(0,1);
	Lib.ShowAdmin();
    switch (ans){
		case 1: Lib.EditAdmin(); break; 
        case 0: return; break;
    }    
	} while (true);
} 

void Manage_Book()
{
	bool exit = false;
	do { Cls(); 
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【书目管理】                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
	cout << "┃       【 1 】  添加新书                                                  ┃" << endl;
    cout << "┃       【 2 】  删除图书                                                  ┃" << endl;
	cout << "┃       【 3 】  编辑图书                                                  ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
	cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    ans = Read(0,3);
    switch (ans){
		case 1: Lib.AddBook(); Wait(); break; 
		case 2: Lib.DeleteBook (); Wait(); break;
		case 3: Lib.EditBook (); Wait(); break;
        case 0: exit = true; break;
    }    
	} while (!exit);
} 

void Manage_Trans()
{
	do { Cls(); 
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【流通管理】                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃       【 1 】  读者借书、预约新书                                        ┃" << endl;
	cout << "┃       【 2 】  书籍归还、取消预约                                        ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    ans = Read(0,2);
    switch (ans){
		case 1:	Lib.ShowBorrow(); break;
		case 2:	Lib.ShowReturn(); break;
        case 0:	return; break;
	} Wait(); 
	} while (true);
} 

void Manage_DataBase() {
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【数据库位置修改】                          ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
	cout << "┃       【 1 】  更换书籍数据库                                            ┃" << endl;
    cout << "┃       【 2 】  更换读者数据库                                            ┃" << endl;
	cout << "┃       【 3 】  更换历史记录数据库                                        ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    ans = Read(0,2);
    switch (ans)
    {
		case 1:	Lib.SetDataBaseName(); break;
		case 2:	Lib.SetUserFileName(); break;
		case 3:	Lib.SetManageFileName(); break;
        case 0:	return; break;
    }    
	Lib.OutputSystem();
	cout << "★ 更改成功，输入restart重新启动生效！" << endl; 
	Wait();
} 

void Help()
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃       碧空图书管理系统 V1.0  【帮助系统】                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
	cout << "┃        特殊命令帮助：                                                    ┃" << endl;
	cout << "┃        【 welcome 】 返回欢迎界面                                        ┃" << endl;
	cout << "┃        【 exit    】 退出图书馆系统                                      ┃" << endl;
	cout << "┃        【 skin    】 选择皮肤                                            ┃" << endl;
	cout << "┃        【 fs      】 全屏显示                                            ┃" << endl;
	cout << "┃        【 window  】 窗口显示                                            ┃" << endl;
	cout << "┃        【 setpage 】 设置每页显示条目数                                  ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃        关键字查询示例：                                                  ┃" << endl;
	cout << "┃        书名=新 AND 类别=N                                                ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┃       【 1 】  打开碧空图书馆说明文档                                    ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
    cout << "┃       【 0 】  返回上一层                                                ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    ans = Read(0,1);
    switch (ans)
    {
        case 0: break;
		case 1: system("Readme.doc"); break;
	}    
} 

void Daily(){
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃          欢迎登录碧空图书管理系统 V1.0                                   ┃" << endl;
    cout << "┃                  www.starea.cn                                           ┃" << endl;
    cout << "┃              设计者：杜若飞(5090109228)                                  ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
	cout << "┃      请按照提示信息登录~~                                                ┃" << endl; 
    cout << "┃                                                                          ┃" << endl;   
    cout << "┃        碧空图书馆温馨提示：知识是人类进步的阶梯~                         ┃" << endl;    
    cout << "┃                                                                          ┃" << endl;
	cout << "┃        ＃〓§〓〓〓〓〓§〓〓〓〓〓〓§〓〓〓〓〓§〓＃                  ┃" << endl;
	cout << "┃            ↓　　　　　↓　　　　　　↓　　　　　↓                      ┃" << endl;
	cout << "┃　        ☆★☆　　　☆★☆　　　　☆★☆　　　☆★☆                    ┃" << endl;
	cout << "┃        ☆　新　☆　☆　年　☆　　☆　快　☆　☆　乐　☆                  ┃" << endl;
	cout << "┃　        ☆★☆　　　☆★☆　　　　☆★☆　　　☆★☆                    ┃" << endl;
	cout << "┃　　        ↓　　　　　↓　　　　　　↓　　　　　↓                      ┃" << endl;
	cout << "┃　　        ※　　　　　※　　　　　　※　　　　　※                      ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;  
}

void Welcome()
{
	do {
	Cls();
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃                     欢迎登录碧空图书管理系统 V1.0                        ┃" << endl;
    cout << "┃                          www.starea.cn                                   ┃" << endl;
    cout << "┃                      设计者：杜若飞(5090109228)                          ┃" << endl;
    cout << "┃                                                                          ┃" << endl;
	cout << "┃           【 1 】 我的个人空间                                           ┃" << endl;
    cout << "┃           【 2 】 信息查询系统                                           ┃" << endl; 
	
	if ( Lib.I->GetType() < 2 ) 
	cout << "┃           【 3 】 图书管理系统                                           ┃" << endl;   
    cout << "┃           【 4 】 帮助系统                                               ┃" << endl;   
    cout << "┃                                                                          ┃" << endl;    
    cout << "┃                                                                          ┃" << endl;
    cout << "┃    您可以随时输入welcome返回系统欢迎界面~                                ┃" << endl;
    cout << "┃              输入exit退出图书管理系统~                                   ┃" << endl; 
    cout << "┃                                                                          ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;  
	boot = true;
    ans = Read(1,4);
    switch (ans)
    {  
		case 1: Cls(); Center(); break;
        case 2: Cls(); Search(); break;
        case 3: Cls(); if ( Lib.I->GetType() < 2 ) Manage(); break;
        case 4: Cls(); Help(); break;
    } 
	} while (true);
}

int main(){
	Init();
	cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                                          ┃" << endl;
    cout << "┃          碧空图书管理系统 V1.0 初始化中...                               ┃" << endl;
	cout << "┃                                                                          ┃" << endl; 
    cout << "┃          碧空图书馆温馨提示：知识是人类进步的阶梯~                       ┃" << endl; 
	cout << "┃                                                                          ┃" << endl; 
	cout << "┃        ＃〓§〓〓〓〓〓§〓〓〓〓〓〓§〓〓〓〓〓§〓＃                  ┃" << endl;
	cout << "┃            ↓　　　　　↓　　　　　　↓　　　　　↓                      ┃" << endl;
	cout << "┃　        ☆★☆　　　☆★☆　　　　☆★☆　　　☆★☆                    ┃" << endl;
	cout << "┃        ☆　新　☆　☆　年　☆　　☆　快　☆　☆　乐　☆                  ┃" << endl;
	cout << "┃　        ☆★☆　　　☆★☆　　　　☆★☆　　　☆★☆                    ┃" << endl;
	cout << "┃　　        ↓　　　　　↓　　　　　　↓　　　　　↓                      ┃" << endl;
	cout << "┃　　        ※　　　　　※　　　　　　※　　　　　※                      ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
    cout << "┃                          www.starea.cn                                   ┃" << endl;
	cout << "┃                                                                          ┃" << endl;
	cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	Lib.Input ();
	Cls();
	while (true) {
		Daily();
		if ( Lib.Login() ) {
			cout << "◇ 登录成功！"; 
			Wait();
			Welcome();
		} else {
			cout << "◆ 登录失败！请重新登录！" << endl; 
			Wait();
		}
		Cls();
	}
    Wait();
    return 0;
}