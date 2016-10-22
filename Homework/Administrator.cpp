#include <iostream>
#include <string>
#include "Administrator.h"
using namespace std;

void Administrator::ModifyPW(string x)
{
	Password = x;
	cout << "管理员密码修改成功！" << endl;
}

