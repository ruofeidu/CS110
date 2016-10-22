#include "longlongint.h"
#include <iostream>
using namespace std;
LongLongInt x, y, z;

int main()
{
	cout << "O(∩_∩)O~欢迎您使用LongLongInt类~~~~~" << endl;
	cout << "请输入两个 LongLongInt x,y ，每行一个，我们将作出比较" << endl;
	x.read();
	y.read();
	z.create(x);
	cout << "z 是 x 的赋值：";
	z.writeln();
	z = add(x, y);
	cout << "z 变成 x + y：";
	z.writeln();

	if (bigger(x,y))
	{
		x.write();
		cout << " > ";
		y.writeln();
	}
	if (equal(x,y))
	{
		x.write();
		cout << " = ";
		y.writeln();
	} else
	if (smaller(x,y))
	{
		x.write();
		cout << " < ";
		y.writeln();
	}

	if (small(x,y))
	{
		x.write();
		cout << " <= ";
		y.writeln();
	}

	if (big(x,y))
	{
		x.write();
		cout << " >= ";
		y.writeln();
	}

	system("pause");
	return(0);
}