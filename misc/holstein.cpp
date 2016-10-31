/*
ID: starea1
PROG: holstein
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "holstein.in" );
ofstream fout ( "holstein.out" );

const int maxlongint = 10000000; 
const int MAXN = 25 + 1;  
const int MAXM = 15 + 1; 
int n, m, i, j, res, ans; 
int a[MAXN];
int f[MAXM], w[MAXM][MAXN]; 
bool vd[MAXM], sav[MAXM]; 

void Check(){
    for ( int i = 0; i < n; ++i ) if ( f[i] > 0 ) return;
    if (res < ans) {
        ans = res; 
        for ( int i = 0; i < n; ++i ) sav[i] = vd[i];
    }
} 

void RFS(int h){
    if (h == n) { Check(); return; } 
    for (int i = 0; i < n; ++i ) f[i] -= w[h][i];
    vd[h] = true;
    ++res; 
    RFS(h+1);
    --res;  
    vd[h] = false; 
    for (int i = 0; i < n; ++i ) f[i] += w[h][i]; 
    RFS(h+1); 
}

int main(){   
    ans = maxlongint; 
    memset(vd, false, sizeof(vd)); 
    fin >> n; 
    for ( i = 0; i < n; ++i ) fin >> f[i]; 
    fin >> m;
    for ( i = 0; i < m; ++i )
    for ( j = 0; j < n; ++j )
        fin >> w[i][j]; 
    
    RFS(0);
    
    fout << ans << endl; 
    bool first = true; 
    for ( int i = 0; i < n; ++i ) if ( sav[i] ) 
    if (first) {
        fout << i + 1; 
        first = false; 
    } else { 
        fout << ' ' << i + 1; 
    } 
    fout << endl; 
    return 0;  
}
