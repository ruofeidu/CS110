/*
ID: starea1
PROG: nuggets
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "nuggets.in" );
ofstream fout ( "nuggets.out" );

const int maxlongint = 10000000; 
const int MAXN = 256;  
const int MAXM = MAXN * MAXN - MAXN - MAXN + 1; 
int n, i, j, ans; 
int a[MAXN];
bool f[MAXM];

void MAX(int &a, int b){
    if ( b > a ) a = b;
}

int main(){   
    fin >> n; 
    for ( i = 0; i < n; ++i ) fin >> a[i]; 
    fin >> m; 
    for ( i = 0; i < m; ++i ) fin >> b[i]; 
    
    
    memset(f, false, sizeof(f)); 
    for ( i = 0; i < n; ++i ){
        f[a[i]] = true; 
        for ( j = 0; j <= MAXM; ++j ) if (f[j])
            f[j+a[i]] = true; 
    }
    
    ans = 0; 
    for (int i = MAXM; i >= 0; --i ) if (!f[i]) {
        ans = i; 
        break; 
    }
    
    fout << ans << endl; 
    return 0;  
}
