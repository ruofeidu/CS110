#include "longlongint.h"
#include <iostream>
using namespace std;
LongLongInt x, y, z;

int main()
{
	cout << "O(��_��)O~��ӭ��ʹ��LongLongInt��~~~~~" << endl;
	cout << "���������� LongLongInt x,y ��ÿ��һ�������ǽ������Ƚ�" << endl;
	x.read();
	y.read();
	z.create(x);
	cout << "z �� x �ĸ�ֵ��";
	z.writeln();
	z = add(x, y);
	cout << "z ��� x + y��";
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