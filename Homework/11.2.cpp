#include <iostream>
#include "LongLongInt.h"
using namespace std;

int main()
{	
	LongLongInt a, b, c;
	
	cout << "O(��_��)O~��ӭ��ʹ��LongLongInt���ǿ��~~~~~" << endl;
	cout << "�����������߾�������a��b��ÿ��һ����" << endl;

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