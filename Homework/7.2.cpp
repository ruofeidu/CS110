//P153 2
//仅在命令行下使用，输入*记得改成 "*"
#include <iostream>
#include <string>
using namespace std;

const int errorcode = -555555;

void error(string);
int val(string);

//Send error messages
void error( string msg )
{
	cout << msg << endl;
	exit(0);
}

//Convert a string to an integer
int val( string s )
{
    int i, x = 0;
    bool flag = false;
    
    if (s[0] == '-')
        flag = true;
    else if (s[0] >= '0' && s[0] <= '9')
        x = ( s[0] - '0' );
    else
        error("您输入的运算数不是整数哦~~");
    
    for ( i = 1; i < s.length(); ++i )
        if (s[i] >= '0' && s[i] <= '9')
            x = x * 10 + ( s[i] - '0' );
        else
            error("您输入的运算数不是整数哦~~");
            
    if (flag) x = -x;
    return (x);
}

//Read from the command, an int, an operator and an int;
int main( int argc, char *argv[] )
{
	if ( argc != 4 ) error("您输入的命令有误，请按如下格式（整数 运算符 整数）输入： 1 + 1 \n 如果您在Windows下输入 * 请务必把 * 写成 \"*\"");
	int a = val(string(argv[1]));
	int b = val(string(argv[3]));
	string c = string(argv[2]);

	if ( c == "+" ) cout << ( a + b ) << endl; else
	if ( c == "-" ) cout << ( a - b ) << endl; else
	if ( c == "*" ) cout << ( a * b ) << endl; else
	if ( c == "%" ) cout << ( a % b ) << endl; else
	if ( c == "/" ) cout << ( a / b ) << endl; else
		error("您输入的运算符有误，请输入 +、-、*、/、% 其中一个~");
	
	system("pause");
	return(0);
}

		

