#include <iostream>
#include "seq.h"
using namespace std;

int main()
{
	char *str = new char[200];
	int num;

	cout << "☆默认标号演示：" << endl;
	cout << GetNextLabel() << endl;
	cout << GetNextLabel() << endl;
	cout << GetNextLabel() << endl;

	cout << "㈠请输入新的标签：";
	cin >> str;
	SetLabel(str);
	cout << "①请输入新的编号：";
	cin >> num;
	SetInitNumber(num);
	cout << "★新的标号演示：" << endl;
	cout << GetNextLabel() << endl;
	cout << GetNextLabel() << endl;
	cout << GetNextLabel() << endl;

	system("pause");
	return(0);
}
