/*
ID: starea1
PROG: barn1
LANG: C++
*/
#include <fstream>
using namespace std;

ifstream fin ( "barn1.in" );
ofstream fout ( "barn1.out" );

const int maxlongint = 1000000000; 
const int MAXN = 200 + 10; 
int n, m, s, c, i, j, ans;
int a[MAXN];  
bool b[MAXN], vd[MAXN]; 

int main(){
    memset( b, false, sizeof(b) ); 
    memset( vd, false, sizeof(vd) ); 
    memset( a, 0, sizeof(a) ); 
    
    fin >> m >> s >> c; 
    for ( i = 0; i < c; ++i ) fin >> b[i];     
    for ( i = 0; i < c; ++i ) {
        int num; 
        fin >> num;
        b[num - 1] = true; 
    }
    b[s] = true; 
    
    for ( int now = 0, pre = -1, i = 0; i <= s; ++i ){
        if ( b[i] ) {
            a[now] = i - pre - 1; 
            pre = i; 
            ++now; 
        }
    }
    
    ans = s - a[0];
    if ( c != 0 ) ans -= a[c];
    
    a[0] = a[c] = 0; 
    for ( i = 1; i < m; ++i ){
        int big = 0, num = -1; 
        for ( j = 0; j <= c; ++j ){
            if (vd[j]) continue; 
            if (a[j] > big){
                big = a[j]; 
                num = j; 
            }
        }
        if (num == -1) break; 
        vd[num] = true;
        ans -= a[num]; 
    }
    
    fout << ans << endl; 
    return 0;  
}
