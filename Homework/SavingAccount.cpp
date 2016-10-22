#pragma once
#include <iostream>
#include "saving_account.h"

double SavingAccount::rate = 0.05;
int  SavingAccount::total = 0;

SavingAccount::SavingAccount(void)
{
	++total;
	
    int l = 0, i = total;
    memset(AccountNumber, 0, sizeof(AccountNumber)) ;
    do
	{
		AccountNumber[l] = i % 10 ;
        i /= 10 ;
        l ++ ;
    } while(i);

	balance = 0; 
}

SavingAccount::SavingAccount(int money)
{
	++total;

    int l = 0, i = total;
    memset(AccountNumber, 0, sizeof(AccountNumber)) ;
    do
	{
		AccountNumber[l] = i % 10 ;
        i /= 10 ;
        l ++ ;
    } while(i);

	balance = money;
}

SavingAccount::~SavingAccount(void)
{
	--total;
}

void SavingAccount::Save(int x)
{
	balance = x;
}

void SavingAccount::Getmoney()
{
	return balance;
}

void SavingAccount::Calculate()
{
	balance += balance * rate;
}

void SavingAccount::Show()
{
	std::cout << "您的存款金额为：" << balance << std::endl;	
}

