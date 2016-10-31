/*
ID: starea1
PROG: money
LANG: C++
*/
#include <fstream>
using namespace std;

ifstream fin ( "money.in" );
ofstream fout ( "money.out" );

const int maxlongint = 1000000000; 
const int MAXN = 10000 + 10; 
const int MAXM = 25 + 10;
int n, m, i, j; 
int a[MAXM];
long long f[MAXN][MAXM];

int main(){   
    memset( f, 0, sizeof(f) ); 
    fin >> m >> n; 
    for ( i = 1; i <= m; ++i ) fin >> a[i];     
    for ( i = 0; i <= m; ++i ) f[i][0] = 1;
    
    for ( i = 1; i <= m; ++i )
    for ( j = a[i]; j <= n; ++j ) {
        f[i][j] = f[i-1][j] +  max(f[i-1][j-a[i]] , f[i][j-a[i]]);
    }
    
    fout << f[m][n] << endl; 
    return 0;  
}
