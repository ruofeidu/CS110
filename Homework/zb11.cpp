#include <iostream>
#include "Reader.h"
#include "Administrator.h"
#define _CRT_SECURE_ID_WARNINGS
using namespace std;


int main()
{
	//Student c( 0, "Du Ruofei", "ACM");
	//学生c不提供演示了~
	int i, n, x;
	string PW;

	Teacher a( 0, "Yu Yong", "CS");
	Administrator b( 0, "Boss", "ACM");
	
	cout << "请修改管理员密码：";
	cin >> PW;
	b.ModifyPW( PW );

	cout << "请输入管理员要预定的书的ISBN:";
	cin >> x; 
	if ( b.Order( x ) ) cout << "预定成功！" << endl;

	cout << "演示提示：您可以输入 12 1 2 3 4 5 6 7 8 9 10 11 1 7 作为输入数据哦~" << endl;
	cout << "作为教师A，请问您想借几本书？" << endl;
	cin >> n;
	cout << "请输入" << n << "本书的编号：";
	for ( i = 0; i < n; ++i )
	{
		cin >> x;
		if ( a.Borrow ( x ) ) cout << "借id为" << x << "的书成功！！" << endl;
			else cout << "借id为" << x << "的书失败！！" << endl;
	}

	a.Show();

	cout << "请输入您要还的书的编号：" << endl;
	cin >> x;
	if (a.Return (x) ) cout << "还id为" << x << "的书成功！！" << endl;
		else cout << "还id为" << x << "的书失败！！" << endl;

	a.Show();

	system("pause");
	return 0;
}