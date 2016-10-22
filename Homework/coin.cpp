//P123 8
#include <iostream>
using namespace std;
const int n = 5, MAX = 100000;
const int coins[n] = {1, 5, 10, 21, 25};
int i, j, m;
int used[MAX], f[MAX], g[MAX];

int main()
{
	cout << "������������Ҫ�������Ǯ��";
	cin >> m;

	if ( m > MAX )
	{
		cout << "���������Ǯ����޴�����ѯ�й��������㣡" << endl;
		system("pause"); return(0);
	}
	else if ( m < 0 )
	{	
		cout << "���������ǮΪ�������ǲ����ҡ�����" << endl;
		system("pause"); return(0);
	}

	//f[i]��ʾ����ǮΪiʱ������Ҫf[i]��Ӳ�ң�g[i]��¼��̬�滮ǰһ���׶���ѡ��ķ�����
	f[0] = 0; g[0] = 0;

	for ( i = 0; i <= m; ++i )
	{
		f[i] = i;
		for ( j = 0; j < n; ++j )
		{
			if ( coins[j] > i ) continue;
			if ( f[i] > f[ i - coins[j] ] + 1 )
			{
				f[i] = f[ i - coins[j] ] + 1;
				g[i] = j;
			}
		}
	}

	if (f[m] == 0)
	{
		cout << "�����Ǯ���ܱ�����~ �޽�~" << endl;
		system("pause"); exit(0);
	}

	i = m;
	do
	{
		++used[ g[i] ];
		i -= coins[ g[i] ];
	} while ( i > 0 );

	cout << "�������Ǯ������Ҫ" << f[m] << "��Ӳ������" << endl;
	cout << "��Ӳ�������һ�ַ������£�" << endl;
	for ( i = 0; i < n; ++i )
		cout << "����Ҫ��ֵΪ" << coins[i] << "��Ӳ��" << used[i] << "����" << endl;

	system("pause");
	return(0);
}

