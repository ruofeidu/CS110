#include <iostream>
#include "Book.h"
using namespace std;
const int maxbook = 10000;
Book books[maxbook];
int total, i;

void Solve()
{
    cin >> books[1];
    cin >> books[2];
    if (books[1] == books[2])
        cout << (books[1] + books[2]) << endl;
    else
        cout << "������~ ��������ISBN��һ��Ŷ~~" << endl;
}

void Wait()
{
    system( "pause" );
}

void Welcome()
{
    cout << "��������������������������������������������������������" << endl;   
    cout << "��                                                    ��" << endl;
    cout << "��           ��ӭ���ʱ̿�ͼ�����ϵͳ                 ��" << endl;
    cout << "��                www.starea.cn                       ��" << endl;
    cout << "��                �����ˣ�������                      ��" << endl;
    cout << "��              F0903028 5090109228                   ��" << endl;
    cout << "��������������������������������������������������������" << endl; 
    cout << "�밴����ʾ��������ISBN����ͬ�����ISBN��źͿ���������" << endl;
}

int main()
{
    Welcome();
    Solve();
    Wait();
    return 0;
}
 
