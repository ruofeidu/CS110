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
	if (Exist[id]) cout << "ע���ɹ���" << endl; else { cout << "���û��Ѿ���ע��!" << endl; return false; }
	Exist[id] = false;
}

bool BankSystem::Save( int id, double money ){
	if (Exist[id]) cout << "���ɹ���" << endl; else { cout << "���û������ڣ����ʧ��!" << endl; return false; }
	User[id].Save(money);
}

bool BankSystem::Draw( int ){
	if (Exist[id]) cout << "ȡ��ɹ���" << endl; else { cout << "���û������ڣ�ȡ��ʧ��!" << endl; return false; }
	User[id].Calculate();
	User[id].Save( User[id].Calculate() );
}

bool BankSystem::GetMoney(){
	if (Exist[id]) cout << "��������ǣ�"; else { cout << "���û������ڣ�" << endl; return false; }
	User[id].Show();
}
