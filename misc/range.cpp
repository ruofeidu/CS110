/*
ID: starea1
PROG: range
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "range.in" );
ofstream fout ( "range.out" );

const int maxlongint = 10000000; 
const int MAXN = 250+10;  
int n, i, j; 
int f[MAXN][MAXN], up[MAXN][MAXN], le[MAXN][MAXN], ans[MAXN];
bool g[MAXN][MAXN];  
string s; 


void MAX(int &a, int b){
    if ( b > a ) a = b;
}

int main(){   
    memset(g, false, sizeof(g));
    memset(f, 0, sizeof(f)); 
    memset(up, 0, sizeof(up)); 
    memset(le, 0, sizeof(le)); 
    
    fin >> n; 
    for ( i = 1; i <= n; ++i ){
        fin >> s; 
        for ( j = 1; j <= n; ++j ) if (s[j-1] == '1') {
            g[i][j] = true; 
            f[i][j] = 1; 
        }
    }

    for ( i = 1; i <= n; ++i ) 
    for ( j = 1; j <= n; ++j ) if (g[i][j]) {
        up[i][j] += up[i-1][j] + 1;
        le[i][j] += le[i][j-1] + 1;
    }
    
    for ( i = 1; i <= n; ++i )
    for ( j = 1; j <= n; ++j ) 
        f[i][j] = min( min(le[i][j], up[i][j]), f[i-1][j-1] + 1 );
        
    for ( i = 1; i <= n; ++i )
    for ( j = 1; j <= n; ++j ) if (f[i][j]>1) ++ans[f[i][j]];
    for ( i = n-1; i >= 1; --i ) ans[i] += ans[i+1];  
    
    for ( i = 2; i <=n; ++i ) if (ans[i] > 0)
        fout << i << ' ' << ans[i] << endl;
        
    return 0;  
}
