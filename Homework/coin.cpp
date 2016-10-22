//P123 8
#include <iostream>
using namespace std;
const int n = 5, MAX = 100000;
const int coins[n] = {1, 5, 10, 21, 25};
int i, j, m;
int used[MAX], f[MAX], g[MAX];

int main()
{
	cout << "→请输入您需要找零的零钱：";
	cin >> m;

	if ( m > MAX )
	{
		cout << "您输入的零钱数额巨大，请咨询中国银行找零！" << endl;
		system("pause"); return(0);
	}
	else if ( m < 0 )
	{	
		cout << "您输入的零钱为负，我们不能找。。。" << endl;
		system("pause"); return(0);
	}

	//f[i]表示找零钱为i时最少需要f[i]个硬币，g[i]记录动态规划前一个阶段所选择的方案。
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
		cout << "●该零钱不能被找零~ 无解~" << endl;
		system("pause"); exit(0);
	}

	i = m;
	do
	{
		++used[ g[i] ];
		i -= coins[ g[i] ];
	} while ( i > 0 );

	cout << "●这个零钱最少需要" << f[m] << "个硬币来找" << endl;
	cout << "◆硬币找零的一种方案如下：" << endl;
	for ( i = 0; i < n; ++i )
		cout << "☆需要面值为" << coins[i] << "的硬币" << used[i] << "个。" << endl;

	system("pause");
	return(0);
}

