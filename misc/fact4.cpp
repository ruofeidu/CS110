/*
ID: starea1
PROG: fact4
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "fact4.in" );
ofstream fout ( "fact4.out" );

const int maxlongint = 10000000; 
int b25, n, i, k, t, ans; 

int main(){   
    fin >> n; 
    
    int b25 = 0, ans = 1; 
    for ( i = 1; i <= n; ++i ){
        int k = i; 
        while ( !( k%2 )){
            k /= 2; 
            ++b25; 
        }
        while ( !( k%5 )){
            k /= 5;
            --b25;
        }
        ans *= k; 
        ans %= 10; 
    }
    if ( b25 )
    switch ( b25 %= 4){
        case 0: ans *= 6; break; 
        case 1: ans *= 2; break; 
        case 2: ans *= 4; break; 
        case 3: ans *= 8; break; 
    }
    ans %= 10; 
    
    fout << ans << endl; 
    return 0;  
}
