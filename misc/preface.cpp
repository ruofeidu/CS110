/*
ID: starea1
PROG: preface
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "preface.in" );
ofstream fout ( "preface.out" );

const int maxlongint = 10000000; 
const int MAXM = 8;  
const char dict[MAXM] = {'I','V','X','L','C','D','M'}; 
int n, m, i, j, t, res, ans; 
int f[MAXM];

void update(int t, int a, int b, int c){
    switch (t){
        case 9: ++f[a]; ++f[c];           break; 
        case 8: ++f[a]; ++f[c]; ++f[c];   break; 
        case 7: ++f[b]; ++f[c]; ++f[c];   break; 
        case 6: ++f[b]; ++f[c];           break; 
        case 5: ++f[b];                   break; 
        case 4: ++f[b]; ++f[c];           break;
        case 3: ++f[c]; ++f[c]; ++f[c];   break; 
        case 2: ++f[c]; ++f[c];           break; 
        case 1: ++f[c];                   break; 
    }
}

void Trans(int x){
    f[6] += x / 1000; 
    x %= 1000; 
    t = x / 100; 
    update(t,6,5,4);
    x %= 100; 
    t = x / 10; 
    update(t,4,3,2);
    x %= 10;
    t = x;
    update(t,2,1,0);
}

int main(){   
    memset(f, 0, sizeof(f)); 
    fin >> n; 
    
    for ( i = 1; i <= n; ++i ) Trans(i); 
    
    for ( i = 0; i < 8; ++i ) if ( f[i] > 0 )
        fout << dict[i] << ' ' << f[i] << endl; 
        
    return 0;  
}
