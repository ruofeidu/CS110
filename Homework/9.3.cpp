#include <iostream>
#include "seq.h"
using namespace std;

int main()
{
	char *str = new char[200];
	int num;

	cout << "��Ĭ�ϱ����ʾ��" << endl;
	cout << GetNextLabel() << endl;
	cout << GetNextLabel() << endl;
	cout << GetNextLabel() << endl;

	cout << "���������µı�ǩ��";
	cin >> str;
	SetLabel(str);
	cout << "���������µı�ţ�";
	cin >> num;
	SetInitNumber(num);
	cout << "���µı����ʾ��" << endl;
	cout << GetNextLabel() << endl;
	cout << GetNextLabel() << endl;
	cout << GetNextLabel() << endl;

	system("pause");
	return(0);
}
