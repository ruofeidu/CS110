#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int i;

	for ( i = 'A'; i <= 'Z'; ++i )
		cout << char(i) << "��Ӧ��Ascii���£�ʮ���ƣ�" << dec << i << " �˽��ƣ�" << oct << i << " ʮ�����ƣ�" << hex << i << endl;
	for ( i = 'a'; i <= 'z'; ++i )
		cout << char(i) << "��Ӧ��Ascii���£�ʮ���ƣ�" << dec << i << " �˽��ƣ�" << oct << i << " ʮ�����ƣ�" << hex << i << endl;
	

	system("pause");
	return 0;
}