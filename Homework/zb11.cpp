#include <iostream>
#include "Reader.h"
#include "Administrator.h"
#define _CRT_SECURE_ID_WARNINGS
using namespace std;


int main()
{
	//Student c( 0, "Du Ruofei", "ACM");
	//ѧ��c���ṩ��ʾ��~
	int i, n, x;
	string PW;

	Teacher a( 0, "Yu Yong", "CS");
	Administrator b( 0, "Boss", "ACM");
	
	cout << "���޸Ĺ���Ա���룺";
	cin >> PW;
	b.ModifyPW( PW );

	cout << "���������ԱҪԤ�������ISBN:";
	cin >> x; 
	if ( b.Order( x ) ) cout << "Ԥ���ɹ���" << endl;

	cout << "��ʾ��ʾ������������ 12 1 2 3 4 5 6 7 8 9 10 11 1 7 ��Ϊ��������Ŷ~" << endl;
	cout << "��Ϊ��ʦA����������輸���飿" << endl;
	cin >> n;
	cout << "������" << n << "����ı�ţ�";
	for ( i = 0; i < n; ++i )
	{
		cin >> x;
		if ( a.Borrow ( x ) ) cout << "��idΪ" << x << "����ɹ�����" << endl;
			else cout << "��idΪ" << x << "����ʧ�ܣ���" << endl;
	}

	a.Show();

	cout << "��������Ҫ������ı�ţ�" << endl;
	cin >> x;
	if (a.Return (x) ) cout << "��idΪ" << x << "����ɹ�����" << endl;
		else cout << "��idΪ" << x << "����ʧ�ܣ���" << endl;

	a.Show();

	system("pause");
	return 0;
}