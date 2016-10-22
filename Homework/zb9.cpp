#include <iostream>
#include "Book.h"
using namespace std;
const int maxbook = 10000;
Book books[maxbook];
int total;

void Welcome();
void Swap(Book &a, Book &b);
void Solve();
void Qsort(int l, int r);

void Swap(Book &a, Book &b)
{
    Book c;
    c = a; a = b; b = c;
}

void Qsort(int l, int r)
{
    int i, j;
    Book pivot;
    
    i = l;  j = r;
    pivot = books[(i + j) / 2];
    
    do
    {
		while ( strcmp( books[i].getIsbn(), pivot.getIsbn() ) < 0 ) ++i;
		while ( strcmp( pivot.getIsbn(), books[j].getIsbn() ) < 0 ) --j;
	    //while ( books[i] < pivot ) ++i;
        //while ( pivot < books[j] ) --j;

        if ( i <= j )
        {
            Swap( books[i], books[j] );
            ++i; --j;
        }
    } while ( i <= j );
    
    if (l < j) Qsort(l, j);
    if (i < r) Qsort(i, r);
} 

void Solve()
{
    int i, N = 10;
    cout << "�밴����ʾ����" << N << "�����ISBN��źͿ���������" << endl;
    for ( i = 0; i < N; ++i ) cin >> books[i];
    
    Qsort(0, N - 1);
    
    Welcome();
    cout << "��" << N << "����İ�ISBN������������£�" << endl;
    for ( i = 0; i < 10; ++i ) cout << books[i] << endl;

	//���캯�����£�
	//"Book(): borrowed(0), copy(0), writer_num(0) { isbn[0] = '\\0'; writer[0][0] = '\\0'; name[0] = '\\0'; index[0] = '\\0'; " << endl;
}

void Welcome()
{
    system( "cls" );
    cout << "��������������������������������������������������������" << endl;   
    cout << "��                                                    ��" << endl;
    cout << "��           ��ӭ���ʱ̿�ͼ�����ϵͳ                 ��" << endl;
    cout << "��                www.starea.cn                       ��" << endl;
    cout << "��                �����ˣ�������                      ��" << endl;
    cout << "��              F0903028 5090109228                   ��" << endl;
    cout << "��������������������������������������������������������" << endl; 
}

int main()
{
    Welcome();
    Solve();
    system( "pause" );
    return 0;
}
 
