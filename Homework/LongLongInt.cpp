#include "LongLongInt.h"
#include <iostream>
using namespace std;

LongLongInt::LongLongInt()
{
	l = 1;
	memset(num, 0, sizeof(num));
	minus = false;
}

LongLongInt::LongLongInt(int x)
{
	l = 0;
	memset(num, 0, sizeof(num));
	while (x)
	{
		num[l++] = x % 10;
		x /= 10;
	}
	if (l == 0)	l = 1;
	minus = x < 0 ? true : false;
}

LongLongInt::operator int()
{
	int x = 0, y = l - 1;
	while (y)
	{
		x = x * 10 + num[y];
		--y;
	}
	if (minus) x = -x;
	return(x);
}


LongLongInt::operator int*()
{
	return num;
}

int LongLongInt::length()
{
	return l;
}

ostream & operator << ( ostream & os, const LongLongInt & x )
{

	if (x.minus) os << '-';
	for (int i = x.l - 1; i >= 0; --i) os << x.num[i];
	return os;
}

istream & operator >> ( istream & is, LongLongInt & x )
{
	char s[MAXL + 1];

	is >> s;
	x.l = strlen(s);
	if (s[0] != '-')
	{
		x.minus = false;
		for (int i = 0; i < x.l; ++i)
			x.num[i] = s[x.l-i-1] - '0';
	} else
	{
		x.minus = true;
		for (int i = 1; i < x.l; ++i)
			x.num[i-1] = s[x.l-i-1] - '0';
	}

	return is;
}

bool operator == (LongLongInt a, LongLongInt b)
{
	if (a.l != b.l) return(false);
	for (int i = 0; i < a.l; ++i)
			if (a.num[i] != b.num[i]) return(false); 	
	return(true);
}

bool operator > (LongLongInt a, LongLongInt b)
{
	if (a.length() < b.length()) return(false); else
	if (a.length() > b.length()) return(true);

	for (int i = a.length() - 1; i >= 0; --i)
		if (a.num[i] < b.num[i]) return(false); else
		if (a.num[i] > b.num[i]) return(true);

	return (a[0] > b[0]) ? true : false;
}

bool operator >= (LongLongInt a, LongLongInt b)
{
	if (a.length() < b.length()) return(false);
	if (a.length() > b.length()) return(true);

	for (int i = a.length() - 1; i >= 0; --i)
		if (a.num[i] < b.num[i]) return(false); else
		if (a.num[i] > b.num[i]) return(true);

	return (a[0] >= b[0]) ? true : false;
}

bool operator < (LongLongInt a, LongLongInt b)
{
	if (a.length() > b.length()) return(false);
	if (a.length() < b.length()) return(true);

	for (int i = a.length() - 1; i >= 0; --i)
		if (a.num[i] > b.num[i]) return(false); else
		if (a.num[i] < b.num[i]) return(true);

	return (a[0] < b[0]) ? true : false;
}

bool operator <= (LongLongInt a, LongLongInt b)
{
	if (a.length() > b.length()) return(false);
	if (a.length() < b.length()) return(true);

	for (int i = a.length() - 1; i >= 0; --i)
		if (a.num[i] > b.num[i]) return(false); else
		if (a.num[i] < b.num[i]) return(true);

	return (a[0] <= b[0]) ? true : false;
}

LongLongInt operator + (LongLongInt a, LongLongInt b)
{
	int l = a.l > b.l ? a.l : b.l, t = 0;

	LongLongInt ans;

	for (int i = 0; i < l; ++i)
	{
		ans[i] = (a[i] + b[i] + t) % 10;
		t = (a[i] + b[i] + t) / 10;
	}
	while (t)
	{
		ans[l++] = t % 10;
		t /= 10;
	}
	ans.l = l;
	return(ans);
}

LongLongInt operator - (LongLongInt a, LongLongInt b)
{
	LongLongInt ans;
	ans.minus = false;

	if ( a < b ) 
	{
		swap( a, b );
		ans.minus = true;
	}

	int l = a.l;
	memcpy(ans.num, a.num, sizeof(a.num));
	for (int i = 0; i < l; ++i)
	{
		ans[i] -= b[i];
		if (ans[i] < 0)
		{
			ans[i] += 10;
			--ans[i+1];
		}
	}
	while (ans[l] == 0) --l;
	++l;
	if ( l <= 0 ) l = 1;
	ans.l = l;
	return ans;
}

//一种神奇的慢点的乘法写法 

LongLongInt operator * (LongLongInt a, LongLongInt b)
{
	LongLongInt c;
	for (int i = 0; i < a.l; ++i )
	for (int j = 0; j < b.l; ++j )
	{
		c.num[ i+j ] += a.num[i] * b.num[j];
		c.num[ i+j+1 ] += c.num[ i+j ] / 10;
		c.num[ i+j ] %= 10;
	}
	c.l = a.l + b.l - 1;
	while (c.l > 1 && c.num[c.l] == 0) --c.l;
	++c.l;
	return c;
} 

/*
LongLongInt operator * (LongLongInt a, LongLongInt b)
{
	int t, p;
	LongLongInt ans;
	for (int i = 0; i < a.l; ++i)
	{
		t = 0; 
		for (int j = 0; j < b.l; ++j)
		{
			ans[i+j] += (a[i] * b[j] + t) % 10;
			t = (a[i] * b[j]) / 10;
		}
		p = i + b.l;
		while (t)
		{
			ans[p++] += t % 10;
			t /= 10;
		}
	}
	ans.l = a.l + b.l - 1;
	while (ans[ans.l] == 0) --ans.l;
	++ans.l;
	return(ans);
}
*/
bool RangeCmp (int *a, int *b, int l)
{
	while (l)
	{
		if (*a != *b) return *a < *b;
		--a;
		--b;
		--l;
	}
}

LongLongInt operator / (LongLongInt a, LongLongInt b)
{
	int t;
	LongLongInt ans, p;
	memcpy(p.num, a.num, sizeof(a.num));
	for (int i = 0; i + b.l <= a.l; ++i)
	{
		while (RangeCmp( &b[b.l - 1], &p[a.l - i - 1], b.l))
		{
			for (int j = 0; j < b.l; ++j)
			{
				t = a.l - b.l - i + j;
				p[t] -= b[j];
				if (p[t] < 0)
				{
					p[t] += 10;
					--p[t+1];
				}
			}
			++ans[a.l - b.l - i];
		}
	}
	ans.l = MAXL - 1;
	while (ans[ans.l] == 0) --ans.l;
	++ans.l;
	return ans;
}

int main()
{	
	LongLongInt a, b, c;
	
	cout << "O(∩_∩)O~欢迎您使用LongLongInt类加强版~~~~~" << endl;
	cout << "请输入两个高精度数字a，b，每行一个：" << endl;

	cin >> a;
	cin >> b;

	c = a + b;
	cout << "a + b = " << c << endl;

	c = a - b;
	cout << "a - b = " << c << endl;

	c = a * b;
	cout << "a * b = " << c << endl;
	
	//c = a / b;
	//cout << c << endl;

	if (a == b) cout << "a == b" << endl;
	if (a > b)  cout << "a > b" << endl;
	if (a >= b)  cout << "a >= b" << endl;
	if (a < b) cout << "a < b" << endl;
	if (a <= b) cout << "a <= b" << endl;
	

	system("pause");
	return(0);
}