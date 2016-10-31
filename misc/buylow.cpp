/*
ID: starea1
PROG: buylow
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "buylow.in" );
ofstream fout ( "buylow.out" );

const int MAXN = 5000 + 10; 
const int MAXM = MAXN * MAXN + 10; 
int n, m, i, j, res, ans;  
long f[MAXN], g[MAXN], a[MAXN];
bool law[MAXN]; 

int main(){   
    memset(law, true, sizeof(law)); 
    fin >> n;
    for ( i = 0; i < n; ++i ) {
        fin >> a[i];
        f[i] = 1; 
        g[i] = 1; 
        for ( j = 0; j < i; ++j ) if (a[i] == a[j]){
          //  law[i] = false; 
        }
    } 
    
    for ( i = 0; i < n; ++i ) if (law[i])
    for ( j = 0; j < i; ++j ) if (law[j] && a[j] > a[i])
    if (f[j] + 1 > f[i]){
        f[i] = f[j] + 1; 
        g[i] = g[j]; 
    } else if (f[j] + 1 == f[i]){
        g[i] += g[j]; 
    }
    
    ans = 0; 
    for ( i = 0; i < n; ++i ) if (law[i] && f[i] > ans){
        ans = f[i]; 
        res = g[i]; 
    } else if (f[i] == ans) {
        res += g[i];
    }
       
    fout << ans << ' ' << res << endl; 
    return 0;  
}
