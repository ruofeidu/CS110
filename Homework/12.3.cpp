#include <iostream>
#include "Reader.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


int main()
{
	readerTeacher a( 0, "Yu Yong", "CS");
	readerStudent b( 0, "Du Ruofei", "ACM");
	//ѧ��b���ṩ��ʾ��~
	int i, n, x;
	
	cout << "��ʾ��ʾ������������ 12 1 2 3 4 5 6 7 8 9 10 11 1 7 ��Ϊ��������Ŷ~" << endl;
	cout << "��Ϊ��ʦA����������輸���飿" << endl;
	cin >> n;
	cout << "������" << n << "����ı�ţ�";
	for ( i = 0; i < n; ++i )
	{
		cin >> x;
		if ( a.bookBorrow ( x ) ) cout << "��idΪ" << x << "����ɹ�����" << endl;
			else cout << "��idΪ" << x << "����ʧ�ܣ���" << endl;
	}

	a.show();

	cout << "��������Ҫ������ı�ţ�" << endl;
	cin >> x;
	if (a.bookReturn (x) ) cout << "��idΪ" << x << "����ɹ�����" << endl;
		else cout << "��idΪ" << x << "����ʧ�ܣ���" << endl;

	a.show();

	system("pause");
	return 0;
}