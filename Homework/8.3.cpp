#include <iostream>
#include <math.h>
using namespace std;

struct rationalT
{
	int num, den;
	bool neg;
};

//Get the Greatest Common Divisor
int GCD( int a, int b )
{
	if ( b == 0 )
		return a;
	else
		return GCD( b, a % b );
}

//Abbreviate a Rational
rationalT SimRational( rationalT x )
{
	int t;
	if ((x.num < 0 && x.den > 0) || (x.num > 0 && x.den < 0)) x.neg = true; else x.neg = false;

	x.num = abs(x.num);
	x.den = abs(x.den);

	t = GCD( x.num, x.den );
	x.num /= t;
	x.den /= t;
	
	if (x.neg) x.num = -x.num;

	return(x);
}

//Create a rational
rationalT CreateRational( int num, int den )
{
	rationalT x;

	x.num = num;
	x.den = den;

	return(x);
}

//Add two rationals
rationalT AddRational( rationalT x, rationalT y )
{
	rationalT z;
	
	z.num = x.num * y.den + y.num * x.den;
	z.den = x.den * y.den;

	return(SimRational(z));
}
	
//Multiply two rationals
rationalT MultiplyRational( rationalT x, rationalT y )
{
    rationalT z;
    
	z.num = x.num * y.num;
	z.den = x.den * y.den;
	return(SimRational(z));
}

//Get the double type of a rational
double GetRational( rationalT x )
{
	return( x.num / x.den );
}

//Get the length of a int;

void PrintRational( rationalT x )
{
	int i, l;

	x.num = abs(x.num);
	x.den = abs(x.den);

	l = max( floor( log10( double(x.num) ) ) , floor( log10( double(x.den) ) ) ) + 2;
	if (x.neg) cout << '-';
	cout << x.num << endl;
	for ( i = 0; i < l; ++i ) cout << '-';
	cout << endl << x.den << endl;
}

int main()
{
	rationalT x, y;
	int a, b;

	cout << "◆请输入两个有理数，我们将输出他们的和与乘积~" << endl;
	cout << "◇请输入第一个有理数的分子：";		cin >> a;
	cout << "◇请输入第一个有理数的分母：";		cin >> b;
	x = CreateRational( a, b );

	cout << "◇请输入第二个有理数的分子：";		cin >> a;
	cout << "◇请输入第二个有理数的分母：";		cin >> b;
	y = CreateRational( a, b );					cout << endl;

	cout << "★两个数的和为：" << endl;
	PrintRational( AddRational( x, y ) );
	cout << endl;

	cout << "★两个数的积为：" << endl;
	PrintRational( MultiplyRational( x, y ) );
	cout << endl;

	system("pause");
	return(0);
}
