#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "saving_account.h"

//整数随机数生成函数 
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
	cout << "O(∩_∩)O~欢迎您使用Saving Account类~~~~~" << endl;
	cout << "这是一个自动演示程序。。存款钱数是随机的..." << endl;
	for (i = 0; i < n; ++i) { cout << "账户" << i << "："; a[i].Show(); }
	cout << "一个月后...." << endl;
	for (i = 0; i < n; ++i) a[i].Calculate();
	for (i = 0; i < n; ++i) { cout << "账户" << i << "："; a[i].Show(); }
	

	cout << "请输入新的存款利率：";
	cin >> x;
	SavingAccount::SetRate(x);
	cout << "又一个月后...." << endl;
	for (i = 0; i < n; ++i) a[i].Calculate();
	for (i = 0; i < n; ++i) { cout << "账户" << i << "："; a[i].Show(); }

	system("pause");
	return(0);
}