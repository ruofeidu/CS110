//P123 6
#include <iostream>
#include <algorithm>
using namespace std;

const int errorcode = -555555;
int a[1000000];
int i, n, pos, k;

int bin_search( int l, int r );

int main()
{
    cout << "�����������ݹ�ģ N ��";
	cin >> n;
	cout << "�������� " << n << " ��������" << endl;
	for ( i = 0; i < n; ++i ) cin >> a[i];
	sort( a, a + n );
	cout << n << " �����������������£�" << endl;
	for ( i = 0; i < n; ++i ) cout << a[i] << " ";
	cout << endl << "��������������֣�";
	cin >> k;

	pos = bin_search(0, n - 1);

	if ( pos == errorcode )
		cout << "�����ź���" << k << "�����������в�����" << endl;
	else
		cout << "���ҵ�" << k << "����" << k << "�ǵ�" << pos + 1 << "������֡�" << endl;

	system("pause");
	return 0;
}

int bin_search( int l, int r)
{
	if (l > r) return errorcode;
	int p = a[(l + r) / 2];
	if (p == k)
		return (l + r) / 2;
	else if (k < p)
		return (bin_search( l, (l + r) / 2 - 1));
	else if (k > p)
		return (bin_search( (l + r) / 2 + 1, r));
}

	


	


