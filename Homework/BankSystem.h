#include <iostream>
#include "SavingAccount.h"
using namespace std;

class BankSystem{
private:
	static const int MAXN = 10000;
	bool Exist[MAXN];
	SavingAccount User[MAXN];
	int MaxID, Total;

public:
	BankSystem(): Total(0), MaxID(0) { memset(Exist, 0, sizeof(Exist)) } 
	//输入
	void Input();
	//输出
	void Output();
	//开户
	void NewUser( double );
	//销户
	bool DeleteUser( int );
	//存款
	bool Save( int, double );
	//取款
	bool Draw( int );
	//返回余额
	bool GetMoney();
}