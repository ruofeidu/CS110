#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
	Time a, b;
	int x;

	cout << "O(��_��)O~��ӭ��ʹ��Time.h��~~~~~" << endl;
	cout << "�밴��ʾ��������ʱ�����a��b������Ϊ����ʾ��" << endl;
	cin >> a;
	cin >> b;
	cout << " a �� b �������Ϊ��" << a - b << endl;

	cout << " a == b �� " << ((a == b) ? "true" : "false") << endl;

	cout << "���������ǽ�ͨ��++��--�����Ѹ�a����2�룬��b����2�룺" << endl;
	
	a++;
	++a;
	cout << "aΪ��" << a << endl;

	b--;
	--b;
	cout << "bΪ��" << b << endl;

	cout << " a < b �� " << ((a < b) ? "true" : "false") << endl;
	cout << " a <= b �� " << ((a <= b) ? "true" : "false") << endl;
	cout << " a > b �� " << ((a > b) ? "true" : "false") << endl;
	cout << " a >= b �� " << ((a > b) ? "true" : "false") << endl;

	cout << "����������x�����ǽ��Ѹ�a����x�룬��b����x�룺" << endl;
	cin >> x;

	a += x;
	cout << "aΪ��" << a << endl;
	b -= x;
	cout << "bΪ��" <<b << endl;

	system("pause");
	return 0;
}


	
	

