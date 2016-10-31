/*
ID: starea1
PROG: comehome
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "comehome.in" );
ofstream fout ( "comehome.out" );

const int maxlongint = 10000000; 
const int MAXN = 26+10; 
const int n = 26;  
int i, j, k, ans, x, y, m, cost; 
int w[MAXN][MAXN]; 
bool g[MAXN];
char ca, cb; 

int main(){   
    fin >> m; 
    for ( i = 0; i < n; ++i )
    for ( j = 0; j < n; ++j )
        w[i][j] = maxlongint; 
    
    for ( i = 0; i < m; ++i ){
        fin >> ca >> cb >> cost;
        if ('A' <= ca && ca <= 'Z') {
            x = ca - 'A'; 
            g[x] = true; 
        } else {
            x = ca - 'a'; 
            g[x] = false;
        }
        if ('A' <= cb && cb <= 'Z') {
            y = cb - 'A'; 
            g[y] = true;
        } else {
            y = cb - 'a'; 
            g[y] = false; 
        }
        w[x][y] = min(w[x][y], cost); 
        w[y][x] = w[x][y]; 
    }
    
    for ( k = 0; k < n; ++k )
    for ( i = 0; i < n; ++i )
    for ( j = 0; j < n; ++j ) 
        w[i][j] = min( w[i][j], w[i][k] + w[k][j]); 
        
    ans = maxlongint; 
    for ( i = 0; i < n-1; ++i ) if (g[i] && w[i][n-1] < ans ){
        ans = w[i][n-1]; 
        ca = i + 'A'; 
    }
        
    fout << ca << ' ' << ans << endl; 
    return 0;  
}
