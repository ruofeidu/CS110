//#include <iostream>
#include "Set.h"
#include "Set.cpp"
//using namespace std;

int main()
{
	Set<int> x, y, z;
	int i, a, n; 

	cout << "情输入两个整型集合（输入其他类型欢迎更改类模版），我们将为您算出两个集合的并、交、差：" << endl;
	cout << "请输入第一个集合 x 大小：" << endl;		cin >> n;
	cout << "请输入第一个集合 x 的元素：";
	for ( i = 0; i < n; ++i )
	{
		cin >> a; 
		x.Add (a);
	}
	cout << "请输入第二个集合 y 大小：" << endl;		cin >> n;
	cout << "请输入第二个集合 y 的元素：";
	for ( i = 0; i < n; ++i )
	{
		cin >> a; 
		y.Add (a);
	}

	z.Union ( x, y );
	cout << "两个集合的并："; 
	z.Show (); 
	
	z.Intersection ( x, y );
	cout << "两个集合的交：";
	z.Show ();

	z.Subtract ( x, y );
	cout << "两个集合的差：";
	z.Show ();

	system("pause");
	return 0;
}