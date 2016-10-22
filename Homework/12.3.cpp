#include <iostream>
#include "Reader.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


int main()
{
	readerTeacher a( 0, "Yu Yong", "CS");
	readerStudent b( 0, "Du Ruofei", "ACM");
	//学生b不提供演示了~
	int i, n, x;
	
	cout << "演示提示：您可以输入 12 1 2 3 4 5 6 7 8 9 10 11 1 7 作为输入数据哦~" << endl;
	cout << "作为教师A，请问您想借几本书？" << endl;
	cin >> n;
	cout << "请输入" << n << "本书的编号：";
	for ( i = 0; i < n; ++i )
	{
		cin >> x;
		if ( a.bookBorrow ( x ) ) cout << "借id为" << x << "的书成功！！" << endl;
			else cout << "借id为" << x << "的书失败！！" << endl;
	}

	a.show();

	cout << "请输入您要还的书的编号：" << endl;
	cin >> x;
	if (a.bookReturn (x) ) cout << "还id为" << x << "的书成功！！" << endl;
		else cout << "还id为" << x << "的书失败！！" << endl;

	a.show();

	system("pause");
	return 0;
}