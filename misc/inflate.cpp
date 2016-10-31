/*
ID: starea1
PROG: inflate
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "inflate.in" );
ofstream fout ( "inflate.out" );

const int maxlongint = 10000000; 
const int MAXN = 10000 + 10; 
const int MAXM = 10000 + 10;  
int m, n, i, j, ans, p, t; 
int f[MAXN];

void MAX(int &a, int b){
    if ( b > a ) a = b;
}

int main(){   
    fin >> m >> n; 
    for ( i = 0; i < n; ++i ){
        fin >> p >> t; 
        for ( j = 0; j + t <= m; ++j )
            MAX( f[j+t], f[j]+p ); 
    }
    
    ans = 0; 
    for ( i = 0; i <= m; ++i) MAX(ans, f[i]); 
    fout << ans << endl; 
    return 0;  
}
