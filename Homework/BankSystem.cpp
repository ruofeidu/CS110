#include <fstream>
#include <iostream>
#include <string>
#include "BankSystem.h"
#include "SavingAccount.h"
using namespace std;

void BankSystem::Input(){
	ifstream fin;
	double money;

	fin.open ("bank.in");

	fin >> Total;
	for ( int i = 0; i < Total; ++i ) {
		fin >> id >> money;
		MaxID = max( MaxID, id );
		Exist[id] = true;
		User[id].Save(money);
	}

	fin.close();
}

void BankSystem::Output(){
	ofstream fout; 
	
	fout.open ("bank.out");
	fin.
	fout << Total;
	for ( int i = 0; i < MaxID; ++i ) if ( Exist[i] ) {
		fout << id << ' ' << User[id] << endl;
	}

	fout.close();
}

void BankSystem::NewUser( double money ){
	++MaxID; ++Total;
	User[MaxID].Save( money );
	Exist[MaxID] = true;
}
	
bool BankSystem::DeleteUser ( int id ){
	if (Exist[id]) cout << "注销成功！" << endl; else { cout << "该用户已经被注销!" << endl; return false; }
	Exist[id] = false;
}

bool BankSystem::Save( int id, double money ){
	if (Exist[id]) cout << "存款成功！" << endl; else { cout << "该用户不存在！存款失败!" << endl; return false; }
	User[id].Save(money);
}

bool BankSystem::Draw( int ){
	if (Exist[id]) cout << "取款成功！" << endl; else { cout << "该用户不存在！取款失败!" << endl; return false; }
	User[id].Calculate();
	User[id].Save( User[id].Calculate() );
}

bool BankSystem::GetMoney(){
	if (Exist[id]) cout << "您的余额是："; else { cout << "该用户不存在！" << endl; return false; }
	User[id].Show();
}
