#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int i;

	for ( i = 'A'; i <= 'Z'; ++i )
		cout << char(i) << "对应的Ascii如下：十进制：" << dec << i << " 八进制：" << oct << i << " 十六进制：" << hex << i << endl;
	for ( i = 'a'; i <= 'z'; ++i )
		cout << char(i) << "对应的Ascii如下：十进制：" << dec << i << " 八进制：" << oct << i << " 十六进制：" << hex << i << endl;
	

	system("pause");
	return 0;
}