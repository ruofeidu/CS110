//#include <iostream>
#include "Set.h"
#include "Set.cpp"
//using namespace std;

int main()
{
	Set<int> x, y, z;
	int i, a, n; 

	cout << "�������������ͼ��ϣ������������ͻ�ӭ������ģ�棩�����ǽ�Ϊ������������ϵĲ��������" << endl;
	cout << "�������һ������ x ��С��" << endl;		cin >> n;
	cout << "�������һ������ x ��Ԫ�أ�";
	for ( i = 0; i < n; ++i )
	{
		cin >> a; 
		x.Add (a);
	}
	cout << "������ڶ������� y ��С��" << endl;		cin >> n;
	cout << "������ڶ������� y ��Ԫ�أ�";
	for ( i = 0; i < n; ++i )
	{
		cin >> a; 
		y.Add (a);
	}

	z.Union ( x, y );
	cout << "�������ϵĲ���"; 
	z.Show (); 
	
	z.Intersection ( x, y );
	cout << "�������ϵĽ���";
	z.Show ();

	z.Subtract ( x, y );
	cout << "�������ϵĲ";
	z.Show ();

	system("pause");
	return 0;
}