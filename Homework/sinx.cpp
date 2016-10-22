//P123 2
#include <iostream>
#include <math.h>
using namespace std;

const double pi2 = 3.1415926535897932 * 2;
char neg;
double x, epsilon;
double f ( double x );

int main()
{
	cout << "∑ 我们将为您计算 sin x 的值，请您先输入未知数x：";
	cin >> x;
	if ( x < 0 ) neg = '-'; else neg = ' ';
	x = abs( x );
	x = x - pi2 * floor( x / pi2 );
	cout << "∵ 无穷级数中最后一项的绝对值应大于ε：";
	cin >> epsilon;
	cout << "∴ sin x 的值为：" << neg << f(x) << endl << endl;
	system("pause");
	return 0;
}

double f ( double x )
{
	// sin x = sigma( (-1)^(k+1) x^(2k-1) / k! )
	double ans = 0, item = x, x_sqr = x * x;
	bool minus = false;
	int i = 1;

	do
	{
		if ( minus ) ans -= item; else ans += item;
		item *= x_sqr / ( i + 1 ) / ( i + 2 );
		//cout << ans << " " << item << endl;
		i += 2;
		minus = !minus;
	} while (item > epsilon);

	return( ans );
}
