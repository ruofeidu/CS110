#include <iostream>
#include <cstring>
using namespace std;

const int maxstr = 1000;
const int maxlen = 256;
const int maxletter = 300;
int n;
char letter[maxletter], rear = 0;
char str[maxstr][maxlen], task[maxlen];
bool flag[maxstr], exist[maxletter];

void Solve();
void Init();
void Wait();
void Read();
bool Equal();
bool Find();

//Judge whether both strings are the same
bool Equal(char a[], char b[])
{
    if (strlen(a) != strlen(b)) return(false);
    for (int i = 0; i < strlen(a); ++i)
        if (a[i] != b[i]) return(false);
    return(true);
}

//Find whether a includes b
bool Find(char a[], char b[])
{
    if (strlen(a) < strlen(b)) return(false);
    int i, j;

    for (i = 0; i <= strlen(a) - strlen(b); ++i)
    {
        for (j = 0; j < strlen(b); ++j)
            if (a[i + j] != b[j]) break;
        if (j == strlen(b)) return(true);
    }
    return(false);
}
        

void Solve()
{
    int i, j; 
    
    cout << "★完全匹配：" << endl;
    for (i = 0; i < n; ++i)
        if (flag[i] && Equal(str[i], task))
        {
            cout << str[i] << endl;
            flag[i] = false;
        }    
    cout << endl;

    char sink[maxlen]; //Enumerate substrings with different lengths
    cout << "★连续子串匹配：" << endl;
    for (i = 0; i < strlen(task) - 1; ++i )
    {
        sink[0] = task[i];
        sink[1] = 0;   
        for (j = i + 1; j < strlen(task); ++j )
        {
            int len = strlen(sink);
            sink[len] = task[j];
            sink[len + 1] = 0;
            
            for (int k = 0; k < n; ++k )
                if (flag[k] && Find(str[k], sink)) 
                {
                    cout << str[k] << endl;
                    flag[k] = false;
                }
        } 
    }
    cout << endl;
   
    cout << "★字母匹配：" << endl;
    for (i = 0; i < n; ++i)
    if (flag[i])
        for (j = 0; j < strlen(str[i]); ++j)
        if (exist[str[i][j]])
        {
            cout << str[i] << endl;
            flag[i] = false;
            break;
        }
            
	cout << endl;
   
}

void Wait()
{
    system("pause");
}

void Init()
{
    memset(flag, true, sizeof(flag));
    memset(exist, false ,sizeof(exist));
}

void Read()
{
    int i;
    cout << "★请输入要查询的字符串个数：";
    cin >> n;
    for (i = 0; i < n; ++i)
        cin >> str[i];
        
    cout << "★请输入要查询的子串：";
    cin >> task;
    // To save letter existed in "task"
    for (i = 0; i < n; ++i)
        if (!exist[task[i]])
        {
            exist[task[i]] = true;
            rear++;
            letter[rear] = task[i];
        }
            
    cout << endl;
}

int main()
{
    Init();
    Read();
    Solve();
    Wait();
    return 0;
}
 
