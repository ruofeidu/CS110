#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "saving_account.h"

//������������ɺ��� 
int Random( int x )
{
    return ( rand() * x / (RAND_MAX + 1) );
}

int main(int argc, char* argv[])
{
	const int MAXN = 10;

	srand( time(NULL) );
	SavingAccount a[MAXN];
	int i, x, n = MAXN;

	for (i = 0; i < n; ++i) a[i].Save (Random(10000));
	cout << "O(��_��)O~��ӭ��ʹ��Saving Account��~~~~~" << endl;
	cout << "����һ���Զ���ʾ���򡣡����Ǯ���������..." << endl;
	for (i = 0; i < n; ++i) { cout << "�˻�" << i << "��"; a[i].Show(); }
	cout << "һ���º�...." << endl;
	for (i = 0; i < n; ++i) a[i].Calculate();
	for (i = 0; i < n; ++i) { cout << "�˻�" << i << "��"; a[i].Show(); }
	

	cout << "�������µĴ�����ʣ�";
	cin >> x;
	SavingAccount::SetRate(x);
	cout << "��һ���º�...." << endl;
	for (i = 0; i < n; ++i) a[i].Calculate();
	for (i = 0; i < n; ++i) { cout << "�˻�" << i << "��"; a[i].Show(); }

	system("pause");
	return(0);
}