#include <iostream>
#include "Book.h"
using namespace std;
Book a, b, c;
int total;

int main()
{
	cout << "����������ɡ���������ʾ����ISBN��ͬ��ɽ���+=��ʾ��" << endl;
	cin >> a >> b;
	c = a;

	if (a == b) cout << "a == b" << endl; else cout << "a != b" << endl;
	if (c > b)  cout << "a > b" << endl;
	if (a >= b)  cout << "a >= b" << endl;
	if (a < b) cout << "a < b" << endl;
	if (c <= b) cout << "a <= b" << endl;

	cout << "a++,++a,b--,--b��ʾ��" << endl;
	a++;
	++a;
	b--;
	--b;
	cout << a << endl << b << endl;

	cout << "a+=b��ʾ��" << endl;
	a+=b;
	cout << a << endl;

	system ("pause");
	return 0;
}
