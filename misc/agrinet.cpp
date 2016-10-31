/*
ID: starea1
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "agrinet.in" );
ofstream fout ( "agrinet.out" );

const int MAXN = 100 + 10; 
const int MAXM = MAXN * MAXN + 10; 
struct Edge{
    int x, y, w; 
};
int n, m, i, j, t, ans;  
int p[MAXN], a[MAXN][MAXN]; 
Edge e[MAXM];

int getP( int v ){
    if ( v == p[v] ) return v; else {
        p[v] = getP( p[v] ); 
        return p[v]; 
    }
}

int compare( const void* a, const void* b){
    return ((Edge*)a)->w - ((Edge*)b)->w;
} 

int main(){   
    fin >> n; m = 0; t = 0;  
    for ( i = 0; i < n; ++i )
    for ( j = 0; j < n; ++j ){ 
        fin >> a[i][j];
        if ( j > i ) {
            e[m].w = a[i][j];
            e[m].y = i; 
            e[m].x = j; 
            ++m;
        }
    }
    
    qsort( e, m, sizeof(Edge), compare ); 
    //for ( i = 0; i < m; ++i ) fout << e[i].y << ' ' << e[i].x << ' ' << e[i].w << endl; 
    for ( i = 0; i < n; ++i ) p[i] = i; 
    for ( i = 0; i < m; ++i ){
        if (getP(e[i].x) == getP(e[i].y)) continue;
        p[getP(e[i].x)] = getP(e[i].y);
        ++t; 
        ans += e[i].w;
        if (t == n - 1) break;
    }
        
    fout << ans << endl; 
    return 0;  
}
