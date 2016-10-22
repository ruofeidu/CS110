#include <iostream>
#include "Book.h"
using namespace std;
const int maxbook = 10000;
Book books[maxbook];
int total, i;

void Solve()
{
    cin >> books[1];
    cin >> books[2];
    if (books[1] == books[2])
        cout << (books[1] + books[2]) << endl;
    else
        cout << "出错啦~ 这两本书ISBN不一样哦~~" << endl;
}

void Wait()
{
    system( "pause" );
}

void Welcome()
{
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;   
    cout << "┃                                                    ┃" << endl;
    cout << "┃           欢迎访问碧空图书管理系统                 ┃" << endl;
    cout << "┃                www.starea.cn                       ┃" << endl;
    cout << "┃                制作人：杜若飞                      ┃" << endl;
    cout << "┃              F0903028 5090109228                   ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl; 
    cout << "请按照提示输入两本ISBN号相同的书的ISBN编号和拷贝数量：" << endl;
}

int main()
{
    Welcome();
    Solve();
    Wait();
    return 0;
}
 
