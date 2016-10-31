/*
ID: starea1
PROG: milk
LANG: C++
*/
#include <fstream>
using namespace std;

ifstream fin ( "milk.in" );
ofstream fout ( "milk.out" );

const int maxlongint = 1000000000; 
const int MAXM = 5000 + 10; 
int n, m, i, ans; 
int p[MAXM], a[MAXM]; 
bool vd[MAXM]; 

int main(){
    memset( vd, false, sizeof(vd) ); 
    
    fin >> n >> m; 
    for ( i = 0; i < m; ++i ) fin >> p[i] >> a[i];     
    
    ans = 0; 
    while ( n > 0 ) {
        int low = maxlongint, num = -1; 
        for ( int i = 0; i < m; ++i ){
            if ( vd[i] ) continue; 
            if ( p[i] < low ) {
                low = p[i];
                num = i; 
            }
        }
        
        vd[num] = true; 
        if ( a[num] < n ){
            n -= a[num];
            ans += a[num] * p[num];
        } else {
            ans += n * p[num]; 
            n = 0; 
        }
    }
    
    fout << ans << endl; 
    return 0;  
}
