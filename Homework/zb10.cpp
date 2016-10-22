#include <iostream>
#include "Book.h"
using namespace std;
Book a, b, c;
int total;

int main()
{
	cout << "输入两本书吧。。做个演示。。ISBN相同则可进行+=演示：" << endl;
	cin >> a >> b;
	c = a;

	if (a == b) cout << "a == b" << endl; else cout << "a != b" << endl;
	if (c > b)  cout << "a > b" << endl;
	if (a >= b)  cout << "a >= b" << endl;
	if (a < b) cout << "a < b" << endl;
	if (c <= b) cout << "a <= b" << endl;

	cout << "a++,++a,b--,--b演示：" << endl;
	a++;
	++a;
	b--;
	--b;
	cout << a << endl << b << endl;

	cout << "a+=b演示：" << endl;
	a+=b;
	cout << a << endl;

	system ("pause");
	return 0;
}
