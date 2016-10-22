#include <iostream>
#include "LongLongInt.h"
using namespace std;

int main()
{	
	LongLongInt a, b, c;
	
	cout << "O(∩_∩)O~欢迎您使用LongLongInt类加强版~~~~~" << endl;
	cout << "请输入两个高精度数字a，b，每行一个：" << endl;

	cin >> a;
	cin >> b;

	c = a + b;
	cout << "a + b = " << c << endl;

	c = a - b;
	cout << "a - b = " << c << endl;

	c = a * b;
	cout << "a * b = " << c << endl;
	
	//c = a / b;
	//cout << c << endl;

	if (a == b) cout << "a == b" << endl;
	if (a > b)  cout << "a > b" << endl;
	if (a >= b)  cout << "a >= b" << endl;
	if (a < b) cout << "a < b" << endl;
	if (a <= b) cout << "a <= b" << endl;
	

	system("pause");
	return(0);
}