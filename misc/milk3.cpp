/*
ID: starea1
PROG: milk3
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "milk3.in" );
ofstream fout ( "milk3.out" );

const int maxlongint = 10000000; 
const int MAXN = 20 + 1;   
int A, B, C, na, nb, nc, i; 
bool f[MAXN];
bool g[MAXN][MAXN];

void MAX(int &a, int b){
    if ( b > a ) a = b;
}

void Pour(int &a, int &b, const int &B){
    if ( a >= B - b ){
        a -= B - b; 
        b = B; 
    } else { 
        b += a;
        a = 0; 
    }
}

void RFS(int a, int b){
    if (g[a][b]) return;  
    g[a][b] = true;
    int c = C - a - b;  
    if (a!=0){
        na = a, nb = b, nc = c; 
        Pour(na, nb, B); 
        RFS(na, nb); 
        na = a, nb = b, nc = c;
        Pour(na, nc, C); 
        RFS(na, nb); 
    } else f[c] = true; 
    if (b!=0){
        na = a, nb = b, nc = c; 
        Pour(nb, na, A); 
        RFS(na, nb); 
        na = a, nb = b, nc = c;
        Pour(nb, nc, C); 
        RFS(na, nb);
    }
    if (c!=0){
        na = a, nb = b, nc = c; 
        Pour(nc, na, A); 
        RFS(na, nb); 
        na = a, nb = b, nc = c;
        Pour(nc, nb, B); 
        RFS(na, nb);
    }
}

int main(){   
    memset(g, 0, sizeof(g)); 
    fin >> A >> B >> C; 
    RFS(0,0); 
    for ( i = 0; i < C; ++i) if (f[i])
        fout << i << ' '; 
    fout << C << endl; 
    return 0;  
}
