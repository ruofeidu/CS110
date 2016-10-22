#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
	Time a, b;
	int x;

	cout << "O(∩_∩)O~欢迎您使用Time.h类~~~~~" << endl;
	cout << "请按提示输入两个时间变量a和b，程序将为您演示：" << endl;
	cin >> a;
	cin >> b;
	cout << " a 和 b 相差秒数为：" << a - b << endl;

	cout << " a == b 是 " << ((a == b) ? "true" : "false") << endl;

	cout << "接下来我们将通过++、--操作把给a增加2秒，给b减少2秒：" << endl;
	
	a++;
	++a;
	cout << "a为：" << a << endl;

	b--;
	--b;
	cout << "b为：" << b << endl;

	cout << " a < b 是 " << ((a < b) ? "true" : "false") << endl;
	cout << " a <= b 是 " << ((a <= b) ? "true" : "false") << endl;
	cout << " a > b 是 " << ((a > b) ? "true" : "false") << endl;
	cout << " a >= b 是 " << ((a > b) ? "true" : "false") << endl;

	cout << "请输入增量x，我们将把给a增加x秒，给b减少x秒：" << endl;
	cin >> x;

	a += x;
	cout << "a为：" << a << endl;
	b -= x;
	cout << "b为：" <<b << endl;

	system("pause");
	return 0;
}


	
	

