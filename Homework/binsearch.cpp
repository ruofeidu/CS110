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
    cout << "★请输入数据规模 N ：";
	cin >> n;
	cout << "★请输入 " << n << " 个整数：" << endl;
	for ( i = 0; i < n; ++i ) cin >> a[i];
	sort( a, a + n );
	cout << n << " 个整数的排序结果如下：" << endl;
	for ( i = 0; i < n; ++i ) cout << a[i] << " ";
	cout << endl << "请输入待查找数字：";
	cin >> k;

	pos = bin_search(0, n - 1);

	if ( pos == errorcode )
		cout << "★真遗憾！" << k << "在输入数据中不存在" << endl;
	else
		cout << "★找到" << k << "啦！" << k << "是第" << pos + 1 << "大的数字。" << endl;

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

	


	


