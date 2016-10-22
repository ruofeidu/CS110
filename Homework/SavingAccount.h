#pragma once

class SavingAccount
{
private:
	char AccountNumber[20];	//Account
	char SavingData[8];		//Date:YYYYMMDD
	double balance;			//Total
	static double rate;
	static int total;

public:
	SavingAccount(void);
	SavingAccount(int);
	~SavingAccount(void);

	static void SetRate( double newrate ) { rate = newrate; }

	void Calculate(void);
	void Show(void);
	void Save(int x);
	void Getmoney();
};