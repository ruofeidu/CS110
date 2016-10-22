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
	//����
	void Input();
	//���
	void Output();
	//����
	void NewUser( double );
	//����
	bool DeleteUser( int );
	//���
	bool Save( int, double );
	//ȡ��
	bool Draw( int );
	//�������
	bool GetMoney();
}