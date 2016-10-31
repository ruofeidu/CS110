/*
ID: starea1
PROG: fracdec
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "fracdec.in" );
ofstream fout ( "fracdec.out" );

const int maxlongint = 10000000; 
const int MAXN = 26+10; 
const int n = 26;  
int i, j, k, ans, x, y, m, cost; 
int w[MAXN][MAXN]; 
bool g[MAXN];
char ca, cb; 

void debug(){
    fout << a << ' ' << b << ' ' << cyc << endl; 
} 

int main(){   
    memset( g, -1, sizeof(g) );  fout << g[0] << endl; 
    fin >> n >> d; 
    a = n % d;
    b = d; 
    cyc = true; 
    debug(); 
    for ( n = 0; ; ) {
        if ( a == 0 ) {
            cyc = false; 
            break;
        }
        f[n] = a / b; 
        a = a % b; 
        if ( g[a] != -1 ){
            begin = g[a]; 
            break; 
        }
        g[a] = n++; 
        a *= 10; 
        debug(); 
    }
        
    fout << ca << ' ' << ans << endl; 
    return 0;  
}
