/***************************************************
  �ļ�: Menu.cpp
  ����: ������
  ѧ��: 5090109228
  ����: �Ǻ��̿�ͼ��ݹ���ϵͳ
  �༶: F0903028
  ��;���������̵Ĳ˵��ļ�
  ���룺����Զ����˵��Ķ���
***************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Library.h"
#include "MDStarea.h"
using namespace std;
const int error_code = 19910525;		//ϵͳ������
int ans, pageset = 15;					//ѡ���룬ÿҳ��ʾҳ����
bool start, boot = true;				//�Ƿ��ǵ�һ������
string str;								//ϵͳ���ұ����ַ���
Library Lib;							//ͼ������~

//ϵͳ����
void Cls();								//��������
void Wait();							//�ȴ��û���Ӧ
bool Check();							//�����жϡ��������
int Read( int l, int r);				//��������

void Init();							//��ʼ��CMD����
void Welcome();							//��ӭ����
void Center();							//�˵�_��������
void Center_UserView();					//�˵�_�û���¼
void Center_UserModify();				//�˵�_�޸��û���Ϣ
void Search();							//�˵�_����ϵͳ
void Search_Book( int page = 0 );		//�˵�_������
void Search_Reader( int page = 0 );	//�˵�_��������
void Manage();							//�˵�_����ϵͳ
void Manage_Book();						//�˵�_�����鼮
void Manage_Admin();					//�˵�_�������Ȩ��
void Manage_Reader();					//�˵�_�������
void Manage_Trans();					//�˵�_������ͨ
void Manage_DataBase();					//�˵�_�������ݿ�
void Help();							//�˵�_�������ϵͳ
void Daily();							//�˵�_ÿ��һ��

//����Ƿ�ǿ�Ʒ��ػ���ǿ���˳� 
bool Check(){
	bool flag = true; int select;
    if (str == "exit" || str == "halt" ){
		cout << "�� ϣ�����ڱ̿�ͼ��ݶȹ����ĵ�һ�죡�ټ�~ " << endl;
		Lib.Output();
        exit(0) ;
    } else if (str == "welcome" || str == "main"){
        Cls();
        Welcome();  
	} else if (str == "fullscreen" || str == "fs" ){
		system("fullscreen 1"); cout << "�� �Ѿ��л���ȫ��״̬��"; Wait();
	} else if (str == "window" || str == "win" ){
		system("fullscreen 0"); cout << "�� �Ѿ��л�������״̬��"; Wait();
	} else if (str == "about"){
		cout << "�� ���������Ǻ��̿� www.starea.cn С�Ǻ� F0903028 5090109228 �����ɿ���" << endl;
		Wait();
	} else if (str == "egg"){
		cout << "�� ��ϲ���ҵ��ʵ���������ᷢ��ʲô�أ� O(��_��)O~" << endl;
		Lib.ShowEgg();	Wait();
	} else if (str == "1 + 1"){
		cout << "1 + 1 = 2 ";
		Wait();
	} else if (str == "setpage"){
		cout << "�� ������ÿҳ��ʾ������" ; 
		select = Read( 1, 100); 
		pageset = select;
		Wait();
	} else if (str == "login"){
		while (true) {
			Cls();
			Daily();
			if ( Lib.Login() ) {
				cout << "�� ��¼�ɹ���"; 
				Wait();
				Welcome();
			} else {
			cout << "�� ��¼ʧ�ܣ������µ�¼��" << endl; 
			Wait();
			}
		}
	} else if (str == "restart") {
		Cls();
		system("Library");
		exit(0);
	} else if (str == "skin") {
		cout << "�� ��ѡ��Ƥ����" << endl;
		cout << "�� 0 �� �й��о� " << endl; 
		cout << "�� 1 �� �ڿ͵۹� " << endl;
		cout << "�� 2 �� ���Ԥ�� " << endl;
		cout << "�� 3 �� �������� " << endl;
		cout << "�� 4 �� ����ݵ� " << endl;
		cout << "�� 5 �� ��ѧ���� " << endl;

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

//�������� 
void Cls(){
    system("cls");
}

//�ַ���ת�������ֵĺ��� 
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
//�û����벻�Ϸ����
void Hint()
{
    if (start) cout << "�� ���������ҿ����� @_@ ~ ������������~" << endl;
	start = false;
}

void Hint2() {
    if (start) cout << "�� ��������ָ����Ϸ���Χ @_@ ~ ������������~~" << endl;
	start = false;
}

//����û����������
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

//�����ʼ������ 
void Init(){
	system("fullscreen 1");
	system("color 0a");
	system("prompt ��");
	system("title �Ǻ��̿�ͼ��ݹ���ϵͳ V1.2 SP1 Build 20100105 ���ߣ�F0903028 5090109228 ������");
}

void Wait(){
    system( "pause" );
}

void Center()
{
	bool exit = false; 
	do { Cls(); 	
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ���ҵĸ��˿ռ䡿                            ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 1 ��  �ҵ���Ϣ���                                              ��" << endl;
    cout << "��       �� 2 ��  �ҵ���Ϣ����                                              ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
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
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ���ҵ���Ϣ�����                            ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
	Lib.ShowUser(-1);

    ans = Read(0,0);
    switch (ans) {
        case 0: break;
    }    
} 

void Center_UserModify()
{
	do { Cls(); 	
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ���ҵ���Ϣ���ġ�                            ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 1 ��  �����û���                                                ��" << endl;
    cout << "��       �� 2 ��  ��������                                                  ��" << endl;
    cout << "��       �� 3 ��  ���Ĺ�����λ                                              ��" << endl;
	cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
    ans = Read(0,3);
    switch (ans){
		case 1: Lib.SetMyName();  break;
		case 2: Lib.SetMyPW();    break;
		case 3: Lib.SetMyDept();  break;
        case 0: return; break;
    }    
	cout << "�� ���óɹ���" << endl; Wait();
	} while ( true );
} 

void Search() {
	bool exit = false;
	do { Cls(); 
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ����ѯϵͳ��                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 1 ��  ��Ŀ��ѯ                                                  ��" << endl;
    cout << "��       �� 2 ��  ���߲�ѯ                                                  ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
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
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ����Ŀ��ѯ��                                ��" << endl;
    cout << "��                                                                          ��" << endl;
	if ( page == 0 )
    cout << "��       �� 1 ��  ��ʾ��һҳ                                                ��" << endl;
	else 
	cout << "��       �� 1 ��  ��ʾ��һҳ                                                ��" << endl;
	if ( Lib.GetBookResult() > page + pageset )
    cout << "��       �� 2 ��  ��ʾ��һҳ                                                ��" << endl;
    cout << "��       �� 3 ��  ����ؼ�������ͼ����Ϣ                                    ��" << endl;
	cout << "��       �� 4 ��  ��ѯ������Ϣ                                              ��" << endl;
	cout << "��       �� 5 ��  ���ò�ѯ��𣨵�ǰ:"; 
							   cout << Lib.GetBookSMode() << "                           ��" << endl;
	cout << "��       �� 6 ��  ���������Ŀ                                              ��" << endl;
    cout << "��       �� 7 ��  �Բ��ҽ��������                                          ��" << endl;
	cout << "��       �� 8 ��  �������Ѱģʽ����ǰ��"; 
	                     cout << Lib.GetFindMode() << "��                                ��" << endl;
	cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 

	if (Lib.GetBookResult() == 0) { cout << "�� �Բ��𣬵�ǰͼ���û������Ҫ����~~~ �����ȫ����Ŀ��" << endl; Lib.InitSBook(); }
	if ( searching ) cout << "���ҵ����: " << Lib.GetBookResult() << "����" << "��ǰ��ʾ��" << page / pageset + 1 << "ҳ��" << endl;
	if ( ans == 1 || ans == 2 || searching ) Lib.Book_Show( page, pageset );
	ans = Read(0,9);
    switch (ans)
    {
		case 1:		if ( page > 0 ) page -= pageset; break;
		case 2:		if ( Lib.GetBookResult() > page + pageset ) page += pageset; break;
		case 3:		cout << "�� ������ؼ��֣�"; 
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
					cout << "������������������������������������������������������������������������������" << endl;   
					cout << "��                                                                          ��" << endl;
					cout << "��      �� 0 ���� ���� ����                                                 ��" << endl;
					cout << "��      �� 1 ���� ISBN ����                                                 ��" << endl;
					cout << "��      �� 2 ���� ���� ����                                                 ��" << endl;
					cout << "��      �� 3 ���� ����� ����                                               ��" << endl;
					cout << "��      �� 4 ���� ��� ����                                                 ��" << endl; 
					cout << "��      �� 5 ���� ��� ����                                                 ��" << endl; 
					cout << "��                                                                          ��" << endl;
					cout << "������������������������������������������������������������������������������" << endl;
					i = Read( 0, 5);
					Lib.Sort( i );
					break;
		case 8:		cout << "�� ����������ģʽ����0�� ��ȫ���ݿ�������  ��1�� �ڽ��������" << endl;
					i = Read(0, 1);
					Lib.SetFindMode(i);
					break;
		case 9:		cout << "�� ������Ҫ��������ҳ��" ; 
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
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  �����߲�ѯ��                                ��" << endl;
    cout << "��                                                                          ��" << endl;
	if ( page == 0 )
    cout << "��       �� 1 ��  ��һҳ                                                    ��" << endl;
	else 
	cout << "��       �� 1 ��  ��һҳ                                                    ��" << endl;
	if (Lib.GetUserResult() > page + pageset)
    cout << "��       �� 2 ��  ��һҳ                                                    ��" << endl;
    cout << "��       �� 3 ��  ����ؼ���                                                ��" << endl;
	cout << "��       �� 4 ��  ���ò�ѯ��𣨵�ǰ:" << Lib.GetUserSMode() << "��ѯ��                             ��" << endl;
	cout << "��       �� 5 ��  ��ѯ������ϸ��Ϣ                                          ��" << endl;
	cout << "��       �� 6 ��  ������ж���                                              ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
	cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
	//���������ʾ��Ϣ��
	if ( searching ) cout << "���ҵ����: " << Lib.GetUserResult() << "����" << "��ǰ��ʾ��" << page / pageset + 1 << "ҳ��" << endl;
	if ( ans == 1 || ans == 2 || searching ) Lib.User_Show( page );
	ans = Read(0,6);
    switch (ans)
    {
		case 1:		if ( page > 0) page -= pageset; break;
		case 2:		if ( Lib.GetUserResult() > page + pageset) page += pageset; break;
		case 3:		cout << "�� ������ؼ��֣�"; 
					getline( cin, keywords ); 
					Lib.FindoutUser ( keywords ); 
					searching = true;
					break;
		case 4:		Cls(); Lib.SetUserSMode(); break;
		case 5:		if ( Lib.I->GetType() > 1 ) { cout << "�� �����ǹ���Ա����Ȩ�鿴��" << endl; break; }
					cout << "�� ���������ID";		i = Read( 1, Lib.UserTotal );
					i = Lib.LocateUser( i );
					if ( i == -1 ) cout << "�� �������ҵĶ��߲����ڣ�"; else Lib.ShowUser(i);
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
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ������ϵͳ��                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 1 ��  ���߹���                                                  ��" << endl;
    cout << "��       �� 2 ��  ��Ŀ����                                                  ��" << endl;
    cout << "��       �� 3 ��  ��ͨ����                                                  ��" << endl;
	cout << "��       �� 4 ��  ����ԱȨ�޹���                                            ��" << endl;
	if ( Lib.I->GetType() == 0 )
	cout << "��       �� 5 ��  ���ݿ�λ���޸�                                            ��" << endl;
	cout << "��       �� 6 ��  MDStarea������ܹ���                                      ��" << endl;
	cout << "��       �� 7 ��  �鿴��ʷ��¼                                              ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
    if ( Lib.I->GetType() == 0 ) ans = Read(0,7); else ans = Read(0,4);
    switch (ans)
    {
		case 1: Cls(); if ( Lib.I->GetManageUser() == 1 ) Manage_Reader(); else cout << "�� ��û��Ȩ�ޣ�"; break;
		case 2: Cls(); if ( Lib.I->GetManageBook() == 1 ) Manage_Book();   else cout << "�� ��û��Ȩ�ޣ�"; break;
		case 3: Cls(); if ( Lib.I->GetManageBorrow() == 1 ) Manage_Trans(); else cout << "�� ��û��Ȩ�ޣ�"; break;
		case 4: Cls(); if ( Lib.I->GetManageAdmin() == 1 ) Manage_Admin();  else cout << "�� ��û��Ȩ�ޣ�"; break;
		case 5: Cls(); if ( Lib.I->GetType() == 0 ) Manage_DataBase(); else cout << "�� ��û��Ȩ�ޣ�"; break;
		case 6: cout << "�� ������������ַ�����"; getline( cin, str);  cout << "�� ���ܽ�����£�" << MDStarea(str) << endl; break;
		case 7: Cls(); Lib.ShowHistory();  break;
		case 0: return; break;
    }  Wait();
	} while (true);
} 

void Manage_Reader()
{
	do { Cls(); 
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  �����߹���                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 1 ��  ��Ӷ���                                                  ��" << endl;
    cout << "��       �� 2 ��  ɾ������                                                  ��" << endl;
    cout << "��       �� 3 ��  �޸Ķ���                                                  ��" << endl;
	cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
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
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ������ԱȨ�޹���                          ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "��       �� 1 ��  �޸Ĺ���ԱȨ��                                            ��" << endl;
	cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
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
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ����Ŀ����                                ��" << endl;
    cout << "��                                                                          ��" << endl;
	cout << "��       �� 1 ��  �������                                                  ��" << endl;
    cout << "��       �� 2 ��  ɾ��ͼ��                                                  ��" << endl;
	cout << "��       �� 3 ��  �༭ͼ��                                                  ��" << endl;
    cout << "��                                                                          ��" << endl;
	cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
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
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ����ͨ����                                ��" << endl;
    cout << "��                                                                          ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��       �� 1 ��  ���߽��顢ԤԼ����                                        ��" << endl;
	cout << "��       �� 2 ��  �鼮�黹��ȡ��ԤԼ                                        ��" << endl;
	cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
    ans = Read(0,2);
    switch (ans){
		case 1:	Lib.ShowBorrow(); break;
		case 2:	Lib.ShowReturn(); break;
        case 0:	return; break;
	} Wait(); 
	} while (true);
} 

void Manage_DataBase() {
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  �����ݿ�λ���޸ġ�                          ��" << endl;
    cout << "��                                                                          ��" << endl;
	cout << "��       �� 1 ��  �����鼮���ݿ�                                            ��" << endl;
    cout << "��       �� 2 ��  �����������ݿ�                                            ��" << endl;
	cout << "��       �� 3 ��  ������ʷ��¼���ݿ�                                        ��" << endl;
	cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
    ans = Read(0,2);
    switch (ans)
    {
		case 1:	Lib.SetDataBaseName(); break;
		case 2:	Lib.SetUserFileName(); break;
		case 3:	Lib.SetManageFileName(); break;
        case 0:	return; break;
    }    
	Lib.OutputSystem();
	cout << "�� ���ĳɹ�������restart����������Ч��" << endl; 
	Wait();
} 

void Help()
{
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��       �̿�ͼ�����ϵͳ V1.0  ������ϵͳ��                                ��" << endl;
    cout << "��                                                                          ��" << endl;
	cout << "��        �������������                                                    ��" << endl;
	cout << "��        �� welcome �� ���ػ�ӭ����                                        ��" << endl;
	cout << "��        �� exit    �� �˳�ͼ���ϵͳ                                      ��" << endl;
	cout << "��        �� skin    �� ѡ��Ƥ��                                            ��" << endl;
	cout << "��        �� fs      �� ȫ����ʾ                                            ��" << endl;
	cout << "��        �� window  �� ������ʾ                                            ��" << endl;
	cout << "��        �� setpage �� ����ÿҳ��ʾ��Ŀ��                                  ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��        �ؼ��ֲ�ѯʾ����                                                  ��" << endl;
	cout << "��        ����=�� AND ���=N                                                ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "��       �� 1 ��  �򿪱̿�ͼ���˵���ĵ�                                    ��" << endl;
	cout << "��                                                                          ��" << endl;
    cout << "��       �� 0 ��  ������һ��                                                ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl; 
    ans = Read(0,1);
    switch (ans)
    {
        case 0: break;
		case 1: system("Readme.doc"); break;
	}    
} 

void Daily(){
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��          ��ӭ��¼�̿�ͼ�����ϵͳ V1.0                                   ��" << endl;
    cout << "��                  www.starea.cn                                           ��" << endl;
    cout << "��              ����ߣ�������(5090109228)                                  ��" << endl;
    cout << "��                                                                          ��" << endl;
	cout << "��      �밴����ʾ��Ϣ��¼~~                                                ��" << endl; 
    cout << "��                                                                          ��" << endl;   
    cout << "��        �̿�ͼ�����ܰ��ʾ��֪ʶ����������Ľ���~                         ��" << endl;    
    cout << "��                                                                          ��" << endl;
	cout << "��        ��������������������������������������������                  ��" << endl;
	cout << "��            ����������������������������������������                      ��" << endl;
	cout << "����        ���������������������������                    ��" << endl;
	cout << "��        ��¡����ꡡ�����졡���֡���                  ��" << endl;
	cout << "����        ���������������������������                    ��" << endl;
	cout << "������        ����������������������������������������                      ��" << endl;
	cout << "������        ����������������������������������������                      ��" << endl;
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl;  
}

void Welcome()
{
	do {
	Cls();
    cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��                     ��ӭ��¼�̿�ͼ�����ϵͳ V1.0                        ��" << endl;
    cout << "��                          www.starea.cn                                   ��" << endl;
    cout << "��                      ����ߣ�������(5090109228)                          ��" << endl;
    cout << "��                                                                          ��" << endl;
	cout << "��           �� 1 �� �ҵĸ��˿ռ�                                           ��" << endl;
    cout << "��           �� 2 �� ��Ϣ��ѯϵͳ                                           ��" << endl; 
	
	if ( Lib.I->GetType() < 2 ) 
	cout << "��           �� 3 �� ͼ�����ϵͳ                                           ��" << endl;   
    cout << "��           �� 4 �� ����ϵͳ                                               ��" << endl;   
    cout << "��                                                                          ��" << endl;    
    cout << "��                                                                          ��" << endl;
    cout << "��    ��������ʱ����welcome����ϵͳ��ӭ����~                                ��" << endl;
    cout << "��              ����exit�˳�ͼ�����ϵͳ~                                   ��" << endl; 
    cout << "��                                                                          ��" << endl;
    cout << "������������������������������������������������������������������������������" << endl;  
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
	cout << "������������������������������������������������������������������������������" << endl;   
    cout << "��                                                                          ��" << endl;
    cout << "��          �̿�ͼ�����ϵͳ V1.0 ��ʼ����...                               ��" << endl;
	cout << "��                                                                          ��" << endl; 
    cout << "��          �̿�ͼ�����ܰ��ʾ��֪ʶ����������Ľ���~                       ��" << endl; 
	cout << "��                                                                          ��" << endl; 
	cout << "��        ��������������������������������������������                  ��" << endl;
	cout << "��            ����������������������������������������                      ��" << endl;
	cout << "����        ���������������������������                    ��" << endl;
	cout << "��        ��¡����ꡡ�����졡���֡���                  ��" << endl;
	cout << "����        ���������������������������                    ��" << endl;
	cout << "������        ����������������������������������������                      ��" << endl;
	cout << "������        ����������������������������������������                      ��" << endl;
	cout << "��                                                                          ��" << endl;
    cout << "��                          www.starea.cn                                   ��" << endl;
	cout << "��                                                                          ��" << endl;
	cout << "������������������������������������������������������������������������������" << endl;
	Lib.Input ();
	Cls();
	while (true) {
		Daily();
		if ( Lib.Login() ) {
			cout << "�� ��¼�ɹ���"; 
			Wait();
			Welcome();
		} else {
			cout << "�� ��¼ʧ�ܣ������µ�¼��" << endl; 
			Wait();
		}
		Cls();
	}
    Wait();
    return 0;
}