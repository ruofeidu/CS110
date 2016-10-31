/*
ID: starea1
PROG: starry
LANG: C++
*/
#include <fstream>
#include <string>
using namespace std;

ifstream fin ( "starry.in" );
ofstream fout ( "starry.out" );

const int maxlongint = 10000000; 
const int MAXL = 100000; 
const int MAXN = 100 + 2; 
const int MAXM = 160 + 2;  
const int MAXC = 26 + 2; 
const int d[8][2]    = {  {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} }; 
const int D[8][8][2] = {{ {-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} }, 
                          {-1,0},{-1,1},{0,1},{1,1},{0,1},{1,-1},{0,-1},{-1,-1} },
                          {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} },
                          {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} },
                          {1,0},{1,1},{0,1},{-1,1},{-1,0},{1,-1},{0,-1},{-1,-1} },
                          {1,0},{-1,-1},{0,-1},{1,-1},{0,-1},{1,1},{0,1},{-1,1} },
                          {0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1} },
                          {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} }}; 
struct star{
    int x, y;
};

int n, m, i, j, res, ans; 
int a[MAXN];
int f[MAXM], w[MAXM][MAXN]; 
star q[MAXL]; 
star c[MAXC][MAXM];
int cw[MAXM], ch[MAXM], cn[MAXM];  
bool vd[MAXM], sav[MAXM]; 
char mark[MAXN][MAXN];

void MIN(int &a, int b){ if (b<a) a=b; }
void MAX(int &a, int b){ if (b>a) a=b; }

bool operator < ( star &a, star &b ){
    if ( a.x < b.x ) return true; 
    if ( a.x == b.x && a.y < b.y ) return true; 
    return false; 
}

bool Same(star a[], star b[]){
    for (int v = 0; v < 8; ++v){
        int f = r = 1;         
    
    
    
    }
}

void QS(int l, int r, star a[]){
    int i=l, j=r; star x=a[(l+r)>>1];
    do{
        while (a[i]<x) ++i;
        while (x<a[j]) --j;
        if (i<=j) swap(a[i++],a[j--]);
    } while (i<j);
    if (l<j) quicksort(l,j,a);
    if (i<r) quicksort(i,r,a);
}

void RFS( int y, int x ){
    ++id;
    cn[id] = 1;  
    c[id][0].y = y; c[id][1].x = x; 
    memset(q, 0, sizeof(q)); 
    int f = r = 1; q[f].y = y; q[f].x = x; 
    int Left = Up = maxlongint; 
    int Right = Down = 0;  
    while ( f <= r ) {
        i = q[f].y;
        j = q[f].x;
        for (v = 0; v < 8; ++v){
            y = i + d[v][0]; 
            x = j + d[v][1];
            if (g[y,x] && !vd[y][x]){
                ++r; 
                q[r].y = y; 
                q[r].x = x; 
                vd[y][x] = true; 
                MIN(Left, x);   MIN(Up,y);
                MAX(Right, x);  MAX(Down,y);
                ++cn[id]; 
            }
        }
        ++f; 
    }
    QS(0,cn[id],c[id]); 
    for ( int k = 0; k < id; ++k ) if (cn[id] == cn[k] && Same(c[id],c[k])){
        for ( int i = 0; i < cn[id]; ++i )
            mark[ c[id][i].y, c[id][i].x ] = 'a' + k - 1; 
        --id; 
        return;     
    } 
    
    for ( int i = 0; i < cn[id]; ++i )
        mark[ c[id][i].y, c[id][i].x ] = 'a' + id - 1; 
}

int main(){   
    memset(g, false, sizeof(g)); 
    memset(vd, false, sizeof(vd)); 
    
    fin >> m >> n; 
    for ( i = 1; i <= n; ++i ){
        cin >> s; 
        for ( j = 1; j <= m; ++j )
        switch (s[j-1]){
            case '1': g[i][j] = true; break; 
            case '0': g[i][j] = false; mark[i][j] = '0'; break; 
        }
    }
    
    for ( i = 1; i <= n; ++i )    
    for ( j = 1; j <= m; ++j ) if (!vd[i][j])
        RFS(i,j); 
    
    return 0;  
}
